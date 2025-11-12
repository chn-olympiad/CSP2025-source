# include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_n = 1e4 + 10 + 10;
const int max_m = 1e6 + 10 * max_n + 10;

bool del[max_n];
int n, m;
int k;
int cnt;
int fa[max_n];
int edge_c[max_m];
int used[max_n];
ll ans = LLONG_MAX;
ll c[max_n];

struct Edge {
	int u, v;
	ll w;
	bool operator < (const Edge &t) const {
		return w < t.w;
	}
} edge[max_m];

int Find(int x) {
	if (fa[x] ^ x) {
		fa[x] = Find(fa[x]);
	}
	return fa[x];
}

ll Kruskal() {
	for (int i = 1; i <= n + k; i ++) {
		fa[i] = i;
	}
	ll ret = 0ll;
	cnt = 0;
	memset(used, 0, sizeof used);
	for (int i = 1; i <= m; i ++) {
		int u = edge[i].u, v = edge[i].v;
		if (!del[u] && !del[v]) {
			int fa_u = Find(u), fa_v = Find(v);
			if (fa_u ^ fa_v) {
				fa[fa_u] = fa_v;
				ret += edge[i].w;
				if (u > n) {
					edge_c[++ cnt] = i;
					used[u] ++;
				}
				if (v > n) {
					edge_c[++ cnt] = i;
					used[v] ++;
				}
			}
		}
	}
	return ret;
}

void DFS(int x) {
	if (x > k) {
		ll t = 0ll;
		for (int i = n + 1; i <= n + k; i ++) {
			if (!del[i]) {
				t += c[i];
			}
		}
		t += Kruskal();
		for (int i = 1; i <= cnt; i ++) {
			int u = edge[edge_c[i]].u, v = edge[edge_c[i]].v;
			ll w = edge[edge_c[i]].w;
			if (used[u] == 1) {
				t -= c[u] + w;
			}
			if (used[v] == 1) {
				t -= c[v] + w;
			}
		}
		ans = min(ans, t);
	}
	else {
		del[n + x] = 1;
		DFS(x + 1);
		del[n + x] = 0;
		DFS(x + 1);
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %lld", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	for (int i = n + 1; i <= n + k; i ++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j ++) {
			ll a;
			scanf("%lld", &a);
			edge[++ m] = {i, j, a};
		}
	}
	sort(edge + 1, edge + m + 1);
	DFS(1);
	printf("%lld", ans);
	return 0;
}