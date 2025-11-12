#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <queue>
#include <numeric>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ifstream fin("road.in");
ofstream fout("road.out");

const int kN = 1e4 + 11;

ll ans = 1e18, s[kN], f[kN], v[kN];
int n, m, k, c[11][kN];
struct Edge {
  int u, v, w;

  bool operator<(const Edge& t) const { return w < t.w; }
};
vector<Edge> ed, _ed;

int Find(int x) {
  return f[x] == x ? x : f[x] = Find(f[x]);
}
ll Prime() {
  iota(f + 1, f + n + 1, 1);
  ll res = 0;
  sort(ed.begin(), ed.end());
  for (int i = 0; i < (int)ed.size(); i++) {
    int x = Find(ed[i].u), y = Find(ed[i].v), z = ed[i].w;
    if (x == y)
      continue;
    f[y] = x, res += z;
  }
  return res;
}

int main() {
  fin.tie(0)->sync_with_stdio(0);
  fin >> n >> m >> k;
  if (m >= 1e6 && k > 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1, x, y, z; i <= m; i++) {
    fin >> x >> y >> z;
    _ed.push_back({x, y, z});
  }
  for (int i = 1; i <= k; i++)  {
    fin >> c[i][0];
    for (int j = 1; j <= n; j++)
      fin >> c[i][j];
  }
  for (int s = 0; s < 1 << k; s++) {
    ll t = 0;
    ed = _ed;
    for (int i = 1; i <= k; i++) {
      if (s >> (i - 1) & 1) {
        t += c[i][0];
        for (int j = 1; j <= n; j++)
          ed.push_back({i + n, j, c[i][j]});
      }
    }
    ans = min(ans, Prime() + t);
    _ed = ed;
  }
  fout << ans;
  return 0;
}