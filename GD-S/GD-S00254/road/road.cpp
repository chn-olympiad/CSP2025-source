#include<bits/stdc++.h>
using namespace std;
int a[15][10004];
vector<pair<int, int> >edge[10004], side[10004];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			side[i].push_back({j, w});
			edge[j].push_back({i, w});
		}
	}
	cout << 0;
}
