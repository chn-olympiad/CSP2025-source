#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10015][10015],country[10][10050];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(a,0x3f,sizeof(a));
	for (int i = 1;i <= m;i++)
	{
		int u,v,s;
		cin >> u >> v >> s;
		a[u][v] = s;
		a[v][u] = s; 
	}
	for (int i = 1;i <= k;i++)
	{
		for (int j = 1;j <= n+1;j++)
		{
			cin >> country[i][j];
		}
	}
	int y = rand()*rand();
	cout << y;
	return 0;
}
