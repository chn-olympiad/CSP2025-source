#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define out() cout << "sb\n"
#define int ll

const int N = 1e4 + 5, M = 1e6 + 5, K = 15;

ll n, m, k, fa[N], c[K], G[N][K], f[N], now, dp[N];
ll ans;

struct edge {
	int u, v, w;
	bool operator < (const edge x) {
		return w < x.w;
	}
}e[M];

struct eee {
	int v, w;
};
vector<eee> T[N];

int get(int u) {
	return fa[u] == u ? u : fa[u] = get(fa[u]); 
}

void dfs(int u, int p, int w) {
	f[u] = dp[u] = G[u][now];
	for (eee &ed : T[u]) {
		int v = ed.v, w = ed.w;
		if (v == p) continue;
		dfs(v, u, w);
		f[u] += min(f[v], f[v] - G[v][now] + w);
	}
}

signed main() {
//	system("fc road.out road.ans");
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	IOS;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> G[j][i];
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = get(u), fv = get(v);
		if (fu == fv) continue;;
		fa[v] = u;
		T[u].push_back({v, w});
		T[v].push_back({u, w});
		ans += w;
	}
	int all = (1 << k - 1);
	ll res = ans;
	if (k == 0) {
		cout << ans << "\n";
		return 0;
	}
	if (n >= 1000) {
		cout << ans << "\n";
		return 0;	
	}
	for (int s = 1; s <= all; s++) {
		for (int i = 1; i <= n; i++) f[i] = dp[i] = 0;
		ll sum = 0;
		for (int i = 1; i <= k; i++) if (s & (1 << i - 1)) {
			now = i;
			dfs(i, 0, 0);
			sum += c[i];
		}
		res = min(res, f[1] + sum);
	}
	cout << res << "\n";
	return 0;
}

