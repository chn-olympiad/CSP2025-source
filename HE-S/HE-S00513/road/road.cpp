#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z;
int long long ans,c[15],a[10005][10005],f[10005][10005];
struct s{
	int u,v,w;
}d[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		f[x][y]=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	{
		for(int k=1;k<=n;k++)
	{
		f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
	}
	}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
	{
		ans+=f[i][j];
	}
	}
	cout<<ans<<endl;
	return 0;
}
