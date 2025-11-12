#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace aaaaaa{
	const int N = 1e4 + 5;
	const int M = 1e6 + 5;
	
	struct Node {
		int to;
		int val;
	};
	
	int n, m, k;
	vector <Node> graph[M];
	int c[15];
	int a[15][N];
	
	queue <int> q;
	bool vist[M];
	int dist[N][N];
	void SPFA(int start) {
		for (int i = 1; i < N; ++ i)
			dist[start][i] = INT_MAX;
		
		q.push(start);
		vist[start] = true;
		dist[start][start] = 0;
		
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			vist[now] = false;
			
			for (Node it : graph[now]) {
				if (dist[start][it.to] > dist[start][now] + it.val && !vist[it.to]) {
					cout << it.val << ' ' << it.to << '\n';
					dist[start][it.to] = dist[start][now] + it.val;
					q.push(it.to);
					vist[it.to] = true;
					cout << dist[start][it.to] << '\n';
				}
			}
		}
	}
	
	signed main() {
		freopen("road.in", "r", stdin);
		freopen("road.out", "w", stdout);
		
		cin >> n >> m >> k;
		for (int i = 1; i <= m; ++ i) {
			int u, v, w;
			cin >> u >> v >> w;
			
			graph[u].push_back({v, w});
			graph[v].push_back({u, w});
		}
		bool flag_a = true;
		for (int i = 1; i <= k; ++ i) {
			cin >> c[i];
			if (c[i])
				flag_a = false;
			for (int j = 1; j <= n; ++ j) {
				cin >> a[j][i];
				if (a[j][i])
					flag_a = false;
			}
		}
		
		if (flag_a) {
			cout << 0;
			return 0;
		}
		
		for (int i = 1; i <= n; ++ i)
			SPFA(i);
		
		int mn = INT_MAX;
		for (int i = 1; i <= n; ++ i) {
			int sum = 0;
			for (int j = 1; j <= n; ++ j) {
				sum += dist[i][j];
			}
			mn = min(mn, sum);
		}
		
		cout << mn;
		
		return 0;
	}
}

signed main() {
	aaaaaa::main();
	
	return 0;
}
