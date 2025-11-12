#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k , a[10020][10020] , u , v , w , b[10020]; 
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}
	int xf;
	for (int i = 1 ; i <= k ; i++)
	{
		cin >> xf;
		for (int j = 1 ; j <= n ; j++)
		{
			cin >> b[i];
		}
		for (int j = 1 ; j <= n ; j++)
		{
			for (int l = j + 1 ; l <= n ; l++)
			{
				a[i][j] = min(a[i][j] , xf + b[i] + b[j]);
				a[j][i] = a[i][j];
			}
		}// 建图，权重为两地之间的最小权重 
	}
	int ans = 0 , mi = 1000000001;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = i + 1 ; j <= n ; j++)
		{
			mi = min(mi , a[i][j]);
		}
		ans += mi;
	}
	cout << ans;
	return 0;
}
