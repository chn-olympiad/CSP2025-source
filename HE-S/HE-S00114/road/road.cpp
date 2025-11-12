#include<iostream>
#include<vector>
#include<map>
using namespace std;
const int N = 1e3+5;
int n,m,l;
int v[N][N];
int c[15][N];
int g[15];
int vis[N][N];
int ans = 1e9;

void dfs(int sum,int num)
{
	if(num == n-1)
	{
		ans = min(ans,sum);
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!vis[i][j])
			{
				
				vis[i][j]=1;
				vis[j][i]=1;
				dfs(sum+=v[i][j],num+1);
				vis[i][j]=0;
				vis[j][i]=0;
			}
		}
	}
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int u,x,w;
	cin>>n>>m>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>x>>w;
		v[u][x]=w;
		v[x][u]=w;
	}
	for(int i=1;i<=l;i++)
	{
		cin>>g[i];
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			c[j][i]=w;
			c[i][j]=w;
		}
	}
	
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(v[k][i]!=0 && v[k][j]!=0)
				{
					if(v[i][j]!=0)
					{
						v[i][j] = min(v[i][j],v[i][k] + v[k][j]);
						v[j][i] = v[i][j];
					}
					else
					{
						v[i][j]=v[j][i]=v[i][k]+v[k][i];
					}
				}
			}
		}
	}
	
	for(int k=1;k<=l;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(v[i][j] != 0)
				{
					v[i][j] = min(v[i][j],c[i][k]+c[k][j]);
					v[j][i] = v[i][j];
				}
				else
				{
					v[i][j]=v[j][i]=c[i][k]+c[k][i];
				}
			}
		}
	}
	
	
	dfs(0,0);
	
	cout<<ans;
	return 0;
	//Ren5Jie4Di4Ling5%
}
