#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define cfor(i, a, b) for (int i = a; i <= b; i++)
#define ofor(i, a, b) for (int i = a; i < b; i++)
#define bfor(i, a, b) for (int i = a; i >= b; i--)
#define mset(a, x) memset(a, x, sizeof(a))
const int N = 1e4 + 20;
const int M = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, K;

ll cost[15];
int town;
bool ok[15];

struct edge {
  int u, v;
  ll w;
  bool operator < (const edge &x) const {
    return w < x.w;
  }
} a[M], b[15][N];
int pa, pb[15];

int fa[N];
int Find(int u) {
  if (fa[u] == u) return u;
  return fa[u] = Find(fa[u]);
}

void Merge(int u, int v) {
  u = Find(u), v = Find(v);
  if (u == v) return;
  fa[u] = v;
  return;
}

edge get_min() {
  edge ret = a[pa];
  int idx = 0;
  cfor (i, 1, K) {
    if (not ok[i]) continue;
    if (b[i][pb[i]] < ret) {
      ret = b[i][pb[i]];
      idx = i;
    }
  }
  if (idx == 0) pa++;
  else pb[idx]++;
  return ret;
}

ll sum;
void Kruskal() {
  int cnt = 0;
  while (cnt < n + town - 1) {
    edge e = get_min();
    if (Find(e.u) == Find(e.v)) continue;
    Merge(e.u, e.v);
    sum += e.w;
    cnt++;
  }
  return;
}

void init() {
  town = 0;
  sum = 0;
  pa = 1;
  cfor (i, 1, K) pb[i] = 1, ok[i] = false;
  cfor (i, 1, n + K) fa[i] = i;
  return;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m >> K;
  cfor (i, 1, m) {
    int u, v; ll w;
    cin >> u >> v >> w;
    a[i] = {u, v, w};
  }
  sort(a + 1, a + m + 1);

  cfor (i, 1, K) {
    cin >> cost[i];
    cfor (j, 1, n) {
      ll w;
      cin >> w;
      b[i][j] = {n + i, j, w};
    }
    sort(b[i] + 1, b[i] + n + 1);
  }

  ll ans = inf;
  ofor (S, 0, (1 << K)) {
    init();
    cfor (i, 1, K) {
      if ((S >> (i - 1)) & 1) {
        ok[i] = true;
        town++;
        sum += cost[i];
      }
    }
    Kruskal();
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}