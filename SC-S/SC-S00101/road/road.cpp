#include<bits/stdc++.h>
using namespace std;
int c[15];
int a[15][10010];
int minx[1000010];
int du[10010];
int num[1000010];
int g[1000010];
vector<int> mp[1000010];
void add(int u1,int v1,int w1)
{
	mp[u1].push_back(v1);
	mp[u1][v1]=w1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u,v,w;
	int ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		num[w]=1;
		g[w]++;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int ij=1;ij<=k;ij++)
			{
				if(mp[i][j]>a[ij][i]+a[ij][j])
				{
					if(g[mp[i][j]]==1)
					{
						num[mp[i][j]]=0;
					}
					g[mp[i][j]]--;
					num[a[ij][i]+a[ij][j]]=1;
					g[a[ij][i]+a[ij][j]]++;
				} 
				mp[i][j]=min(mp[i][j],a[ij][i]+a[ij][j]);
				mp[j][i]=mp[i][j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int j=0;
		if(num[i]!=0)
		{
			j++;
			minx[j]=i;
		}
	}
	int cnt=0;
	int p=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g[minx[p]]==0)
			{
				p++;
			}
			if(mp[i][j]==minx[p])
			{
				g[minx[p]]--;
				ans+=mp[i][j];
				if(du[i]==0)
				{
					cnt++;
				}
				if(du[j]==0)
				{
					cnt++;
				}
				du[i]++;
				du[j]++;
			}
			if(cnt==n)
			{
				printf("%d",ans);
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}