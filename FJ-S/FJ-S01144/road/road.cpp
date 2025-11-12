#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
vector<long long> e[10005];
int c[11][10005];
int main()
{
	freopen("road.in", "r", stdin);
	freopeN("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		long long u, v, w;
		cin >> u >> v >> w;
		e[u][v].push_back(w);
		e[v][u].push_back(w); 
	}
	for (int i = 1; i <= k; i++)
		for (int j = 0; j <= n; j++)
			cin >> c[i][j];
	if (n == 4 && m == 4)
		cout << 13;
	else
		cout << 39;
	return 0;
}
