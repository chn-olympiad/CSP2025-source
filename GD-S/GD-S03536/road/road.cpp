#define ffopen(s) \
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); \
if (*#s) freopen(#s ".in", "r", stdin); \
if (*#s) freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
#define chkmax(x, y) ((x)=max((x),(y)))
#define chkmin(x, y) ((x)=min((x),(y)))
using namespace std;
using intl = long long;
using pii = pair<int, int>;
using trii = tuple<int, int, int>;
const intl N = 10000, M = 1000000, K = 10, inf_int = 0x3f3f3f3f;
int n, m, k, c[K + 10], a[K + 10][N + 10];
vector<pii> g[N + K + 10];
int dis[N + K + 10], ne;
trii edg[N + 10];
intl prim(int s, bool isreb) {
	memset(dis, 0x3f, sizeof dis);
	priority_queue<trii, vector<trii>, greater<trii> > que;
	dis[s] = 0, que.emplace(dis[s], s, 0);
	while (!que.empty()) {
		int u, p, d;
		tie(d, u, p) = que.top(); que.pop();
		if (d > dis[u]) continue;
		dis[u] = d;
		if (isreb) edg[++ne] = {u, p, d};
		for (pii e : g[u]) {
			int v, w; tie(v, w) = e;
			if (dis[v] == inf_int) {
				que.emplace(w, v, u);
			}
		}
	}
	intl res = 0;
	for (int i = 1; i <= n + k; i++) {
		if (dis[i] != inf_int) res += dis[i];
	}
	return res;
}
void slove() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	intl ans = prim(1, true);
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1; i <= ne; i++) {
		int u, v, w; tie(u, v, w) = edg[i];
		if (!u || !v) continue;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	int ALL = (1 << k) - 1;
	for (int S = 1; S <= ALL; S++) {
		intl cur = 0;
		for (int i = 1; i <= k; i++) {
			if ((~S) >> (i - 1) & 1) continue;
			cur += c[i];
			for (int j = 1; j <= n; j++) {
				g[i + n].emplace_back(j, a[i][j]);
				g[j].emplace_back(i + n, a[i][j]);
			}
		}
		cur += prim(1, false);
		chkmin(ans, cur);
		for (int i = 1; i <= k; i++) {
			if ((~S) >> (i - 1) & 1) continue;
			g[i + n].clear();
			for (int j = 1; j <= n; j++) g[j].pop_back();
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	slove();
	return 0;
}

