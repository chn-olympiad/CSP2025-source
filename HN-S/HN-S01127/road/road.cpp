#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
int city[N][N],a[N][N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w".,stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		city[u][v] = w;
		city[v][u] = w;
	}
	//特殊性质A  题目什么意思？！ 
	for(int i = 1; i <= k; i++)
	{
		int c;
		cin >> c;
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		} 
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j) city[i][j] = 0;
			else if(city[i][j] != 0) city[i][j] = min(city[i][j],a[i][j]);
			else city[i][j] = a[i][j];
			ans += city[i][j]; 
		}
	}
	cout << ans / 2 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
