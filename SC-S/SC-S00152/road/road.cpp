#include <cstdio>
#include <algorithm>
#include <vector>
#include <cctype>
using std::vector;
typedef long long ll;
const int N = 10004, K = 15, M = 1000006;
int read() {
	char c = getchar();
	while (!std::isdigit(c)) c = getchar();
	int x = 0;
	while (std::isdigit(c)) {
		x = ((x + (x << 2)) << 1) + (c ^ 48);
		c = getchar();
	}
	return x;
}
struct Edge {
	int u, v, w;
	void input() {
		u = read();
		v = read();
		w = read();
	}
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
};
int n, m, k;
Edge e[M];
int c[K];
ll a[K][N];
int fa[N], h[N];
int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return 0;
	if (h[u] < h[v]) std::swap(u, v);
	fa[v] = u;
	h[u] += h[v];
	return 1;
}
struct Vedge {
	int id, ver, w;
};
std::vector<Vedge> G[N];
int qwqcnt = 0;
int a_to[N];
int cost[N], cp[N];
void add_edge(int u, int v, int w) {
	++qwqcnt;
	G[u].push_back({qwqcnt, v, w});
	G[v].push_back({qwqcnt, u, w});
}
ll w_edge[N];
void dfs(int u, int _fa) {
	for (Vedge ve : G[u]) {
		int v = ve.ver, id = ve.id;
		if (v != _fa)
			w_edge[id] = ve.w, dfs(v, u);
	}
}
int rp;
void re_dfs(int u, int _fa) {
	for (Vedge ve : G[u]) {
		int v = ve.ver, id = ve.id;
		if (v != _fa)
			w_edge[id] = std::min(w_edge[id], a[rp][v]), re_dfs(v, u);
	}
}
int main() {
	//qwq rp++!
	//Ya int_4096 desu
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
		e[i].input();
	std::sort(e + 1, e + 1 + m);
	for (int i = 1; i <= n; i++)
		fa[i] = i, h[i] = 1;
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (merge(u, v))
			ans += w, add_edge(u, v, w);
	}
	if (k == 0)
		printf("%lld\n", ans);
	else {
		dfs(1, 0);
		for (int i = 1; i <= k; i++) {
			c[i] = read();
			rp = i;
			for (int j = 1; j <= n; j++) {
				a[i][j] = read();
				if (a[i][j] == 0)
					a_to[i] = j;
			}
		}
		ans = 0;
		for (int i = 1; i <= k; i++)
			re_dfs(a_to[i], 0);
		for (int i = 1; i <= qwqcnt; i++)
			ans += w_edge[i];
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
CSP-S
KaoShengMiHuoXingWeiDaShang:
14:32
Open T2.
Ahh, more complex MST.
15:34
k <= 10?
if we enum the set which is 2^k = 1024
A simple transform is to connect..
No it's wrong!
15:50
Have some thoughts.
But I think do T3, T4 bf first.
16:56
No only 1:30 left..
And I just start.
17:48
Sadly, the algorithm is fake.
no time to be sad, debug T1, it's my last chance.
*/