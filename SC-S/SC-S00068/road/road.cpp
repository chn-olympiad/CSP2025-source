#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10, maxm = 1e6 + 10;
int n, m, nod, k, MAX_W, a[11][maxn], fa[maxm];
long long ans = 0, out = 0;
struct Edge {
	int u, v, w;
	bool operator < (const Edge & t) const {
		return w < t.w;
	}
}e1[maxm], e2[maxm], e3[maxm];
inline int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void kruscal1() {
	sort(e1 + 1, e1 + m + 1);
	for(int i = 1; i <= n; ++ i) fa[i] = i;
	for(int i = 1, j = 1, fx, fy; i <= m && j < n; ++ i) {
		fx = find(e1[i].u), fy = find(e1[i].v);
		if(fx != fy) {
			e2[j ++] = e1[i];
			fa[fx] = fy;
			ans += e1[i].w;
		}
	}
	MAX_W = e2[n - 1].w;
}
void kruscal2() {
	for(int i = 1; i <= nod; ++ i) fa[i] = i;
	sort(e3 + 1, e3 + m + 1);
	for(int i = 1, j = 1, fx, fy; i <= m && j < nod; ++ i) {
		fx = find(e3[i].u), fy = find(e3[i].v);
		if(fx != fy) {
			fa[fx] = fy;
			ans += e3[i].w;
		}
	}
	out = min(ans, out);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++ i) cin >> e1[i].u >> e1[i].v >> e1[i].w;
	kruscal1(); out = ans;
	for(int j = 1; j <= k; ++ j) 
		for(int i = 0; i <= n; ++ i) 
			cin >> a[j][i];
	for(int s = 1; s < (1 << k); ++ s) {
		nod = n; m = n - 1; ans = 0;
		for(int i = 1; i <= m; ++ i) e3[i] = e2[i];
		for(int i = 1; i <= k; ++ i) {
			if(s & (1 << (i - 1))) {
				++ nod;
				ans += a[i][0];
				for(int j = 1; j <= n; ++ j) if(a[i][j] <= MAX_W) e3[++ m] = {nod, j, a[i][j]};
			}
		}
		kruscal2();
	}
	cout << out;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/