#include <bits/stdc++.h>
using namespace std;
#define FULL(v) begin(v), end(v)
#define ALL(v, l, r) begin(v) + l, begin(v) + r + 1
using tp = int;
constexpr tp INF = 1e9;

template <typename T>
bool ckmin(T &x, T y) {
   if (y < x) return x = y, 1;
   return 0;
}
template <typename T>
bool ckmax(T &x, T y) {
   if (y > x) return x = y, 1;
   return 0;
}

constexpr tp mod = 998244353;
tp norm(tp x) { return x + (x < 0) * mod - (x >= mod) * mod; }
void add(tp &x, tp y) { x = norm(x + y); }
tp pow(tp x, tp y) {
   tp z = 1;
   for (; y; x = 1ll * x * x % mod, y >>= 1)
      if (y & 1ll) z = 1ll * z * x % mod;
   return z;
}

void QWQ() {
   freopen("employ.in", "r", stdin), freopen("employ.out", "w", stdout);
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   return ;
}

constexpr tp N = 505;
tp n, m;
array<tp, N> c, a;
array<array<tp, 1 << 18>, 19> f;

tp HARUTO() {
   cin >> n >> m;
   for (tp i = 0; i < n; ++i) {
      char x; cin >> x, a[i] = x - '0';
   }
   for (tp i = 0; i < n; ++i) cin >> c[i];
   if (m == n) {
      for (tp i = 0; i < n; ++i)
         if (a[i] == 0 || c[i] == 0) return cout << "0\n", 0;
      tp ans = 1;
      for (tp i = 1; i <= n; ++i) ans = 1ll * ans * i % mod;
      return cout << ans << "\n", 0;
   }
   f[0][0] = 1;
   for (tp s = 0; s < 1 << n; ++s) {
      tp x = __builtin_popcount(s);
      for (tp i = 0; i <= x; ++i) {
         if (f[i][s] == 0) continue;
         for (tp j = 0; j < n; ++j)
            if ((s & (1 << j)) == 0) {
               if (i >= c[j] || a[x] == 0) add(f[i + 1][s | (1 << j)], f[i][s]);
               else add(f[i][s | (1 << j)], f[i][s]);
            }
      }
   }
   tp ans = 0;
   for (tp i = 0; i <= n - m; ++i) add(ans, f[i][(1 << n) - 1]);
   cout << ans << "\n";
   return 0;
}

int main() {
   QWQ();
   tp t = 1; // cin >> t;
   while (t--) HARUTO();
   return 0;
}