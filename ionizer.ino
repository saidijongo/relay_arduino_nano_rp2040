#define relayPin 3 

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {

  if(Serial.available() > 0){
    
    String command = Serial.readStringUntil(',');
    
    if(command == "L"){
      
      String lampState = Serial.readStringUntil(',');
      
      sendStatusMessage("LAMP", lampState);
      
      if(lampState == "1"){
        turnLampOn();
      }
      else{
        turnLampOff(); 
      }
      
      sendStatusMessage("RETLAMP", lampState);
      
    }
    
  }
  
}

void sendStatusMessage(String type, String state){
  Serial.print("ST,0,");
  Serial.print(type);
  Serial.print(","); 
  Serial.print(state);
  Serial.print(",ED\r\n");
}

void turnLampOn(){
  digitalWrite(relayPin, HIGH); 
}

void turnLampOff(){
  digitalWrite(relayPin, LOW);
}
