#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;

constexpr int N = 1e4 + 10;
constexpr int M = 1e6 + 10;
constexpr int K = 15;

template<typename T>
void read(T &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}

int n, m, k;
vector<tuple<int, int, int>> edges;
int c[K], a[K][N];

struct DSU {
  vector<int> f;
  // vector<int> siz;
  DSU(int n) {
    f.resize(n + 1);
    // siz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) f[i] = i;
  }
  int get(int x) {
    if (x != f[x]) f[x] = get(f[x]);
    return f[x];
  }
  bool merge(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return false;
    // if (siz[x] < siz[y]) swap(x, y);
    f[y] = x;
    // siz[x] += siz[y];
    return true;
  }
};

vector<tuple<int, int, int>> edges2;

i64 kruskal2() {
  i64 res = 0;
  sort(edges.begin(), edges.end(), [](tuple<int, int, int> u, tuple<int, int, int> v) {
    return get<2>(u) < get<2>(v);
  });
  DSU U(n);
  int cnt = 0;
  for (auto [u, v, w] : edges) {
    if (U.merge(u, v)) {
      res += w;
      cnt++;
      edges2.emplace_back(u, v, w);
      if (cnt >= n) break;
    }
  }
  return res;
}

i64 kruskal(int S) {
  vector<tuple<int, int, int>> e = edges2;
  int vcnt = 0;
  i64 res = 0;
  // e.reserve(n + n * k);
  for (int i = 0; i < k; i++) {
    if ((S >> i) & 1) {
      for (int j = 1; j <= n; j++) {
        e.emplace_back(n + i + 1, j, a[i + 1][j]);
      }
      vcnt++;
      res += c[i + 1];
    }
  }
  // cout << vcnt << endl;
  sort(e.begin(), e.end(), [](tuple<int, int, int> u, tuple<int, int, int> v) {
    return get<2>(u) < get<2>(v);
  });
  DSU U(n + k);
  int cnt = 0;
  for (auto [u, v, w] : e) {
    // cout << u << ' ' << v << endl;
    if (U.merge(u, v)) {
      res += w;
      cnt++;
      if (cnt >= n + vcnt) break;
    }
  }
  return res;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);

  // cin.tie(nullptr)->sync_with_stdio(false);

  // cin >> n >> m >> k;
  read(n), read(m), read(k);
  edges.resize(m);
  for (auto &[u, v, w] : edges) {
    // cin >> u >> v >> w;
    read(u), read(v), read(w);
  }
  for (int i = 1; i <= k; i++) {
    // cin >> c[i];
    read(c[i]);
    for (int j = 1; j <= n; j++) read(a[i][j]);
  }

  i64 res = kruskal2();
  for (int S = 1; S < (1 << k); S++) {
    res = min(res, kruskal(S));
  }
  
  cout << res << '\n';

  return 0;
}