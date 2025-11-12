#include <bits/stdc++.h>

using ll = long long;

constexpr ll mod = 998244353;
constexpr int N = 510;

inline void add(ll &x, const ll y) {
  (x += y) %= mod;
}

int n, m;
ll fac[N], C[N][N];

char str[N];
int c[N], prec[N], pre0[N];

ll f[N][N], g[N][N];

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);

  scanf("%d%d", &n, &m);
  for (int i = fac[0] = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = C[i][0] = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }

  scanf("%s", str + 1);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x), c[x]++;
  }
  for (int i = 0; i <= n; i++) {
    prec[i] = c[i] + (i == 0 ? 0 : prec[i - 1]);
  }
  for (int i = 1; i <= n; i++) {
    pre0[i] = (str[i] == '0') + pre0[i - 1];
  }
  f[0][0] = 1;
  for (int i = 0; i < n; i++) {
    memcpy(g, f, sizeof(g));
    memset(f, 0, sizeof(f));
    if (str[i + 1] == '1') {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k + j <= i; k++) {
          add(f[j][k + 1], g[j][k]);
          for (int s = 0; s <= c[j + 1] && s <= k; s++) {
            add(f[j + 1][k - s], g[j][k] * (prec[j] - (i - pre0[i] - k)) % mod * C[c[j + 1]][s] % mod * C[k][s] % mod * fac[s]);
          }
        }
      }
    } else {
      for (int j = 0; j <= i; j++) {
        for (int k = 0; k + j <= i; k++) {
          for (int s = 0; s <= c[j + 1] && s <= k; s++) {
            add(f[j + 1][k - s], g[j][k] % mod * C[c[j + 1]][s] % mod * C[k][s] % mod * fac[s]);
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int j = 0; j <= n - m; j++) {
    for (int i = 0; i <= pre0[n] && i <= n - prec[j]; i++) {
      add(ans, f[j][n - prec[j] - i] * C[n - prec[j]][i] % mod * fac[n - prec[j] - i] % mod);
    }
  }
  printf("%lld\n", ans * fac[pre0[n]] % mod);

  return 0;
}