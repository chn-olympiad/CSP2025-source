#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e4 + 10;
int diet[N], vis[N];

struct node {
	int u;
	LL w;
};
vector<node> g[N];

struct node2 {
	int v, w;
	bool operator < (const node2 &x) const {
		return x.w > w;
	}
};

priority_queue<node2> q;

void dijk(int s) {
	vis[s] = 1;
	q.push({s, 0});
	while(!q.empty()) {
		node2 tmp = q.top();
		int x = tmp.v;
		if(vis[x] == 1) continue;
		vis[x] = 1;
		for (int i = 0;i < g[x].size();i++) {
			int y = g[x][i].u;
			int z = g[x][i].w;
			if(diet[y] > diet[x] + z) {
				diet[y] = diet[x] + z;
			}
			if(!vis[x]) {
				q.push({y, diet[y]});
			}
		}
	}
}

int main () {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) {
		int u, v;
		LL w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1;i <= k;i++) {
		int u = n + i, w;
		cin >> w;
		for (int j = 1;j <= n;j++) {
			g[u].push_back({j, w});
			g[j].push_back({u, w});
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		memset(diet, -0x3f3f3f3f, sizeof(diet));
		memset(vis, 0, sizeof(vis));
		dijk(i);
		ans += diet[i + 1];
	}
	cout << ans << endl;
	
	return 0;
}
