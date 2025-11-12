#include <bits/stdc++.h>

using namespace std;

int buc[128];

signed main() {
  freopen("number.in", "r", stdin);
  freopen("number.out", "w", stdout);
  
  cin.tie(nullptr)->sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  for (char c : s) buc[int(c)]++;
  
  for (char c = '9'; c >= '0'; c--)
    while (buc[int(c)]--) cout << c;
}
