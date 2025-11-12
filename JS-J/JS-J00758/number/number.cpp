// ‐O2 ‐std=c++14 ‐static
/*
g++ -Wall -O2 -std=c++14 -static number.cpp -o number && ./number
*/
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
signed main() {
  freopen("number.in", "r", stdin);
  // freopen("number4.in", "r", stdin); /////
  freopen("number.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  vector<int> a;
  for (const char& c : s) {
    if ('0' <= c && c <= '9') {
      a.push_back(c - '0');
    }
  }
  sort(a.begin(), a.end(), cmp);
  if (a.front() == 0) {
    cout << "0\n";
    return 0;
  }
  for (const int& x : a) {
    cout << x;
  }
  cout << '\n';
  return 0;
}