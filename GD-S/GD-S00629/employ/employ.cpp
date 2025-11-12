#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n, m, ans, cnt, c[510], s[510], f[1 << 18][20];
char str[510];
signed main() {
  freopen ("employ.in", "r", stdin);
  freopen ("employ.out", "w", stdout);
  scanf ("%lld%lld%s", &n, &m, str + 1);
  for (int i = 1; i <= n; i++)
    s[i] = str[i] - '0';
  for (int i = 1; i <= n; i++) {
    scanf ("%lld", &c[i]);
    cnt += c[i] == 0;
  }
  if (m > n - cnt) {
    printf ("0\n");
    return 0;
  }
  f[0][0] = 1;
  for (int mask = 0; mask < (1 << n); mask++) {
    int date = __builtin_popcount (mask) + 1;
    for (int i = 0; i < n; i++)
      for (int j = 1; j <= n; j++)
        if (! (mask & (1 << j - 1))) {
          int flag = i >= c[j] || !s[date];
          (f[mask | (1 << j - 1)][i + flag] += f[mask][i]) %= mod;
        }
  }
  for (int i = m; i <= n; i++)
    (ans += f[ (1 << n) - 1][n - i]) %= mod;
  printf ("%lld\n", ans);
  return 0;
}


