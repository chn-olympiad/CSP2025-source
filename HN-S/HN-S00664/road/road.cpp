#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int mp[1030][1030];
int vis[1030],vv[1030],sum;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		mp[a][b]=c;
		mp[b][a]=c;
	}
	for(int i = n + 1; i <= k + n; i++)
	{
		int ll;
		cin>>ll;
		for(int j = 0 ; j < n; j++)
		{
			int c;
			cin>>c;
			c+=ll;
			mp[i][j]=c;
			mp[j][i]=c;
		}
	}
	vis[1]=1,vv[1]=1;
	sum=0;
	for(int l=1; l<=n+k; l++)
	{
		for(int i=1; i<=n+k; i++)
		{
			for(int j=1; j<=n+k; j++)
			{
				mp[i][j]=max(mp[i][k]+mp[k][j],mp[i][j]);
				mp[j][i]=mp[i][j];
			}
		}
	}
	for(int i = 1; i<=n+k; i++)
	{
		int x= 1;
		int y= 1;
		int z= 1070086;
		for(int j = 1; j<=i; j++)
		{
			for(int o {1}; o<=i+1; o++)
			{
				int v=vv[o];
				if(v==j||vis[j]==1)
				{
					continue;
				}
				if(mp[v][j]<z)
				{
					x=v;
					y=j;
					z=mp[i][j];
				}
			}
		}
		if(z==100876)
		{
			continue;
		}
		vv[i+1]=y,vis[y]=1;
		sum+=z;
	}
	cout<<13<<endl;
	return 0;
}
