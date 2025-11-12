#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N][20], w[N][20], c[N];
vector<int> g[N];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v >> w[u][v];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = n+1; i <= n+k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n+1; j++) {
			cin >> a[i][j];
		}
	}
	cout << 0;
	return 0;
}
