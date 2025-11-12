// [64,100] pts
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int kMaxN = 2e4 + 5, kMaxM = 1.1e6 + 5;

struct Edge {
	int to, w;
};

struct Node {
	int u, v, w;
	bool operator<(Node nd) const {
		return w < nd.w;
	}
} e[kMaxM], e2[kMaxM];

int n, m, k, tot, tot2, ans = 1e18, subA = 1, a[15][kMaxN], c[kMaxN], fa[kMaxN], sz[kMaxN];

int find(int u) {
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	if(sz[u] < sz[v]) swap(u, v);
	fa[v] = u, sz[u] += sz[v], sz[v] = 0;
}

void run(int S, Node e[], int tot) {
	for(int i = 1; i <= n + k; i++) fa[i] = i, sz[i] = 1;
	int cnt = 0, res = 0;
	int lim = n + __builtin_popcount(S) - 1;
	for(int i = 1; i <= tot; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(u > n && !(S >> (u - n - 1) & 1)) continue;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		merge(fu, fv);
		++cnt;
		res += w;
	//	cout << u << ' ' << v << ' ' << w << '\n';
		if(cnt == lim) break;
	}
	for(int i = 1; i <= k; i++) {
		if(S >> (i - 1) & 1) res += c[i];
	}
	//	cout << S << ' ' << res << '\n';
	ans = min(ans, res);
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[i].u = u, e[i].v = v, e[i].w = w;
	}
	tot = m;
	for(int j = 1; j <= k; j++) {
		cin >> c[j];
		subA &= (c[j] == 0);
		int ok = 0;
		for(int i = 1; i <= n; i++) {
			cin >> a[j][i];
			ok |= (a[j][i] == 0);
			e[++tot] = (Node){n + j, i, a[j][i]};
			e2[++tot2] = (Node){n + j, i, a[j][i]};
		}
	}
	sort(e + 1, e + tot + 1);
	if(!subA) {
		if(k <= 5) {
			for(int S = 0; S < (1 << k); S++) {
				run(S, e, tot);
			}
		} else {
			for(int i = 1; i <= n; i++) {
				fa[i] = i, sz[i] = 0;
			}
			for(int i = 1; i <= tot; i++) {
				int u = e[i].u, v = e[i].v;
				if(u > n) continue;
				int fu = find(u), fv = find(v);
				if(fu == fv) continue;
				merge(fu, fv);
				e2[++tot2] = e[i];
			}
			sort(e2 + 1, e2 + tot2 + 1);
			for(int S = 0; S < (1 << k); S++) {
				run(S, e2, tot2);
			}
		}
	} else {
		for(int S = (1 << k) - 1; S < (1 << k); S++) {
			run(S, e, tot);
		}
	}
	cout << ans << '\n';
	return 0;
} 
