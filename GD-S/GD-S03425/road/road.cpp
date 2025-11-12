#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 10005;
const int MXM = 1000005;
const int MXK = 14;
const int MXP = MXN + MXK;
const ll INF = 1e18;
int N, M, K, P, fa[MXP], sc[MXK], it[MXK];
tuple<int, int, int> es[MXM], spe[MXK][MXN];
ll ans(INF), sum;

inline void dsu_init() { iota(fa, fa + P, 0); }
int find(int x) { return fa[x] ^ x ? fa[x] = find(fa[x]) : x; }

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N >> M >> K, P = N + K;
  for (int i(0), u(0), v(0), w(0); i != M; ++i) {
    cin >> u >> v >> w, --u, --v;
    es[i] = make_tuple(w, u, v);
  }
  sort(es, es + M);
  dsu_init();
  for (int i(0), e(0); i != M; ++i) {
    auto [w, u, v] = es[i];
    u = find(u), v = find(v);
    if (u == v) continue;
    fa[u] = v, swap(es[i], es[e++]);
  }
  for (int i(0); i != K; ++i) {
    cin >> sc[i];
    for (int j(0), w(0); j != N; ++j) {
      cin >> w;
      spe[i][j] = make_tuple(w, j, N + i);
    }
    sort(spe[i], spe[i] + N);
  }
  for (int s(0); s != (1 << K); ++s) {
    dsu_init();
    priority_queue<pair<int, int>> pq;
    sum = 0;
    for (int i(0); i != K; ++i)
      if ((s >> i) & 1)
        sum += sc[i], it[i] = 0, pq.push({-get<0>(spe[i][0]), i});
    it[K] = 0, pq.push({-get<0>(es[0]), K});
    while (!pq.empty()) {
      int id(pq.top().second);
      pq.pop();
      auto [w, x, y] = (id == K ? es[it[K]++] : spe[id][it[id]++]);
      if (id == K && it[K] != N - 1) pq.push({-get<0>(es[it[K]]), K});
      else if (id != K && it[id] != N) pq.push({-get<0>(spe[id][it[id]]), id});
      x = find(x), y = find(y);
      if (x != y) sum += w, fa[x] = y;
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
