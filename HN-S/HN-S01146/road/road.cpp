#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int kN = 1e4 + 5, kK = 11;

int n, m, k;
struct Edge {
  int u, v, w;
  inline bool operator<(const Edge &x) const { return w < x.w; }
};
vector<Edge> edge, mst;
int fa[kN];
LL ans = 0;
int Find(int x) { return x == fa[x] ? x : (fa[x] = Find(fa[x])); }

int a[kN];
vector<PII> e[kK];

vector<vector<Edge>> vec;
vector<Edge> tmp;
int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> u >> v >> w;
    edge.push_back({u, v, w});
  }
  sort(edge.begin(), edge.end());
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    for (int v = 1, w; v <= n; v++)
      cin >> w, e[i].emplace_back(w, v);
    sort(e[i].begin(), e[i].end());
  }

  iota(fa, fa + n + 1, 0);
  for (auto ED : edge) {
    int u = Find(ED.u), v = Find(ED.v), w = ED.w;
    if (u != v) {
      fa[u] = v, ans += w;
      mst.push_back(ED);
    }
  }
  // cerr << ans << '\n';
  
  for (int s = 1; s < 1 << k; s++) {
    LL cur = 0;
    for (int d = 0; d < k; d++)
      if (s >> d & 1) {
        for (auto ED : e[d + 1])
          tmp.push_back({n + d + 1, ED.second, ED.first});
        vec.push_back(tmp), tmp.clear();
        cur += a[d + 1];
      }
    vec.push_back(mst);
    int cnt = __builtin_popcount(s);
    for (int d = 1; d <= cnt; d *= 2)
      for (int i = 0; i + d <= cnt; i++) {
        tmp.resize(vec[i].size() + vec[i + d].size());
        merge(vec[i].begin(), vec[i].end(), vec[i + d].begin(), vec[i + d].end(), tmp.begin());
        vec[i].swap(tmp), tmp.clear();
      }
    // for (auto ED : vec[0])
    //   cerr << ED.u << ' ' << ED.v << ' ' << ED.w << '\n';
    // cerr << '\n';
    // cerr << vec[0].size() << ' ';
    iota(fa, fa + n + k + 1, 0);
    int tot = 0;
    for (auto ED : vec[0]) {
      int u = Find(ED.u), v = Find(ED.v), w = ED.w;
      if (u != v)
        fa[u] = v, cur += w, tot++;
      if (tot == n + cnt - 1)
        break;
    }
    vec.clear();
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}