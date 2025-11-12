#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[100010];
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
struct edge
{
	int u,v,w;
}e[2000010];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,k,m;
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		sort(e+1,e+1+m,[](edge x,edge y){return x.w<y.w;});
		int tot=0,ans=0;
		for(int i=1;i<=m;i++)
		{
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y)
			{
				tot++;
				ans+=e[i].w;
				f[x]=y;
				if(tot==n-1)break;
			}
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=m;i++)
		{
			cin>>e[i].u>>e[i].v>>e[i].w;
		}
		int cnt=m;
		for(int i=1;i<=k;i++)
		{
			int a;
			cin>>a;
			for(int j=1;j<=n;j++)
			{
				cin>>a;
				e[++cnt]={i+n,j,a};
			}
		}
		sort(e+1,e+1+cnt,[](edge x,edge y){return x.w<y.w;});
		int tot=0,ans=0;
		for(int i=1;i<=cnt;i++)
		{
			int x=find(e[i].u),y=find(e[i].v);
			if(x!=y)
			{
				tot++;
				ans+=e[i].w;
				f[x]=y;
				if(tot==n+k-1)break;
			}
		}
		cout<<ans;
	}
}
