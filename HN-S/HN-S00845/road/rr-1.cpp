// g++ -std=c++14 -O2 -fsanitize=address,undefined -o road road.cpp && ./road
#include <bits/stdc++.h>

#define int int64_t

const int kMaxN = 1e4 + 5, kMaxM = 1e6 + 5, kMaxK = 15;

int n, m, k;
int u[kMaxM], v[kMaxM], w[kMaxM];
int c[kMaxK], a[kMaxK][kMaxN];
std::vector<std::tuple<int, int, int>> ee[1 << 10];

struct DSU {
  int fa[kMaxN + kMaxK];
  void init(int n) { std::iota(fa + 1, fa + 1 + n, 1); }
  inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  inline bool unionn(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) return fa[fx] = fy, 1;
    else return 0;
  }
} dsu, dsu1[1 << 10];

std::vector<std::tuple<int, int, int>> kruskal() {
  std::vector<std::tuple<int, int, int>> ed, vec;
  for (int i = 1; i <= m; ++i) ed.emplace_back(w[i], u[i], v[i]);
  std::sort(ed.begin(), ed.end());
  dsu.init(n + k);
  for (auto p : ed) {
    int u, v, w;
    std::tie(w, u, v) = p;
    if (dsu.unionn(u, v)) vec.emplace_back(p);
  }
  return vec;
}

void dickdreamer() {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    std::cin >> u[i] >> v[i] >> w[i];
  }
  std::vector<std::tuple<int, int, int>> ee1;
  for (int i = 1; i <= k; ++i) {
    std::cin >> c[i];
    for (int j = 1; j <= n; ++j) std::cin >> a[i][j], ee1.emplace_back(a[i][j], i + n, j);
  }
  for (int s = 0; s < (1 << k); ++s) dsu1[s].init(n + k);
  std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  std::sort(ee1.begin(), ee1.end());
  for (auto p : ee1) {
    int u, v, w;
    std::tie(w, u, v) = p;
    for (int s = 0; s < (1 << k); ++s) {
      if (s >> (u - n - 1) & 1) {
        // if (dsu1[s].unionn(u, v)) ++c[1];
        ee[s].emplace_back(p);
      }
    }
  }
  std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  auto tr = kruskal();
  int ans = 1e18;
  for (int s = 0; s < (1 << k); ++s) {
    int sum = 0;
    dsu.init(n + k);
    for (int i = 1; i <= k; ++i)
      if (s >> (i - 1) & 1)
        sum += c[i];
    int tot = 0;
    for (int i = 0, j = 0; i < tr.size() || j < ee[s].size();) {
      int u, v, w;
      if (i < tr.size() && (j == ee[s].size() || std::get<0>(tr[i]) < std::get<0>(ee[s][j]))) std::tie(w, u, v) = tr[i++];
      else std::tie(w, u, v) = ee[s][j++];
      if (dsu.unionn(u, v)) sum += w, ++tot;
      if (tot >= n + k - 1) break;
    }
    ans = std::min(ans, sum);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}