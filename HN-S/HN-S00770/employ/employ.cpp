#include <bits/stdc++.h>

using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

constexpr int N = 505, MOD = 998244353;
void Add(int &x, i64 y) { x = (x + y) % MOD; }
void Add(int &x, int y) {
  if ((x += y) >= MOD) x -= MOD;
}
std::array<int, N+N> fac;
void Math() {
  for (int i = fac[0] = 1; i < N+N; ++i) fac[i] = i64(fac[i - 1]) * i % MOD;
}

int n, m, ans;
std::string s;
std::array<int, N> c, cnt;

std::array<std::array<int, N>, N> f, g;

int main() {
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Math();

  std::cin >> n >> m >> s, s = ' ' + s;
  for (int i = 1; i <= n; ++i) std::cin >> c[i], ++cnt[c[i]];
  for (int i = 0; i < n; ++i) cnt[i + 1] += cnt[i];

  for (int i = f[0][0] = 1, c = 0; i <= n; ++i) {
    if (s[i] == '0') continue;
    for (int j = 0; j <= c; ++j) {
      for (int k = 0; k <= j; ++k) {
        if (!f[j][k]) continue;
        int w = std::max(0, cnt[i - 1 - j] - c + j - k);
        Add(g[j][k], i64(f[j][k]) * w);
        Add(g[j + 1][k], f[j][k]);
        Add(g[j + 1][k + 1], i64(MOD - f[j][k]) * w);
      }
    }
    ++c;
    for (int j = 0; j <= c; ++j)
      for (int k = 0; k <= j; ++k) f[j][k] = g[j][k], g[j][k] = 0;
  }

  int z = std::count(begin(s), end(s), '0');
  for (int s = m; s <= n; ++s)
    for (int t = 0; t <= s; ++t) Add(ans, i64(f[s][t]) * fac[z + s - t]);
  std::cout << ans << '\n';

  return 0;
}