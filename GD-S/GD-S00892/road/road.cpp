#include <bits/stdc++.h> 
//#define ONLINE_JUDGE
#define FILENAME "road"

typedef long long ll;
const int N = 1e4 + 105, M = 1e6 + 105;
int n, m, k, cnt;
struct Edge {
	int u, v;
	ll w;
	bool operator<(const Edge &o) const {
		return w < o.w;
	}
} e[M * 10], a[20][N];
ll c[20];
//ll a[20][N];
int fa[N];
int used[25], p[25], len[25];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void chmin(int &pp, int i) {
	while (p[i] <= len[used[i]]) {
		int fu = find(a[used[i]][p[i]].u), fv = find(a[used[i]][p[i]].v);
		if (fu != fv) break;
		++p[i];
	}
	if (p[i] > len[used[i]]) return;
	if (pp == -1 || a[used[i]][p[i]].w < a[used[pp]][p[pp]].w) {
		pp = i;
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
#endif
	
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(0);
	
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; ++i) {
		std::cin >> c[i];
		for (int u = 1; u <= n; ++u) {
			std::cin >> a[i][u].w;
			a[i][u].u = i + n;
			a[i][u].v = u;
		}
		std::sort(a[i] + 1, a[i] + 1 + n);
		len[i] = n;
	}
	
	// First Kruskal
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	std::sort(e + 1, e + 1 + m);
	ll ans = 0, res = 1e18;
	for (int i = 1; i <= m; ++i) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu == fv) continue;
		a[0][++cnt] = e[i];
		fa[fu] = fv;
		ans += e[i].w;
		if (cnt == n - 1) break;
	}
	res = ans;
	len[0] = n - 1;
	
	// Now only n - 1 edges
	
	ll tmp = 0;
	//for (int i = 1; i < (1 << k); ++i) {
	for (int i = 1; i < (1 << k); ++i) {
//		break;
		tmp = 0;
		cnt = n - 1;
		int now = n, ucnt = 0;
		p[0] = 1;
		for (int j = i; j; j ^= (j & -j)) {
			++now;
			int t = __builtin_ctz(j) + 1;
			tmp += c[t];
			used[++ucnt] = t;
			p[ucnt] = 1;
		}
		
		for (int j = 1; j <= n + k; ++j) fa[j] = j;
		for (int j = 1; j < now; ++j) {
			int pos = -1;
			for (int u = 0; u <= ucnt; ++u) chmin(pos, u);
			int fu = find(a[used[pos]][p[pos]].u), fv = find(a[used[pos]][p[pos]].v);
			fa[fu] = fv;
			ll w = a[used[pos]][p[pos]++].w;
			tmp += w;
		}
		res = std::min(res, tmp);
	}
	std::cout << res << '\n';
	
	return 0;
}

