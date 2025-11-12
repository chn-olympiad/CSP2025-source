#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

struct node {
  int u, v, w;
} e[2000005];

int n, m, k, c[11], a[11][N], fa[N + 10];

long long ans;

bool vis[N];

bool cmp(node _x, node _y) {
  return _x.w < _y.w;
}

int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  return fa[x] = find(fa[x]);
}

void check(long long tmp, int num) {
  for (int i = 1; i <= n + k; i++) {
    fa[i] = i;
  }
  long long cnt = 0, sum = 0;
  for (auto [u, v, w] : e) {
    if (u > n && !vis[u - n]) {
      continue;
    }
    if (find(u) != find(v)) {
      cnt++;
      u = find(u);
      v = find(v);
      fa[u] = v;
      sum += w;
    }
    if (cnt == n + num - 1) {
      ans = min(ans, sum + tmp);
      return ;
    }
  }
}

void dfs(int cnt, long long sum, int res) {
  if (cnt == k + 1) {
    check(sum, res);
    return ;
  }
  dfs(cnt + 1, sum, res);
  vis[cnt] = true;
  dfs(cnt + 1, sum + c[cnt], res + 1);
  vis[cnt] = false;
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  ans = 1e18;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  for (int i = 1, u, v, w; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
  }
  for (int i = 1; i <= k; i++) {
    cin >> c[i];
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      e[m + (i - 1) * n + j] = {i + n, j, a[i][j]};
    }
  }
  sort(e + 1, e + m + k * n + 1, cmp);
  dfs(1, 0, 0);
  cout << ans;
  return 0;
}
