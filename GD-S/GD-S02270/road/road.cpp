#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int ans = 0;
	int graph[n+1][n+1] = {};
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin >> x >> y >> z;
		graph[x][y] = 1;
		graph[y][x] = 1;
		ans += z;
	}
	int a[k][n+1] = {};
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}
