/*
g++ -Wall -O2 -std=c++14 -static xor.cpp -o xor && ./xor
*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a, ps;
// ps?? !!!!!!!!
// omg i have solved it!!!!!!!!!!!!!!!!
signed main() {
  freopen("xor.in", "r", stdin);
  // freopen("xor5.in", "r", stdin); ///////
  freopen("xor.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  a.resize(n + 1);
  ps.resize(n + 1);
  int cnt = 0, lst = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = ps[i - 1] ^ a[i];
    for (int j = lst; j <= i; j++) {
      if ((ps[i] ^ ps[j - 1]) == k) {
        lst = i + 1;
        cnt++;
        break;
      }
    }
  }
  cout << cnt << '\n';
  // for (int i = 1; i <= n; i++) {
  //   cerr << ps[i] << '\n';
  // }
  return 0;
}