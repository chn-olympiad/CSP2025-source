#include<bits/stdc++.h>
using namespace std;

int mp[1010][1010];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = w;
		mp[v][u] = w;
	}
	cout << n - m << endl;
	return 0;
}
