/*
Coder : CJSY242203 CXM
tips : 033999
Password : Ren5Jie4Di4Ling5%
Pass all simple On :
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 20, Mod = 998244353;

int add (int x, int y) { return x + y >= Mod ? x + y - Mod : x + y; }

int n, m, dp[1 << N][N], c[N];
string s;

void solve () {
  cin >> n >> m >> s;
  for (int i = 1; i <= n; cin >> c[i++]) {
  }
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n); ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      cnt += i >> j & 1;
    }
    for (int j = 0; j < n; ++j) {
      if (!(i >> j & 1)) {
        for (int k = 0; k <= cnt; ++k) {
          if (k >= c[j + 1]) {
            dp[i | (1 << j)][k + 1] = add (dp[i | (1 << j)][k + 1], dp[i][k]);
          } else if (s[cnt] == '1') {
            dp[i | (1 << j)][k] = add (dp[i | (1 << j)][k], dp[i][k]);
          } else {
            dp[i | (1 << j)][k + 1] = add (dp[i | (1 << j)][k + 1], dp[i][k]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; ++i) {
    ans = add (ans, dp[(1 << n) - 1][i]);
  }
  cout << ans;
}

int main () {
  freopen ("employ.in", "r", stdin);
  freopen ("employ.out", "w", stdout);
  ios :: sync_with_stdio (0), cin.tie (0);
  for (int Test = 1; Test--; solve ()) {
  }
  return 0;
}
/*
4 1
aa bb
a b
aaa bbb
a b
caa bbc

// freopen ()
  this is a never gonna give you up sentence.
  to day (11.1) is cxm's birthday, and I hope :
  CSP_J = 400, CSP_S = max (CSP_S, 300), rp += inf;
*/
