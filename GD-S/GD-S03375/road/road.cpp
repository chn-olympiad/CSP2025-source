#include <bits/stdc++.h>
#define F(i, l, r) for (int i = l; i <= r; i ++)
#define G(i, r, l) for (int i = r; i >= l; i --)
using namespace std;
typedef long long LL;

template <typename T>
void Fmin(T &x, T y) { x = x < y ? x : y; }
template <typename T>
void Fmax(T &x, T y) { x = x > y ? x : y; }

const int N = 1e4 + 17, M = 1e6 + 7;

int read() {
  int x = 0, op = 0;
  char c = getchar();
  while (c < '0' || c > '9')
  	op ^= (c == '-'), c = getchar();
  while (c >= '0' && c <= '9')
  	x = x * 10 + (c - '0'), c = getchar();
  return x * (op ? -1 : 1);
}

LL ans = 1e18;
int n, m, k, c[17];

struct Edge {
  int u, v, w;
} e[M], a[13][N], ed[13][N], tmp[N << 1];
bool operator < (Edge x, Edge y) {
  return x.w < y.w;
}

namespace DSU {
  int fa[N], siz[N];
  void init() {
  	F(i, 1, n + k) fa[i] = i, siz[i] = 1;
  }
  int fnd(int x) {
  	return fa[x] == x ? x : fa[x] = fnd(fa[x]);
  }
  bool uni(int u, int v) {
  	if ((u = fnd(u)) == (v = fnd(v))) return false;
  	if (siz[u] < siz[v]) swap(u, v);
  	return fa[v] = u, siz[u] += siz[v], true;
  }
}

void dfs(int x, LL lpy, int cnt) {
  if (x == k + 1) {
  	LL res = lpy;
  	F(i, 1, cnt) res += ed[k][i].w;
	return Fmin(ans, res), void(); 
  }
  F(i, 1, cnt) ed[x][i] = ed[x - 1][i];
  dfs(x + 1, lpy, cnt);
  int cl = 1, cr = 1, cur = 0;
  while (cl <= cnt || cr <= n) {
  	if (cl <= cnt && (cr > n || ed[x - 1][cl] < a[x][cr]))
  	  tmp[++ cur] = ed[x - 1][cl ++];
	else tmp[++ cur] = a[x][cr ++];
  }
  cur = 0, DSU::init();
  F(i, 1, cnt + n)
  	if (DSU::uni(tmp[i].u, tmp[i].v))
  	  ed[x][++ cur] = tmp[i];
  dfs(x + 1, lpy + c[x], cnt + 1);
}

int main() {
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  n = read(), m = read(), k = read();
  F(i, 1, m)
    e[i].u = read(), e[i].v = read(), e[i].w = read();
  sort(e + 1, e + m + 1);
  F(i, 1, k) {
  	c[i] = read();
  	F(j, 1, n)
	  a[i][j].w = read(), a[i][j].u = i + n, a[i][j].v = j;
  	sort(a[i] + 1, a[i] + n + 1);
  }
  int cur = 0;
  DSU::init();
  F(i, 1, m)
  	if (DSU::uni(e[i].u, e[i].v))
  	  ed[0][++ cur] = e[i];
  dfs(1, 0, n - 1);
  cout << ans << '\n';
  return 0;
}

