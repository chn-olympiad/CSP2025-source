#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n >> m >> k;
	int g[n][n], vis[n][n], a[k][n], c[k];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = 0; vis[i][j] = 0;
		}
	}
	memset(g + 1, sizeof(g), 0);
	memset(vis + 1, sizeof(vis), 0);
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) cout << g[i][j] << " ";
//		cout << endl;
//	}
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w; g[v][u] = w;
	}
	cout << endl;
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	queue<int> q;
	q.push(0);
	int flag = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 0; i < n; i++) {
			if(vis[t][i] == 0) {
				int cost1 = 0x3f3f3f3f;
				//case1
				if(g[t][i] != 0) cost1 = g[t][i];
				//case2
				for(int j = 0; j < k; j++) {
					cost1 = min(cost1, c[j] + a[j][i] + a[j][t]);
					c[j] = 0;
					a[j][t] = 0;
				}
				ans += cost1;
				q.push(i);
				//cout << cost2 << endl;
				vis[t][i] = 1;  vis[i][t] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}
