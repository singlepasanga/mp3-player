
// Include Libraries
#include "Arduino.h"
#include "SpeakerStereo3W.h"


// Pin Definitions
#define DFPLAYER_PIN_TX	10
#define DFPLAYER_PIN_RX	11
#define STEREOSPEAKER_PIN_POS	2
#define TMP36_PIN_VOUT	A3



// Global variables and defines
unsigned int StereoSpeakerHoorayLength          = 6;                                                      // amount of notes in melody
unsigned int StereoSpeakerHoorayMelody[]        = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5}; // list of notes. List length must match HoorayLength!
unsigned int StereoSpeakerHoorayNoteDurations[] = {8      , 8      , 8      , 4      , 8      , 4      }; // note durations; 4 = quarter note, 8 = eighth note, etc. List length must match HoorayLength!
// object initialization
SpeakerStereo3W StereoSpeaker(STEREOSPEAKER_PIN_POS);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1')
    {
    // Disclaimer: The DFPlayer - Mini MP3 Player is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '2') {
    // 3W Stereo Speaker - Test Code
    // The Speaker will play the Hooray tune
    StereoSpeaker.playMelody(StereoSpeakerHoorayLength, StereoSpeakerHoorayMelody, StereoSpeakerHoorayNoteDurations); 
    delay(500);   
    }
    else if(menuOption == '3')
    {
    // Disclaimer: The This Analog Temprature Sensor can measure -40 to 150C. It is very percise and doesn't need calibration is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) DFPlayer - Mini MP3 Player"));
    Serial.println(F("(2) 3W Stereo Speaker"));
    Serial.println(F("(3) This Analog Temprature Sensor can measure -40 to 150C. It is very percise and doesn't need calibration"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing DFPlayer - Mini MP3 Player - note that this component doesn't have a test code"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing 3W Stereo Speaker"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing This Analog Temprature Sensor can measure -40 to 150C. It is very percise and doesn't need calibration - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
