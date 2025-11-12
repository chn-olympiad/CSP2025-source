#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<pair<int, int> > g[100006];
int c[15], a[15][10004]; 
int main() {
	cin >> n >> m >> k;
	
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		
		g[u].push_back({v, w});
		g[v].push_back({w, w});
	} 
	
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	if (k == 0) {
		
	}
}
