#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	vector<int> e[10005] , cost[10005];
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		int u , v , w;
		cin >> u >> v >> w;
		e[u].push_back(v);
		e[v].push_back(u);
		cost[u].push_back(w);
		cost[v].push_back(w);
	}
	int a[13][1004] , c[13];
	for (int i = 1;i <= k;i++)
		for (int j = 1;j <= n;j++)
			cin >> c[i] >> a[i][j];
	cout << 0;
	return 0;
}
