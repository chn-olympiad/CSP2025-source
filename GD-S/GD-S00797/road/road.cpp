#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,z,f[10005][10005],sum;
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (long long i = 1;i<=m;i++)
	{
		cin>>x>>y>>z;
		if (f[x][y])
		{
			f[x][y] = min(f[x][y],z);
			f[y][x] = f[x][y];
		}
		else if (f[y][x])
		{
			f[y][x] = min(f[y][x],z);
			f[x][y] = f[y][x];
		}
		if (!f[x][y])
		{
			f[x][y] = z;
			f[y][x] = z;
		}
	}
	for (long long i = 1;i<=k;i++)
	{
		for (long long j = 1;j<=n;j++)
		{
			cin>>x;
		}
	}
	for (long long i = 1;i<=n;i++)
	{
		for (long long j = i + 1;j<=n;j++)
		{
			sum += f[i][j];
		}
	}
	cout<<sum<<endl;
	return 0;	
} 
