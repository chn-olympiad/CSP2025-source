#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m, k;

struct node{ int u, v, w; };
node raw[5000010], tmp[5000010]; int cnt;
int c[15];
int a[15][10010];

ll ans;

struct DSU{
	int fa[10010], rk[10010]; 
	void init(int n) {
		iota(fa+1, fa+n+1, 1);
		fill(rk+1, rk+n+1, 1);
	}
	int fr(int u) { return u==fa[u]?u:fa[u]=fr(fa[u]); }
	int merge(int u, int v) {
		if ((u = fr(u)) == (v = fr(v))) return 0;
		return fa[u] = v, rk[v] += rk[u], 1;
	}
}D;

ll mst() {
	ll res = 0;
	sort(raw+1, raw+cnt+1, [](node a, node b) -> bool {
		return a.w < b.w;
	});
	D.init(n+k);
	for (int i = 1; i <= cnt; i++) {
		if (D.merge(raw[i].u, raw[i].v)) res += raw[i].w;
	}
	return res;
}

bool flgA = 1;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> tmp[i].u >> tmp[i].v >> tmp[i].w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) flgA = 0;
		bool flg = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (!a[i][j]) flg = 1;
		}
		if (!flg) flgA = 0;
	}
	
	if (flgA) {
		for (int i = 1; i <= m; i++) raw[++cnt] = tmp[i];
		for (int i = 1; i <= k; i++) for (int j = 1; j <= n; j++) raw[++cnt] = {j, n+i, a[i][j]};
		printf("%lld", mst());
		return 0;
	}
	
//	sort(tmp+1, tmp+m+1, [](node a, node b) -> bool {
//		return a.w < b.w;
//	});
//	D.init(n);
//	for (int i = 1; i <= m; i++) {
//		if (D.merge(tmp[i].u, tmp[i].v)) ans += tmp[i].w, raw[++cnt] = tmp[i];
//	}
	ans = 0x3f3f3f3f3f3f3f3f;
//	for (int i = 1; i <= m; i++) raw[++cnt] = tmp[i];
//	m = cnt;
	
	for (int s = 1; s < (1<<k); s++) {
		cnt = 0;
		for (int i = 1; i <= m; i++) raw[++cnt] = tmp[i];
		ll cost = 0;
		int tot = n;
		for (int i = 1; i <= k; i++) {
			if (!((s>>(i-1))&1)) continue;
			tot++;
			cost += c[i];
			for (int j = 1; j <= n; j++) raw[++cnt] = {j, n+i, a[i][j]};
		}
		if (cost > ans) continue;
//		cerr << cnt << endl;
		ll res = cost+mst();
		ans = min(ans, res);
	}
	printf("%lld", ans);
}
/*
给定一个图，和若干个(<=10)额外点，启用一个额外点会耗费C代价，并同时启用该额外点与原图每个点的边
求出最小生成树的最小值 
*/
