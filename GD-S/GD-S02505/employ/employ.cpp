#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define debug(...) void(0)
#define endl "\n"
#endif
using LL = long long;
template <unsigned umod>
struct modint {
  static constexpr int mod = umod;
  unsigned v;
  modint() = default;
  template <class T, enable_if_t<is_integral<T>::value>* = nullptr>
    modint(const T& _y) : v((unsigned)(_y % mod + (is_signed<T>() && _y < 0 ? mod : 0))) {}
  modint& operator+=(const modint& rhs) { v += rhs.v; if (v >= umod) v -= umod; return *this; }
  modint& operator-=(const modint& rhs) { v -= rhs.v; if (v >= umod) v += umod; return *this; }
  modint& operator*=(const modint& rhs) { v = (unsigned)(1ull * v * rhs.v % umod); return *this; }
  friend modint operator+(modint lhs, const modint& rhs) { return lhs += rhs; }
  friend modint operator-(modint lhs, const modint& rhs) { return lhs -= rhs; }
  friend modint operator*(modint lhs, const modint& rhs) { return lhs *= rhs; }
  friend int raw(const modint& self) { return self.v; }
  friend ostream& operator<<(ostream& os, const modint& self) { return os << raw(self); }
  explicit operator bool() const { return v != 0; }
};
using mint = modint<998244353>;
constexpr int N = 510;
int n, m, buc[N];
char s[N];
mint buf[2][N][N];
auto f = buf[0], g = buf[1];
int main() {
#ifndef LOCAL
#ifndef NF
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1, x; i <= n; i++) cin >> x, buc[x] += 1;
  for (int i = n; i >= 1; i--) buc[i - 1] += buc[i];
  memset(f, 0, sizeof buf[0]);
  for (int i = 0; i <= n - m; i++) f[i][0] = 1;
  for (int t = n; t >= 1; t--) {
    memset(g, 0, sizeof buf[0]);
    for (int p = 0; p <= n; p++) {
      for (int q = 0; q <= n; q++) if (f[p][q]) {
        // ping
        if (s[t] == '1' && buc[p + 1] >= q) g[p][q + 1] += f[p][q] * (buc[p + 1] - q);
        // jiang (-1)
        if (p && buc[p] >= q && s[t] == '1') g[p - 1][q + 1] -= f[p][q] * (buc[p] - q);
        // jiang (+1)
        if (p) g[p - 1][q] += f[p][q];
      }
    }
    swap(f, g);
    for (int p = 0; p <= n; p++) {
      for (int q = 0; q <= n; q++) if (f[p][q]) {
        debug("f[%d][%d][%d] = %d\n", t - 1, p, q, raw(f[p][q]));
      }
    }
  }
  mint fac = 1, ans = f[0][n];
  for (int i = 1; i <= n; i++) {
    fac *= i;
    ans += f[0][n - i] * fac;
  }
  cout << ans << endl;
  return 0;
}

