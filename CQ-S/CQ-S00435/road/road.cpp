#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct Edge
{
	int u,v,w;
}edge[M];
int n,m,k,c[15],fa[N+15];
long long Ans;
vector<Edge>g;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge[i]={u,v,w};
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	sort(edge+1,edge+1+m,[](Edge i,Edge j){return i.w<j.w;});
	for(int i=1,u,v,cnt=1;i<=m&&cnt<n;i++)
	{
		u=find(edge[i].u);
		v=find(edge[i].v);
		if(u!=v)
		{
			fa[u]=v;
			g.push_back(edge[i]);
			cnt++;
			Ans+=edge[i].w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1,k;j<=n;j++)
		{
			cin>>k;
			if(k+c[i]/n<=g[n-2].w)g.push_back({n+i,j,k});
		}
	}
	sort(g.begin(),g.end(),[](Edge i,Edge j){return i.w<j.w;});
	for(int sum=1;sum<1<<k;sum++)
	{
		long long ans=0;
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;
		}
		int cnt=n,x=sum,k=1;
		while(x)
		{
			if(x&1)
			{
				ans+=c[k];
				cnt++;
			}
			k++;
			x>>=1;
		}
		for(int i=0,u,v;i<g.size()&&cnt>1;i++)
		{
			if(g[i].u>n&&!((sum>>g[i].u-n-1)&1))continue;
			u=find(g[i].u);
			v=find(g[i].v);
			if(u!=v)
			{
				fa[u]=v;
				cnt--;
				ans+=g[i].w;
			}
		}
		Ans=min(Ans,ans);
	}
	cout<<Ans;
	return 0;
}
