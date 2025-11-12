#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ls(p) p << 1
#define rs(p) p << 1 | 1

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int K = 12;
const int P = 1e9 + 7;
const int INF = 1e18;

struct Edge {int u, v, w;};
int n, m, k, c[K], a[K][N];
int fa[N];
ll ans = INF;
Edge e[M];
Edge G[M + N];

int Find (int p) {
	if (fa[p] == p) return p;
	return fa[p] = Find(fa[p]);
}

inline void merge (int u, int v) {
	u = Find(u); v = Find(v);
	if (u == v) return ;
	fa[u] = v;
}

inline void init () {
	for (int i = 1; i <= n + k; i++) fa[i] = i;
}

bool cmp (Edge x, Edge y) {
	return x.w < y.w;
}

void solve1 () {
	for (int s = 0; s < (1 << k); s++) {
		bool flag = true;
		for (int i = 1; i <= m; i++) G[i] = e[i];
		init();
		ll sum = 0; int cnt = m;
		for (int i = 1; i <= k; i++) {
			if (!((s >> (i - 1)) & 1)) continue;
			sum += c[i];
			if (sum > ans) {
				flag = false;
				break;
			}
			for (int j = 1; j <= n; j++) 
				G[++cnt] = {n + i, j, a[i][j]};
		}
		if (!flag) continue;
		sort (G + 1, G + cnt + 1, cmp);
		for (int i = 1; i <= cnt; i++) {
			Edge t = G[i];
			int u = t.u, v = t.v, w = t.w;
			if (Find(u) == Find(v)) continue;
//			if (fa[u] == fa[v]) continue;
			sum += w;
			if (sum > ans) {
				flag = false;
				break;
			}
			merge (u, v);
		}
		if (!flag) continue;
		ans = min (ans, sum);
	}
	cout << ans;
}

bool check () {
	for (int i = 1; i <= k; i++)
		if (c[i] != 0) return false;
	return true;
}

void solve0 () {
	int cnt = m; ans = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			e[++cnt] = {n + i, j, a[i][j]};
		}
	}
	sort (e + 1, e + cnt + 1, cmp);
	init();
	for (int i = 1; i <= cnt; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (Find(u) == Find(v)) continue;
		merge(u, v); ans += w;
	}
	cout << ans;
}

void solve () {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	if (check()) solve0();
	else solve1();
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; // cin >> T;
	while (T--) solve ();
	return 0;
}