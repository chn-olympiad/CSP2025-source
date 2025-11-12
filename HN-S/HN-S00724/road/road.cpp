#include <bits/stdc++.h>

using namespace std;

const int N = 2000005, K = 13;

struct Edge {
  int u, v, w;
  bool operator <(const Edge &x) const {
    return w < x.w;
  }
} e[N], le[N];

int c[N];
int a[K][N], minp[K];
int fa[N];

int dsu_find(int x) {
  return fa[x] == x ? x : fa[x] = dsu_find(fa[x]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  int n, m, k;
  cin >> n >> m >> k;
  int M = 0;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    minp[i] = 1;
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] < a[i][minp[i]]) {
        minp[i] = j;
      }
    }
  }
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= n + k; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int fu = dsu_find(e[i].u), fv = dsu_find(e[i].v);
    if (fu != fv) {
      fa[fu] = fv;
      le[++M] = e[i];
    }
  }
  long long ans = 1145141919810114514;
  for (int mask = 0; mask < (1 << k); mask++) {
    m = M;
    for (int i = 1; i <= m; i++) {
      e[i] = le[i];
    }
    long long sum = 0;
    int cnt = n - 1;
    for (int i = 1; i <= k; i++) {
      if (mask & (1 << i - 1)) {
        cnt++;
        for (int j = 1; j <= n; j++) {
          e[++m] = {n + i, j, a[i][j]};
        }
        sum += c[i];
      }
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n + k; i++) {
      fa[i] = i;
    }
    for (int i = 1, rcnt = 0; i <= m && rcnt < cnt; i++) {
      int fu = dsu_find(e[i].u), fv = dsu_find(e[i].v);
      if (fu != fv) {
        rcnt++;
        sum += e[i].w;
        fa[fu] = fv;
      }
    }
    ans = min(ans, sum);
  }
  cout << ans << '\n';
}