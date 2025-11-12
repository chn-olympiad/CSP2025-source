#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e2 + 5, mod = 998244353;

int n, m, c[N], dp[1 << 18][20];

string s;

void Solve1() {
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i & (1 << (j - 1))) {
        cnt++;
      }
    }
    //cout << i << " " << cnt << "\n";
    for (int j = 0; j <= cnt; j++) {
      for (int k = 1; k <= n; k++) {
        if (!(i & (1 << (k - 1)))) {
          if (s[cnt + 1] == '0') {
            dp[i ^ (1 << (k - 1))][j + 1] += dp[i][j];
            dp[i ^ (1 << (k - 1))][j + 1] %= mod;
          }
          else {
            if (c[k] > j) {
              dp[i ^ (1 << (k - 1))][j] += dp[i][j];
              dp[i ^ (1 << (k - 1))][j] %= mod;
            }
            else {
              dp[i ^ (1 << (k - 1))][j + 1] += dp[i][j];
              dp[i ^ (1 << (k - 1))][j + 1] %= mod;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (n - i >= m) {
      ans = (ans + dp[(1 << n) - 1][i]) % mod;
    }
  }
  cout << ans % mod  << "\n";
}

signed main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  cin >> n >> m >> s;
  s = " " + s;
  string sum = " ";
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum = sum + "1";
  }
  if (n <= 18) {
    Solve1();
    return 0;
  }
  cout << "0\n";
  return 0;
}
/*
5 3
00111
1 2 3 4 5
*/
