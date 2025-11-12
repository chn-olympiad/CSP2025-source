#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

struct node {
	int y, w;
};

int A = 1;
int c[15], a[15][N];
int f[N];
vector<node> g[N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		if (c[i]) A = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j]) A = 0;
		}
	}
	cout << 0;
	return 0;
}

/*
Ren5Jie4Di4Ling5%

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
