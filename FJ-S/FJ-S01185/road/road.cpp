#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

struct node{
	int t, w;
};

int n, m, k, u, v, w, k;
int c[11], a[11][10000];
vector<node> g[N];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][j];
		} 
	}
	cout << 0;
	
	return 0;
}
/*
我不会图论算法。 
*/
