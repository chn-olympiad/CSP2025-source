#include <bits/stdc++.h>

template <class T>
using V = std::vector<T>;
using ll = long long;

const int mod = 998244353;

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  int n, m;
  std::cin >> n >> m;
  std::string s;
  std::cin >> s;
  V<int> buc(n + 1);
  for (int i = 1, c; i <= n; i++) std::cin >> c, buc[c]++;
  for (int i = 1; i <= n; i++) buc[i] += buc[i - 1];
  V<V<int>> dp(n + 1, V<int>(n + 1));
  dp[0][0] = 1;
  int bc = 0;
  for (char c : s) {
    auto tmp = dp;
    dp.assign(n + 1, V<int>(n + 1));
    for (int i = 0; i <= bc; i++)
      for (int j = 0; j <= bc; j++)
        if (tmp[i][j]) {
          if (c == '1') {
            for (int w : {0, 1}) {
              if (w == 0) {
                (dp[i + 1][j + 1] += (ll)tmp[i][j] * (buc[i] - j) % mod) %= mod;
              } else {
                (dp[i][j + 1] += (ll)tmp[i][j] * (buc[i] - j) * -1 % mod) %= mod;
                (dp[i][j] += tmp[i][j]) %= mod;
              }
            }
          } else {
            (dp[i + 1][j] += tmp[i][j] % mod) %= mod;
          }
        }
    bc++;
  }
  int ans = 0;
  for (int i = 0; n - i >= m; i++) {
    for (int j = 0; j <= n; j++) 
      if (dp[i][j]) {
        ll t = dp[i][j];
        for (int k = j; k < n; k++)
          (t *= n - k) %= mod;
        (ans += t) %= mod;
      }
  }
  std::cout << (ans + mod) % mod << '\n';
}