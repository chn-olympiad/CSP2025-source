#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e4+13;
const int M = 1e6+3;

int n, m, k, a[13][N];
struct edge {
	int u, v, w;
	bool operator < (const edge &o) const {return w < o.w;}
} ed[M], g[M];
ll ans = 1e18, c[N];
int f[N], sz[N];

int find(int k) {
	return f[k]==k ? k : f[k]=find(f[k]);
}
ll kruskal(int n, int nm) {
	for(int i=1; i <= n; ++i) f[i] = i, sz[i] = 1;
	ll s=0;
	int cnt = 0, i=1, j=1;
	while(i<=m || j<=nm) {
		edge e;
		if(i > m) e = g[j++];
		else if(j > nm) e = ed[i++];
		else if(ed[i].w < g[j].w) e = ed[i++];
		else e = g[j++];
		int u = find(e.u), v = find(e.v);
		if(u != v) {
			if(sz[u] > sz[v]) swap(u, v);
			f[u] = v, sz[v] += sz[u];
			s += e.w;
			if(++cnt >= n-1) break;
		}
	}
	return s;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;
	for(int i=1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ed[i] = {u, v, w};
	}
	for(int i=1; i <= k; ++i) {
		for(int j=0; j <= n; ++j) scanf("%d", &a[i][j]);
	}
	sort(ed+1, ed+m+1);
	for(int s=0; s<1<<k; ++s) {
		int totp = n, cur = 0;
		ll cst = 0;
		for(int i=1; i <= k; ++i) {
			if(s>>i-1 & 1) {
				totp++, cst += a[i][0];
				for(int j=1; j <= n; ++j) g[++cur] = {totp, j, a[i][j]};
			}
		}
		if(cst >= ans) break;
		sort(g+1, g+cur+1);
		ans = min(ans, kruskal(totp, cur) + cst);
	}
	cout << ans;
	return 0;
}

