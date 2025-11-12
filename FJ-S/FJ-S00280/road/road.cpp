#include <bits/stdc++.h>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

using LL = long long;
using namespace std;

const int N = 1e4 + 20, M = 10;
int p[N], c[M], a[M][N];
LL s[1 << M];
vector<tuple<int, int, int>> tE[1 << M], f[M];

int find(int x) {
  return x == p[x] ? x : p[x] = find(p[x]);
}

using ve = vector<tuple<int, int, int>>;

void mg(ve &a, ve &b, ve &c) {
  int i = 0, j = 0;
  while (i < sz(a) && j < sz(b)) {
    if (j == sz(b) || (i < sz(a) && a[i] < b[j])) {
      c.eb(a[i++]);
    }
    else {
      c.eb(b[j++]);
    }
  }
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edge(m);
  for (auto &[w, u, v] : edge) {
    cin >> u >> v >> w;
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
    s[1 << i] = c[i];
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      f[i].eb(a[i][j], j, n + i + 1);
    }
    sort(all(f[i]));
  }
  vector<tuple<int, int, int>> E;
  sort(all(edge));
  iota(p + 1, p + n + 1, 1);
  LL ans = 0;
  for (auto [z, x, y] : edge) {
    x = find(x), y = find(y);
    if (x == y) {
      continue;
    }
    ans += z;
    E.eb(z, x, y);
    p[x] = y;
  }
  tE[0] = E;
  for (int i = 1; i < (1 << k); i++) {
    int j = __lg(i & -i);
    s[i] = s[i & (i - 1)] + s[i & -i];
    LL sum = s[i];
    vector<tuple<int, int, int>> nE;
    mg(tE[i & (i - 1)], f[j], nE);
    vector<tuple<int, int, int>> E;
    int tar = n + __builtin_popcount(i) - 1;
    sort(all(nE));
    iota(p + 1, p + n + k + 1, 1);
    for (auto [z, x, y] : nE) {
      x = find(x), y = find(y);
      if (x == y) {
        continue;
      }
      E.eb(z, x, y);
      sum += z;
      p[x] = y;
    }
    tE[i] = E;
    ans = min(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}