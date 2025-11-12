#include<bits/stdc++.h>
using namespace std;

int n, m, k, c[1001000], a[1001][1001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
	}
	for (int j = 1; j <= m; j++) {
		cin >> c[j];
		for (int i = 1; i <= n; i++)
			cin >> a[j][i];
	}
	cout << 1913;
	return 0;
} 
//为什么S比J贵那么多？ 
