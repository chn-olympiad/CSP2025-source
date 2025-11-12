#include<bits/stdc++.h>
using namespace std;
int a[11111][11111];
int n,m,k,ans=9999999;
int v[11111][11111],vv[11111];
void dfs(int i,int d,int t)
{
	int o=t;
	if(t==n)
	{
		ans=min(d,ans);
	}
	if(d>=ans) return;
	for(int j=1;j<=n+k;j++)
	{
		if(a[i][j])
		{
			if(vv[j]==0&&j<=n) o++;
			if(v[i][j]==0)
			{
				v[i][j]=1;
				v[j][i]=1;
				vv[j]=1;
				dfs(j,d+a[i][j]-1,o);
				v[i][j]=0;
				v[j][i]=0;
				vv[j]=0;
			}
			else
			{
				dfs(j,d,o);
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z+1;
		a[y][x]=z+1;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			int b;
			cin>>b;
			a[n+i][j]=c+b+1;
			a[j][n+i]=c+b+1;
		}
	}
	vv[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
