#include <bits/stdc++.h>

#define int int64_t

using namespace std;

constexpr int N = 5e3 + 10, P = 998244353;
int pw2[N], a[N], f[N][N];

signed main() {
  freopen("polygon.in", "r", stdin);
  freopen("polygon.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  pw2[0] = 1;
  for (int i = 1; i < N; i++) pw2[i] = pw2[i - 1] * 2 % P;

  sort(a + 1, a + n + 1);

  if (accumulate(a + 1, a + n + 1, 0) == n) {
    cout << ((pw2[n] - 1 - n - n * (n - 1) / 2) % P + P) % P;
    return 0;
  }

  int res = 0;
  for (int i = 3; i <= n; i++) {
    f[0][0] = 1;
    for (int j = 1; j < i; j++) {
      for (int k = a[i] - a[j] + 1; k <= a[i]; k++)
        (res += f[j - 1][k] * pw2[i - j - 1]) %= P;

      for (int k = 0; k <= a[i]; k++)
        f[j][k] = (f[j - 1][k] + (k >= a[j] ? f[j - 1][k - a[j]] : 0)) % P;
    }
  }

  cout << res;
}
