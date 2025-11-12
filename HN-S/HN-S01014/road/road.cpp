#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define sz(x) (int)(x).size()
using ll = long long;

const int N = 1e4 + 20, M = 1e6 + 10, K = 10;
int n, m, k, c[K];

struct Edge {
  int u, v, w;
  bool operator<(Edge x) const { return w < x.w; }
} a[K][N];

int fa[N];

int find(int x) {
  while(x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if(x == y) return false;
  fa[x] = y;
  return true;
}

vector<Edge> mst(vector<Edge> &e) {
  sort(begin(e), end(e));
  vector<Edge> e1;
  e1.reserve(n + k);
  rep(i, 1, n + k) fa[i] = i;
  for(auto [u, v, w] : e)
    if(merge(u, v)) e1.push_back({u, v, w});
  return e1;
}

ll ans = 4e18;

void dfs(int i, ll tag, vector<Edge> e) {
  if(i == k) {
    ll res = tag;
    for(auto [u, v, w] : e) res += w;
    ans = min(ans, res);
    return;
  }
  dfs(i + 1, tag, e);
  e.insert(end(e), a[i] + 1, a[i] + n + 1);
  dfs(i + 1, tag + c[i], mst(e));
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  vector<Edge> e(m);
  for(auto &[u, v, w] : e) cin >> u >> v >> w;
  rep(i, 0, k - 1) {
    cin >> c[i];
    rep(j, 1, n) {
      a[i][j].u = n + 1 + i;
      a[i][j].v = j;
      cin >> a[i][j].w;
    }
    sort(a[i] + 1, a[i] + n + 1);
  }
  dfs(0, 0, mst(e));
  cout << ans << "\n";
}