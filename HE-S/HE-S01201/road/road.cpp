#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
struct node{
	int u,v,w,bl;
	bool operator<(const node &x)const
	{
		return w<x.w;
	}
	node(int _u=0,int _v=0,int _w=0,int _bl=0)
	{
		u=_u,v=_v,w=_w,bl=_bl;
	}
}g[N],f[N];
int fa[N],val[20],n,m,k;
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		g[i]=node(u,v,w,0);
	}
	sort(g+1,g+1+m);
	int pos=0;
	for(int i=1;i<=m;i++)
	{
		int r1=find(g[i].u),r2=find(g[i].v);
		if(r1!=r2)
		{
			fa[r1]=r2;
			f[++pos]=g[i];
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			f[++pos]=node(i+n,j,w,i);
		}
	}
	sort(f+1,f+1+pos);
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		ll res=0;
		for(int j=0;j<k;j++)
			if(i>>j&1) res+=val[j+1];
		for(int j=1;j<=n+k;j++) fa[j]=j;
	//	cout<<i<<":\n";
		for(int j=1;j<=pos;j++)
		{
			if(f[j].bl==0||(f[j].bl&&((i>>f[j].bl-1)&1)))
			{
				
				int r1=find(f[j].u),r2=find(f[j].v);
				if(r1!=r2) fa[r1]=r2,res+=f[j].w;//,cout<<f[j].u<<' '<<f[j].v<<' '<<f[j].w<<endl;
			}
		}
	//	cout<<endl;
	//	cout<<i<<' '<<res<<endl;
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
