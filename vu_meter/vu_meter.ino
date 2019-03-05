int ledsConfig[4][2] = {
  {2, 100},
  {3, 20000},
  {4, 200000},
  {5, 400000}
};
int ledsCount = sizeof(ledsConfig) / sizeof(int);

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < ledsCount - 1; i++) {
    pinMode(ledsConfig[i][0], OUTPUT);
  }
}

void loop() {
 while (Serial.available()) {
  long int val = Serial.parseInt();
  
  for (int i = 0; i < ledsCount - 1; i++) {
    if (val > ledsConfig[i][1])
      digitalWrite(ledsConfig[i][0], HIGH);
    else
      digitalWrite(ledsConfig[i][0], LOW);
  }
 }
}
