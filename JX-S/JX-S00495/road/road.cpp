#include <bits/stdc++.h>
using namespace std;
#define int long long
template<class T> inline bool cmax(T& x, T y) { if (x < y) return x = y, true; return false; }
template<class T> inline bool cmin(T& x, T y) { if (x > y) return x = y, true; return false; }
constexpr int N = 1e4 + 49, M = 1e6 + 9;
int n, m, k, cst[12], a[12][N], fa[N];
struct edge {
  int x, y, z;
  bool operator<(const edge &r) const {
    return z < r.z;
  }
} e[M], es[1 << 10][N];
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
signed main() {
#ifndef LOCAL
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
#endif
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) cin >> e[i].x >> e[i].y >> e[i].z;
  sort(e + 1, e + m + 1);
  int cnt = 0, ans = 0;
  iota(fa + 1, fa + n + k + 1, 1);
  for (int j = 1; j <= m; ++j) {
    auto [x, y, z] = e[j];
    if ((x = get(x)) == (y = get(y))) continue;
    fa[y] = x, ans += z;
    es[0][++cnt] = e[j];
  }
  for (int i = 0; i < k; ++i) {
    cin >> cst[i];
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  }
  for (int i = 1; i < 1 << k; ++i) {
    iota(fa + 1, fa + n + k + 1, 1);
    int cnt = 0, pc = __builtin_popcount(i);
    int tmp = 0, c = n + pc - 2, id = 0;
    for (int j = 0; j < k; ++j) {
      if (i >> j & 1 ^ 1) continue;
      tmp += cst[j];
      id = j;
    }
    for (int j = 1; j <= c; ++j) e[j] = es[i ^ 1 << id][j];
    for (int j = 1; j <= n; ++j) e[++c] = {n + id + 1, j, a[id][j]};
    sort(e + 1, e + c + 1);
    for (int j = 1; j <= c; ++j) {
      auto [x, y, z] = e[j];
      if ((x = get(x)) == (y = get(y))) continue;
      fa[y] = x;
      tmp += z;
      es[i][++cnt] = e[j];
    }
    cmin(ans, tmp);
  }
  cout << ans;
}