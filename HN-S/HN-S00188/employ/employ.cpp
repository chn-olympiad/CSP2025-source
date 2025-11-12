// BLuemoon_
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 505, kMaxM = 20, kL = (1 << 18) + 5;
const LL kP = 998244353;

LL T = 1, n, m, a[kMaxN], ans, dp[kL][kMaxM], c[kMaxN], F = 1;
string str;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
  for (; T; T--, ans = 0) {
    cin >> n >> m >> str, str = ' ' + str;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
      F &= (str[i] == '1');
    }
    if (F) {
      ans = 1;
      for (int i = 1; i <= n; i++) {
        (ans *= i) %= kP;
      }
      return cout << ans << '\n', 0;
    }
    dp[0][0] = 1;
    for (int s = 0; s < 1 << n; s++) {
      int tot = __builtin_popcount(s);
      for (int i = 0; i <= tot; i++){
        for (int j = 1; j <= n; j++) {
          if ((s >> j - 1 & 1) ^ 1) {
            if (tot - i >= c[j]) {
              (dp[s ^ (1 << j - 1)][i] += dp[s][i]) %= kP;
            } else {
              if (str[tot + 1] == '0') {
                (dp[s ^ (1 << j - 1)][i] += dp[s][i]) %= kP;
              } else {
                (dp[s ^ (1 << j - 1)][i + 1] += dp[s][i]) %= kP;
              }
            }
          }
        }
      }
    }
    for (int i = m; i <= n; i++) {
      (ans += dp[(1 << n) - 1][i]) %= kP;
    }
    cout << ans << '\n';
  }
  return 0;
}
// ulimit -s 102400 && g++ employ.cpp -o employ -O2 -std=c++14 -Wall && ./employ