#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int inf = 0x3f;
int n, m, k, a[5005][5005], dist[N], vis[N], graph[7005][7005], ans, val[N], pos[N];
struct node {
	int u, v, w;
}e[N];
void dij(int v) {
	memset(dist, inf, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	dist[v] = 0;
	int minn, k;
	for (int i = 1; i <= n; i ++) {
		minn = inf, k = -1;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && minn > dist[j]) {
				minn = dist[j];
				k = j;
			}
		}
		ans += dist[k];
		vis[k] = 1;
		for (int j = 1; j <= n; j ++) {
			if (!vis[j] && dist[j] > graph[k][j] && graph[k][j] != inf) {
				dist[j] = graph[k][j];
			}
			if (!vis[j]) {
				for (int q = 1; q <= k; q ++) {
					if (!pos[q + n] && !vis[j] && dist[j] > graph[k][q + n] + graph[q + n][j] + val[q + n] && graph[q + n][j] != inf && graph[k][q + n] != inf) {
						dist[j] = graph[k][q + n] + graph[q + n][j];
						pos[q + n] = 1;
					}
					else if (pos[q + n] && !vis[j] && dist[j] > graph[k][q + n] + graph[q + n][j] && graph[q + n][j] != inf && graph[k][q + n] != inf) {
						dist[j] = graph[k][q + n] + graph[q + n][j];
					}
				}
			}
		}
	}
	for (int i = 1; i <= k; i ++) {
		if (pos[i + n] == 1) {
			ans ++;
		}
	}
	cout << ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	memset(graph, inf, sizeof(graph));
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		graph[e[i].u][e[i].v] = min(graph[e[i].u][e[i].v], e[i].w);//任意两座原有的城市都能通过若干条原有的道路相互到达
		graph[e[i].v][e[i].u] = min(graph[e[i].v][e[i].u], e[i].w);
	}
	for (int i = 1; i <= k; i ++) {
		cin >> val[i + n];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i + n][j];
			graph[i + n][j] = min(graph[i + n][j], a[i + n][j]);
			graph[j][i + n] = min(graph[j][i + n], a[i + n][j]);
		}
	}
	dij(1);
	return 0;
}
