#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[15],h[15][10005],fa[10015];
long long ans=0x3f3f3f3f3f3f3f3f,sum=0;
set<array<int,3> > s;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool un(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
void dfs(int x,set<array<int,3> >& s,long long an,int cnt)
{
	if(x==k+1)
	{
		int cc=0;
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		for(const auto g : s)
		{
			if(un(g[1],g[2]))
			{
				an+=g[0];
				if(++cc==n+cnt-1)break;
			}
		}
		ans=min(ans,an);
		return;
	}
	dfs(x+1,s,an,cnt);
	for(int i=1;i<=n;i++)
	{
		s.insert({h[x][i],x+n,i});
	}
	dfs(x+1,s,an+c[x],cnt+1);
	for(int i=1;i<=n;i++)
	{
		s.erase({h[x][i],x+n,i});
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		s.insert({w,u,v});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>h[i][j];
		}
	}
	if(k==0)
	{
		ans=0;
		for(auto g : s)
		{
			if(un(g[1],g[2]))ans+=g[0];
		}
		cout<<ans;
		return 0;
	}
	if(sum==0)
	{
		ans=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(h[i][j]==0)
				{
					for(int l=1;l<=n;l++)
					{
						s.insert({h[i][l],j,l});
					}
					break;
				}
			}
		}
		int cnt=0;
		for(auto g : s)
		{
			if(un(g[1],g[2]))
			{
				ans+=g[0];
				if(++cnt==n-1)break;
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1,s,0,0);
	cout<<ans;
	return 0;
}
