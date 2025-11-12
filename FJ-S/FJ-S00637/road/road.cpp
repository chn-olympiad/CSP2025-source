#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define Pli pair<ll, int>
#define pb emplace_back

const int N = 1e4 + 7, M = 2e7 + 7;
int n, m, K, vis[N]; ll c[N], ans;

struct E {
	int v, nxt; ll w;
} edge[M];
int head[N], sz;
inline void add(int u, int v, ll w) {
	edge[++sz] = {v, head[u], w}, head[u] = sz;
}

priority_queue<Pli, vector<Pli>, greater<Pli>> q;
void Kruskal() {
	q.push({0, 1}); int cnt = 0;
	for (int u; cnt < n; ) {
		while (vis[q.top().second]) q.pop();
		ans += q.top().first; u = q.top().second; q.pop();
		if (vis[u]) continue; cnt++, vis[u] = true;
		for (int i = head[u], v; i; i = edge[i].nxt)
			if (!vis[v = edge[i].v]) q.push({edge[i].w, v});
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m >> K;
	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, add(u, v, w), add(v, u, w);
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= n; j++) cin >> c[j];
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (j != k) add(j, k, c[j] + c[0] + c[k]);
	}
	Kruskal();
	cout << ans;
}
