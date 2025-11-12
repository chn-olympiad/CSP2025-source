#include <bits/stdc++.h>

using namespace std;

const int N = 1005, mod = 998244353;

int fac[N], ifac[N];
int s[N], c[N];
int dp[1 << 19][19];

int qp(int x, int y) {
  int ans = 1;
  while (y) {
    if (y & 1) {
      (ans *= 1ll * x) %= mod;
    }
    (x *= 1ll * x) %= mod;
    y >>= 1;
  }
  return ans;
}

int C(int n, int m) {
  if (n < m || m < 0) {
    return 0;
  }
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[i] = qp(fac[i], mod - 2);
  }
  int n, m, cnt1 = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    s[i] = (c == '1');
    cnt1 += s[i];
  }
  if (cnt1 < m) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (m == n && c[i] == 0) {
      cout << 0;
      return 0;
    }
  }
  dp[0][0] = 1;
  for (int pc = 0; pc < n; pc++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      if (__builtin_popcount(mask) != pc) {
        continue;
      }
      for (int j = 0; j <= pc; j++) {
        for (int i = 1; i <= n; i++) {
          if (!(mask & (1 << i - 1))) {
            (dp[mask | (1 << i - 1)][j + (c[i] <= j || !s[pc + 1])] += dp[mask][j]) %= mod;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n - m; i++) {
    (ans += dp[(1 << n) - 1][i]) %= mod;
  }
  cout << ans;
}