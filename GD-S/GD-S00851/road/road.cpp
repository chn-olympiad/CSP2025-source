#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//#define int long long

const int maxn=1e4+100, maxm=1e6+10, maxk=12;
int n, m, k;
ll ans = 0;
int c[maxk], a[maxk][maxn];

struct edge {
	int u, v, w;
	
	bool operator < (const edge &b) const {
		return w < b.w;
	}
};
vector<edge> G1, G;

int fa[maxn+maxk], rk[maxn+maxk];

void dsu_init() {
	for (int i=1; i<=n+k; i++) {
		fa[i] = i;
		rk[i] = 1;
	}
}

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	return (fa[x] = find(fa[x]));
}

void join(int fx, int fy) {
	if (rk[fx] < rk[fy]) {
		swap(fx, fy);
	}
	
	rk[fx] += rk[fy];
	fa[fy] = fx;
}

ll kruskal(int n2) {
	G = G1;
	sort(G.begin(), G.end());
	dsu_init();
	
	ll ans = 0, cnt = 0;
	for (auto e: G) {
		int u=e.u, v=e.v;
		int fu=find(u), fv=find(v);
		if (fu == fv) {
			continue;
		}
		
		join(fu, fv);
		ans += e.w;
		
		cnt++;
		if (cnt >= n2-1) {
			break;
		}
	}
	
	return ans;
}

void dfs(int idx, ll s, int n2) {
	if (idx > k) {
		ll a1 = kruskal(n2);
		ans = min(ans, s + a1);
//		cerr << "upd by " << s << " + " << a1 << "\n";
		return;
	}
	
	dfs(idx+1, s, n2);
	
//	cerr << idx << ":\n";
	for (int i=1; i<=n; i++) {
		G1.push_back({n+idx, i, a[idx][i]});
	}
	dfs(idx+1, s+c[idx], n2+1);
	for (int i=1; i<=n; i++) {
		G1.pop_back();
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++) {
		int u, v, w; cin >> u >> v >> w;
		G.push_back(edge{u, v, w});
	}
	for (int i=1; i<=k; i++) {
		cin >> c[i];
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}
	
	sort(G.begin(), G.end());
	dsu_init();
	ans = 0; int cnt=0;
	for (auto e: G) {
		int u=e.u, v=e.v;
		int fu=find(u), fv=find(v);
		if (fu == fv) {
			continue;
		}
		
		join(fu, fv);
		ans += e.w;
		G1.push_back(e);
//		cerr << u << "---" << v << "\n";
		
		cnt++;
		if (cnt >= n-1) {
			break;
		}
	}
	
	dfs(1, 0, n);
	
	cout << ans;
	
	return 0;
}

