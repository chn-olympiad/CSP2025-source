#include <bits/stdc++.h>
using namespace std;
#define FULL(v) begin(v), end(v)
#define ALL(v, l, r) begin(v) + l, begin(v) + r + 1
using tp = int;
using ll = long long int;
constexpr ll INF = 1e18;

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
   for (; y; x = 1ll * x * x % mod, y >>= 1ll)
      if (y & 1ll) z = 1ll * z * x % mod;
   return z;
}

void QWQ() {
   freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   return ;
}

constexpr tp N = 1e4 + 25;
#define ed tuple<tp, tp, tp>
tp n, m, k;
array<tp, 12> c;
array<array<tp, N>, 12> a;
vector<ed> e, ee;

array<tp, N> fa;
tp get(tp x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
bool mer(tp x, tp y) {
   x = get(x), y = get(y);
   if (x == y) return 0;
   return fa[x] = y, 1;
}

tp mst(tp siz) {
   tp cnt = 0;
   ll sum = 0;
   for (tp i = 1; i <= n + k; ++i) fa[i] = i;
   for (auto x : ee) {
      tp w = get<0>(x), u = get<1>(x), v = get<2>(x);
      if (cnt == siz - 1) break;
      if (mer(u, v)) cnt++, sum += w;
   }
   return sum;
}

//vector<ed> E;
// void mmst() {
//    for (tp i = 1; i <= n; ++i) fa[i] = i;
//    for (auto [w, u, v] : e) {
//       if (mer(u, v)) E.emplace_back(w, u, v);
//    }
//    return ;
// }

ll work(tp s) {
   ee = e;
   ll sum = 0;
   for (tp i = 0; i < k; ++i) {
      if ((s & (1 << i)) == 0) continue;
      sum += c[i + 1];
      for (tp j = 1; j <= n; ++j) ee.emplace_back(a[i + 1][j], i + n + 1, j);
   }
   sort(FULL(ee));
   return sum + mst(__builtin_popcount(s) + n);
}

tp HARUTO() {
   cin >> n >> m >> k;
   for (tp i = 1, u, v, w; i <= m; ++i)
      cin >> u >> v >> w, e.emplace_back(w, u, v);
   //mmst();
   ll qwq = 0;
   for (tp i = 1; i <= k; ++i) {
      cin >> c[i], qwq += c[i];
      for (tp j = 1; j <= n; ++j) cin >> a[i][j];
   }
   if (qwq == 0) return cout << work((1 << k) - 1) << "\n", 0;
   ll ans = INF;
   for (tp s = 0; s < 1 << k; ++s) ckmin(ans, work(s));
   cout << ans << "\n";
   return 0;
}

int main() {
   QWQ();
   tp t = 1; // cin >> t;
   while (t--) HARUTO();
   return 0;
}