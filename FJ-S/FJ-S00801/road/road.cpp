#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 20, M = 2e6 + 10, K = 30, KK = 5010;
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n, m, k, c[N], fa[N], id[N], tot, _tot, iid[N];
bool vis[N];
ll a[K][N], dist[KK][KK], tmp[KK][KK], ans = 1e18, CCnt, Cnt, _dist[KK];
struct edge {
	int u, v; ll w;
} e[M];
int nbs[N], Tot;
struct Edge {
	int ed, ne, w;
} E[M << 1];
void add(int u, int v, int w) {
	E[++ Tot] = {v, nbs[u], w}, nbs[u] = Tot;
}
bool cmp(edge a, edge b) {
	return a.w < b.w;
}
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void kruskal() {
	for (int i = 1; i <= n + k; i ++ ) fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i ++ ) {
		int u = e[i].u, v = e[i].v;
		u = find(u), v = find(v);
		if (u != v) {
			fa[u] = v, add(e[i].u, e[i].v, e[i].w), add(e[i].v, e[i].u, e[i].w);
			if (e[i].u <= n && e[i].v <= n) CCnt += e[i].w;
		} 
	}
}
void dfs(int x, int pre) {
	id[x] = tot;
	for (int i = nbs[x]; i; i = E[i].ne) {
		int j = E[i].ed;
		if (j == pre || j > n) continue;
		dfs(j, x);
	}
}
void _dfs(int x, int pre) {
	iid[id[x]] = _tot;
//	iid[id[x]] = 1;
	if (x > n) Cnt += c[x];
	for (int i = nbs[x]; i; i = E[i].ne) {
		int j = E[i].ed;
		if (j == pre || !vis[j]) continue;
		if (j > n || x > n) Cnt += E[i].w;
		_dfs(j, x);
	}
}
int calc(int x) {
	int res = 0;
	while (x) res += x & 1, x >>= 1;
	return res;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; i ++ )
		u = read(), v = read(), w = read(), e[i] = {u, v, w};
	for (int i = 1; i <= k; i ++ ) {
		c[i + n] = read();
		for (int j = 1; j <= n; j ++ )
			a[i][j] = read(), e[++ m] = {i + n, j, a[i][j]};
	}
	kruskal();
	for (int i = 1; i <= n; i ++ )
		if (!id[i]) ++ tot, dfs(i, 0);
	for (int i = 1; i <= tot; i ++ )
		for (int j = 1; j <= tot; j ++ )
			if (i != j) dist[i][j] = 1e18;
	for (int i = 1; i <= m; i ++ ) {
		int u = e[i].u, v = e[i].v;
		if (u > n || v > n) continue;
		int x = id[u], y = id[v];
		if (x == y) continue;
		dist[x][y] = dist[y][x] = min(dist[x][y], e[i].w);
	}
	for (int i = n + 1; i <= n + k; i ++ ) id[i] = i - n + tot;
//	int Tmp = 0; for (int i = 1; i <= n + k; i ++ ) Tmp = max(Tmp, id[i]);
//	cout << Tmp << '\n';
	int Tmp = 0;
	for (int S = 0; S < (1 << k); S ++ ) {
		for (int i = 1; i <= n + k; i ++ ) vis[i] = 0;
		for (int i = 1; i <= n; i ++ ) vis[i] = 1;
		Cnt = 0, _tot = 0;
		for (int j = 0; j < k; j ++ )
			if (S & (1 << j)) vis[n + j + 1] = 1;
		for (int i = 1; i <= tot; i ++ )
			for (int j = 1; j <= tot; j ++ )
				if (i != j) tmp[i][j] = 1e18;
		for (int i = 1; i <= n + k; i ++ ) iid[id[i]] = 0;
		for (int i = 1; i <= n; i ++ )
			if (!iid[id[i]]) ++ _tot, _dfs(i, i);
//		cout << _tot << " ";
		for (int i = 1; i <= tot; i ++ )
			for (int j = 1; j <= tot; j ++ ) {
				int x = iid[i], y = iid[j];
				if (x != y) tmp[x][y] = tmp[y][x] = min(dist[i][j], tmp[x][y]);
			}
		for (int i = n + 1; i <= n + k; i ++ ) {
			if (!vis[i]) continue;
			for (int j = 1; j <= n; j ++ ) {
				int x = iid[i], y = iid[j];
				if (x != y) tmp[x][y] = tmp[y][x] = min(tmp[x][y], a[i - n][j]);
			}
		}
		for (int i = 1; i <= _tot; i ++ ) vis[i] = 0, _dist[i] = 1e18;
		_dist[1] = 0;
		ll _ = 0;
		for (int i = 1; i <= _tot; i ++ ) {
			int p = -1;
			for (int j = 1; j <= _tot; j ++ )
				if (!vis[j] && (p == -1 || _dist[j] < _dist[p])) p = j;
			if (p != -1) {
				vis[p] = 1, _ += _dist[p];
				for (int j = 1; j <= _tot; j ++ )
					if (_dist[j] > tmp[p][j]) _dist[j] = tmp[p][j];				
			}
		}
		ans = min(ans, CCnt + Cnt + _);
	}
	cout << ans;
	return 0;
}

