#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 10015, M = 1100005, K = 15;
typedef long long ll;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &rhs) const {
		return w < rhs.w;
	}
};
Edge E1[M], E[M];
int n, m1, k, m;
int c[K], a[K][N];
int fa[N], h[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int merge(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	if(h[x] < h[y]) std::swap(x, y);
	fa[y] = x;
	if(h[x] == h[y]) h[x]++;
	return 1;
}
ll ans;
int id[K][N];
int fla[M];
ll getans() {
	ll tans = 0;
	for(int i = 1; i <= n + k; i++) fa[i] = i, h[i] = 1;
	for(int i = 1; i <= m; i++) {
		if(!fla[i]) continue;
		int u = E[i].u, v = E[i].v;
		ll w = E[i].w;
		if(merge(u, v)) tans += w;
	}
	return tans;
}
void dfs(int x, ll tcost) {
	if(tcost >= ans) return ;
	if(x == k + 1) {
		ans = std::min(ans, getans() + tcost);
		return ;
	}
	dfs(x + 1, tcost);
	int tm = m;
	for(int i = 1; i <= n; i++) fla[id[x][i]] = 1;
	dfs(x + 1, tcost + c[x]);
	for(int i = 1; i <= n; i++) fla[id[x][i]] = 0;
	m = tm;
}
int read() {
	int x = 0;
	char t;
	while((t = getchar()) < '0') ;
	for(; t >= '0'; t = getchar()) {
		x = x * 10 + t - '0';
	}
	return x;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &k);
	for(int i = 1; i <= m1; i++) {
		E1[i].u = read();
		E1[i].v = read();
		E1[i].w = read();
	}
	for(int i = 1; i <= k; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	std::sort(E1 + 1, E1 + m1 + 1);
	for(int i = 1; i <= n; i++) fa[i] = i, h[i] = 1;
	ans = 0;
	for(int i = 1; i <= m1; i++) {
		int u = E1[i].u, v = E1[i].v, w = E1[i].w;
		if(merge(u, v)) {
			E[++m] = {u, v, w};
			ans += w;
		}
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			E[++m] = {i + n, j, a[i][j]};
		}
	}
	std::sort(E + 1, E + m + 1);
	for(int i = 1; i <= m; i++) {
		int u = E[i].u, v = E[i].v;
		if(u > n) id[u - n][v] = i;
		else fla[i] = 1;
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}