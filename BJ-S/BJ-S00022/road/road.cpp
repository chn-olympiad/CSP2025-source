#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int N = 10005, M = 1000005;
int n, m, k, c[15];
struct Eg {
  int u, v, d;
  inline bool operator<(const Eg &R) const {
    return d < R.d;
  }
} eg[M];
vector<Eg> con[15];

struct DS {
  int fa[N + 15];
  inline void init(int n) { for (int i = 1; i <= n; i++) fa[i] = i; }
  inline int root(int u) { while (fa[u] != u) u = fa[u] = fa[fa[u]]; return u; }
  inline bool mrg(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return 0;
    fa[v] = u;
    return 1;
  }
} ds;

i64 ans;
void dfs(int j, const vector<Eg> &E, i64 cost, i64 ex) {
  if (j > k) {
    ans = min(ans, cost + ex);
  } else {
    dfs(j + 1, E, cost, ex); // 不改
    ex += c[j];
    cost = 0;
    vector<Eg> nE;
    int pt = 0;
    ds.init(n + k);
    for (int i = 0; i < E.size(); i++) {
      for (; pt < con[j].size() && con[j][pt].d < E[i].d; pt++)
        if (ds.mrg(con[j][pt].u, con[j][pt].v)) cost += con[j][pt].d, nE.emplace_back(con[j][pt]);
      if (ds.mrg(E[i].u, E[i].v)) cost += E[i].d, nE.emplace_back(E[i]);
    } // 别忘了 pt 可能每看完
    for (; pt < con[j].size(); pt++)
      if (ds.mrg(con[j][pt].u, con[j][pt].v)) cost += con[j][pt].d, nE.emplace_back(con[j][pt]);
    dfs(j + 1, nE, cost, ex); // 改
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) cin >> eg[i].u >> eg[i].v >> eg[i].d;
  for (int j = 1; j <= k; j++) {
    cin >> c[j];
    for (int i = 1; i <= n; i++) {
      int d;
      cin >> d;
      con[j].emplace_back((Eg){n + j, i, d});
    }
    sort(con[j].begin(), con[j].end());
  }
  // Kruskal 缩减边数
  sort(&eg[1], &eg[m + 1]);
  vector<Eg> E;
  ds.init(n + k);
  for (int i = 1; i <= m; i++)
    if (ds.mrg(eg[i].u, eg[i].v)) ans += eg[i].d, E.emplace_back(eg[i]);
  // 枚举改造点
  dfs(1, E, ans, 0);
  cout << ans << "\n";
  // cerr << clock() * 1000 / CLOCKS_PER_SEC << "\n" << flush;
  return 0;
}