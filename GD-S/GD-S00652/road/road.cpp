#include <bits/stdc++.h>
using namespace std;

const int N = 10000, M = 1000000, K = 10;

struct Edge {
	int u, v; long long w;
};

int n, m, k;
int len1, len2, cnt = 0;
Edge e[M + 10], tmp[N + 10];
long long c[K + 2], a[K + 2][N + 10];

int fa[N + K + 10], sz[N + K + 10];
long long ans = 0ll;

Edge g[35][N + K + 10], h[N + K + 10];
long long sum_c1[35]; int g_cnt[35];

bool cmp(Edge u, Edge v) {
	return u.w < v.w;
}

int find(int u) {
	if(fa[u] != u) fa[u] = find(fa[u]);
	return fa[u];
}

bool merge(int u, int v) {
	u = find(u); v = find(v);
	if(u == v) return false;
	if(sz[u] < sz[v]) swap(u, v);
	fa[v] = u; sz[u] += sz[v];
	return true;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for(int i = 1; i <= k; ++i) {
		cin >> c[i];
		for(int j = 1; j <= n; ++j) cin >> a[i][j];
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; ++i) {
		fa[i] = i; sz[i] = 1;
	}
	for(int i = 1; i <= m; ++i) {
		if(merge(e[i].u, e[i].v)) {
			tmp[++cnt] = e[i]; ans += e[i].w;
		}
	}
	for(int i = 1; i < n; ++i) e[i] = tmp[i];
	len1 = k / 2; len2 = k / 2 + 1;
	for(int i = 0; i < (1 << len1); ++i) {
		cnt = n - 1;
		for(int j = 1; j <= len1; ++j) {
			if((i >> (j - 1)) & 1) {
				for(int x = 1; x <= n; ++x) {
					e[++cnt] = (Edge){j + n, x, a[j][x]};
				}
				sum_c1[i] += c[j];
			}
		}
		sort(e + 1, e + cnt + 1, cmp);
		for(int i = 1; i <= n + k; ++i) {
			fa[i] = i; sz[i] = 1;
		}
		for(int j = 1; j <= cnt; ++j) {
			if(merge(e[j].u, e[j].v)) {
				g[i][++g_cnt[i]] = e[j];
			}
		}
		for(int j = 1; j < n; ++j) e[j] = tmp[j];
	}
	for(int i = 0; i < (1 << len2); ++i) {
		cnt = n - 1;
		int h_cnt = 0; long long sum_c2 = 0ll;
		for(int j = len1 + 1; j <= k; ++j) {
			if((i >> (j - len1 - 1)) & 1) {
				for(int x = 1; x <= n; ++x) {
					e[++cnt] = (Edge){j + n, x, a[j][x]};
				}
				sum_c2 += c[j];
			}
		}
		sort(e + 1, e + cnt + 1, cmp);
		for(int i = 1; i <= n + k; ++i) {
			fa[i] = i; sz[i] = 1;
		}
		for(int j = 1; j <= cnt; ++j) {
			if(merge(e[j].u, e[j].v)) {
				h[++h_cnt] = e[j];
			}
		}
		for(int j = 1; j < n; ++j) e[j] = tmp[j];
		for(int j = 0; j < (1 << len1); ++j) {
			long long sum = sum_c1[j] + sum_c2;
			if(sum > ans) continue;
			for(int x = 1; x <= n + k; ++x) {
				fa[x] = x; sz[x] = 1;
			}
			int l = 1, r = 1;
			while(l <= g_cnt[j] && r <= h_cnt) {
				if(g[j][l].w <= h[r].w) {
					if(merge(g[j][l].u, g[j][l].v)) sum += g[j][l].w;
					++l;
				}
				else {
					if(merge(h[r].u, h[r].v)) sum += h[r].w;
					++r;
				}
			}
			while(l <= g_cnt[j]) {
				if(merge(g[j][l].u, g[j][l].v)) sum += g[j][l].w;
				++l;
			}
			while(r <= h_cnt) {
				if(merge(h[r].u, h[r].v)) sum += h[r].w;
				++r;
			}
			ans = min(ans, sum);
		}
	}
	cout << ans;
	return 0;
} 
