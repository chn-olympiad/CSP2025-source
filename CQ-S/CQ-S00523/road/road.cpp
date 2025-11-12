#include <bits/stdc++.h> 
#define ll long long
using namespace std;

namespace Creeper{
	const int N = 2e4 + 105, M = 15;
	int n, m, k, p[M], cnt, a[M], fa[N], tot;
	ll ans;
	struct node {
		int u, v, w;
	};
	struct nd{
		int i, w; 
	} c[M][N];
	vector<node> e, g;
	int find(int u) {
		if (u == fa[u]) return u;
		return fa[u] = find(fa[u]);
	} 
	bool cmp(node a, node b) {
		return a.w < b.w;
	}
	void Kruskal1() {
		ans = 0;
		for (int i = 1; i <= n; i++) fa[i] = i;
		sort(g.begin(), g.end(), cmp);
		for (int i = 0; i < g.size(); i++) {
			int u = g[i].u, v = g[i].v, w = g[i].w;
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			fa[fu] = fv;
			ans += w;
			e.push_back(g[i]); 
		}
	}
	void Kruskal2() {
		ll res = 0;
		vector<node> t;
		t.clear();
		for (int i = 1; i <= cnt; i++) {
			int x = p[i];
			res += a[x]; 
			vector<node> tmp;
			int ppp = 0;
			for (int j = 1; j <= n; j++) {
				while (ppp < t.size() && t[ppp].w <= c[x][j].w) {
					tmp.push_back(t[ppp]);
					ppp++;
				}
				tmp.push_back((node){n + x, c[x][j].i, c[x][j].w});
			}
			while (ppp < t.size()) {
				tmp.push_back(t[ppp]);
				ppp++;
			}
			t = tmp;
		}
		
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		
		int pp = 0;
		for (int j = 0; j < e.size(); j++) {
			int u = e[j].u, v = e[j].v, w = e[j].w;
			
			for (;pp < t.size() && t[pp].w <= w; pp++) {
				int ftu = find(t[pp].u), ftv = find(t[pp].v);
				if (ftu == ftv) continue;
				fa[ftu] = ftv;
				res += t[pp].w;
				if (res >= ans) return;
			}
			
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			fa[fu] = fv;
			res += w;
			if (res >= ans) return;
		}
		if (res <= ans) {
			ans = res;
		} 
	}
	void dfs(int u) {
		if (u > k) {
			Kruskal2();
			return;	
		}
		dfs(u + 1);
		cnt++;
		p[cnt] = u;
		dfs(u + 1);
		p[cnt] = 0;
		cnt--;
	}
	bool cmp2(nd a, nd b) {
		return a.w < b.w;
	}
	void solve() {
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			g.push_back({u, v, w});
		}
		Kruskal1();
		for (int i = 1; i <= k; i++) {
			cin >> a[i]; 
			for (int j = 1; j <= n; j++) cin >> c[i][j].w, c[i][j].i = j;
			sort(c[i] + 1, c[i] + n + 1, cmp2);
		}
		dfs(1);
		cout << ans;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Creeper::solve(); 
}
