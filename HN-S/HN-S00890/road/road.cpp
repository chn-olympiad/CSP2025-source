#include <bits/stdc++.h>
#define int long long

using namespace std;

const int M = 1e6 + 10;
const int N = 1e4 + 10;

int n, m, k, tot, ans;
int fa[N], a[20][N], c[20];
bool need[N];
struct edge {
  int u, v, w;
} graph[M], temp[N];

bool cmp(edge x, edge y) {
  return x.w < y.w;
}

int find(int a) {
  return fa[a] == a ? a : fa[a] = find(fa[a]);
}

int get_ans() {
  iota(fa + 1, fa + n + k + 1, 1);
  int res = 0, num = tot;
  for (int i = 1; i <= tot; i++) {
    graph[i] = temp[i];
  }
  for (int i = 1; i <= k; i++) {
    if (!need[i])
      continue;
    res += c[i];
    for (int j = 1; j <= n; j++) {
      graph[++num] = {i + n, j, a[i][j]};
    }
  }
  sort(graph + 1, graph + num + 1, cmp);
  for (int i = 1; i <= num; i++) {
    int u = graph[i].u, v = graph[i].v, w = graph[i].w;
    if (find(u) != find(v)) {
      res += w;
      fa[find(u)] = find(v);
      if (res >= ans) {
        return ans;
      }
    }
  }
  return res;
}

void dfs(int now) {
  if (now == k + 1) {
    ans = min(ans, get_ans());
    if (clock() >= 950) {
      printf("%lld", ans);
      exit(0);
    }
    return;
  }
  need[now] = 1;
  dfs(now + 1);
  need[now] = 0;
  dfs(now + 1);
}

int read() {
  char tmp = getchar();
  int res = 0;
  while (isdigit(tmp)) {
    res = res * 10 + (tmp - '0');
    tmp = getchar();
  }
  return res;
}

signed main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  n = read(), m = read(), k = read();
  for (int i = 1, u, v, w; i <= m; i++) {
    u = read(), v = read(), w = read();
    graph[i] = {u, v, w};
  }
  sort(graph + 1, graph + m + 1, cmp);
  iota(fa + 1, fa + n + 1, 1);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int u = graph[i].u, v = graph[i].v, w = graph[i].w;
    ans += w;
    if (find(u) != find(v)) {
      graph[++tot] = {u, v, w};
      temp[tot] = {u, v, w};
      if (tot == n - 1)
        break;
      fa[find(u)] = find(v);
    }
  }
  for (int i = 1; i <= k; i++) {
    c[i] = read();
    for (int j = 1; j <= n; j++) {
      a[i][j] = read();
    }
  }
  dfs(1);
  printf("%lld", ans);
  return 0;
}
