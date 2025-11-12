#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node {
	int p, v; // p position v value
};

struct node2 {
	int p, v, w;
};

bool operator> (node2 x, node2 y) {
	return x.v > y.v;
}

bool operator< (node2 x, node2 y) {
	return x.v < y.v;
}

const int MAXN = 1e4 + 5, MAXK = 10 + 5;
vector <node> g[MAXN];
int a[MAXK][MAXN], c[MAXK], dis[MAXN];
bool vis[MAXN];

void make_pic(int u, int v, int w) {
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}

int dijkstra(int s) {
	priority_queue < node2, vector <node2>, greater <node2> > pq;
	pq.push({s, 0, 0});
	dis[s] = 0;
	int ans = 0;
	while (!pq.empty()) {
		int tp = pq.top().p, tv = pq.top().v, tw = pq.top().w;
		pq.pop();
		for (int i = 0; i < g[tp].size(); i++) {
			int gtp = g[tp][i].p, gtv = g[tp][i].v;
			if (gtv + tv < dis[gtp]) {
				dis[gtp] = gtv + tv;
				ans = ans + g[tp][i].v - 
				pq.push({gtp, dis[gtp], });
			}
		}
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		make_pic(u, v, w);
	}
	bool flaga = true; // A
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i] != 0) flaga = false;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	if (flaga) {
		for (int id = 1; id <= k; id++) {
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					make_pic(i, j, a[id][i] + a[id][j]);
					make_pic(j, i, a[id][i] + a[id][j]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			dis[i] = INT_MAX;
		}
		dijkstra(1);
		for (int i = 1; i <= n; i++) {
			cout << dis[i] << " ";
		}
	}
	return 0;
}
