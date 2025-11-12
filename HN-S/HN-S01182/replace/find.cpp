#include <bits/stdc++.h>

using namespace std;


int main() {
  for (int i = 1e9, cnt = 0; cnt <= 10; i++) {
    int ok = 0;
    for (int j = 2; j * j <= i; j++) {
      ok |= i % j == 0;
    }
    if (!ok) {
      cout << i << '\n';
      cnt++;
    }
  }  
}