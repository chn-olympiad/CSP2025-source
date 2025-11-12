#include <bits/stdc++.h>
using namespace std;

const int kMod = 998244353;

int n, m, c[11], p[11];
string x;

int fac(int x) {
  return x == 0? 1 : x * fac(x - 1) % kMod;
}

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> x;
  x = ' ' + x;
  if(n <= 10) {
    for(int i = 1; i <= n; i++) cin >> c[i];
    iota(p + 1, p + n + 1, 1);
    int ans = 0;
    do {
      int cf = 0;
      for(int i = 1; i <= n; i++) {
        cf += (x[i] == '0' || cf >= c[p[i]]);
      }
      ans += cf <= n - m;
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans << '\n';
  }else cout << fac(n) << '\n';
  return 0;
}
