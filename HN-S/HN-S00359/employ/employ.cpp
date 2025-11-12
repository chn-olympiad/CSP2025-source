#include<bits/stdc++.h>
using namespace std;

const int MAXN = 505, MOD = 998244353;

int n, m, c[MAXN], dp[1 << 20][25];
string s;

int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = " " + s;
  for(int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  dp[0][0] = 1;
  for(int i = 0; i < (1 << n); ++i) {
    for(int j = 0; j <= m; ++j) {
      for(int k = 0; k < n; ++k) {
        if((i >> k) & 1) {
          continue;
        }
        int nj = min(m, j + (s[__builtin_popcount(i) + 1] == '1' && __builtin_popcount(i) - j < c[k + 1]));
        dp[i | (1 << k)][nj] = (dp[i | (1 << k)][nj] + dp[i][j]) % MOD;
      }
    }
  }
  cout << dp[(1 << n) - 1][m];
  return 0;
}
