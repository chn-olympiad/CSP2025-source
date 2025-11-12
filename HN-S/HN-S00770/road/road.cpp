#include <bits/stdc++.h>

using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

constexpr int N = 1E4 + 5, K = 12;

int n, m, k;
i64 ans = INT64_MAX;
std::array<int, K> c;
std::array<std::array<int, N>, K> a, od;
std::vector<std::tuple<int, int, int>> e, t;

std::array<int, N + K> anc;
void Reset() { std::iota(anc.data() + 1, anc.data() + n + k + 1, 1); }
int Anc(int o) { return o - anc[o] ? anc[o] = Anc(anc[o]) : o; }

std::array<int, K> hd;
std::priority_queue<std::pair<int, int>> pq;
void Proc(int s) {
  i64 curw = 0;
  int cc = n + __builtin_popcount(s);
  while (pq.size()) pq.pop();
  for (int t = s; t; t &= t - 1) {
    int k = __builtin_ctz(t);
    curw += c[k], hd[k] = 1, pq.emplace(-a[k][od[k][1]], k);
  }
  Reset();
  auto run = [&](int u, int v, int w) {
    if (Anc(u) - Anc(v)) curw += w, anc[Anc(u)] = Anc(v), --cc;
  };
  for (auto [w, u, v] : t) {
    if (cc == 1) break;
    while (pq.size() && -pq.top().first <= w && cc - 1) {
      int k = pq.top().second;
      run(od[k][hd[k]], n + k + 1, -pq.top().first), pq.pop();
      if (++hd[k] <= n) pq.emplace(-a[k][od[k][hd[k]]], k);
    }
    run(u, v, w);
  }
  ans = std::min(ans, curw);
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m >> k, e.resize(m);
  for (auto &[w, u, v] : e) std::cin >> u >> v >> w;
  for (int i = 0; i < k; ++i) {
    std::cin >> c[i];
    for (int j = 1; j <= n; ++j) std::cin >> a[i][j], od[i][j] = j;
    std::sort(od[i].data() + 1, od[i].data() + n + 1,
      [&](int u, int v) { return a[i][u] < a[i][v]; });
  }

  std::sort(begin(e), end(e)), Reset();
  for (auto [w, u, v] : e)
    if (Anc(u) - Anc(v)) t.emplace_back(w, u, v), anc[Anc(u)] = Anc(v);
  
  for (int s = 0; s < (1 << k); ++s) Proc(s);
  std::cout << ans << '\n';

  return 0;
}