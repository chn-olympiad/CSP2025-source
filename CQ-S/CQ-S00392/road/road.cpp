#include <bits/stdc++.h>

struct DSU {
  std::vector<int> fa;

  explicit DSU(int N) : fa(N, -1) {}

  int find(int u) {
    while (fa[u] >= 0 && fa[fa[u]] >= 0) { u = fa[u] = fa[fa[u]]; }
    return fa[u] >= 0 ? fa[u] : u;
  }

  bool unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) { return false; }
    if (fa[u] > fa[v]) { std::swap(u, v); }
    return fa[u] += fa[v], fa[v] = u, true;
  }
};

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, M, K;
  std::cin >> N >> M >> K;

  std::vector<std::tuple<int, int, int>> edges(M);
  for (auto &t: edges) {
    int u, v, w;
    std::cin >> u >> v >> w, u--, v--;
    t = std::make_tuple(w, u, v);
  }
  std::sort(edges.begin(), edges.end());

  DSU dsu(N);
  std::vector<std::tuple<int, int, int, int>> nw;
  for (auto t: edges) {
    int u, v, w;
    std::tie(w, u, v) = t;
    if (dsu.unite(u, v)) { nw.emplace_back(w, u, v, 0); }
  }

  std::vector<int> C(K);
  for (int i = 0; i < K; i++) {
    std::cin >> C[i];
    for (int j = 0, w; j < N; j++) {
      std::cin >> w, nw.emplace_back(w, j, i + N, i + 1);
    }
  }

  std::sort(nw.begin(), nw.end());

  long long ans = LLONG_MAX;
  for (int st = 0; st < (1 << K); st++) {
    long long cur = 0;
    DSU dsu(N + K);
    for (int i = 0; i < K; i++) {
      if (st >> i & 1) { cur += C[i];  }
    }
    for (auto t: nw) {
      int u, v, w, id;
      std::tie(w, u, v, id) = t;
      if (id && (~st >> (id - 1) & 1)) { continue; }
      if (dsu.unite(u, v)) { cur += w; }
    }
    ans = std::min(ans, cur);
  }
  std::cout << ans << '\n';

  return 0;
}

/*
g++ road.cpp -o road -O2 -std=c++14 -static && 
ulimit -t 1 &&
ulimit -v 256000 &&
cp road1.in road.in && ./road && diff road.out road1.ans &&
cp road2.in road.in && ./road && diff road.out road2.ans &&
cp road3.in road.in && ./road && diff road.out road3.ans &&
cp road4.in road.in && ./road && diff road.out road4.ans &&
cp road5.in road.in && ./road && diff road.out road5.ans &&
echo Accepted!
*/