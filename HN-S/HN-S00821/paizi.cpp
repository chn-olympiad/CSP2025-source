#include <bits/stdc++.h>

using namespace std;

int main() {
  system("g++ code.cpp -o code -std=c++14 -O2");
  system("g++ std.cpp -o std -std=c++14 -O2");
  system("g++ make.cpp -o make -std=c++14 -O2");
  for (;;) {
    system("./make");
    system("./std");
    system("./code");
    if (system("diff -Z std.out code.out")) {
      system("pause");
      return 0;
    }
  }
  return 0;
}