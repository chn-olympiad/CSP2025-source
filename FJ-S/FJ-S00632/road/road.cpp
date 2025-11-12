#include<bits/stdc++.h>
using namespace std;
long long n,m,k,dl,l,head[10020],c[15],a[15][10010],ll,flagj[10015],sum=0,ans=1e17,vis[10015],lans;
struct edge{
	int v,w,nx;
}e[2500010];
inline void add(int u,int v,int w)
{
	e[++l].v=v;
	e[l].w=w;
	e[l].nx=head[u];
	head[u]=l;
	return;
}
struct ddd{
	int v,w;
}ls,d[1000010];
void ad()
{
	d[++dl]=ls;
	for(int i=dl;i>1;i>>=1)
		if(d[i>>1].w>d[i].w)
			swap(d[i>>1],d[i]);
	return;
}
void del()
{
	if(dl!=1)swap(d[1],d[dl]);
	--dl;
	for(int i=1;(i<<1)<=dl;)
		if((i<<1|1)>dl)
			if(d[i<<1].w<d[i].w)
				swap(d[i<<1],d[i]),i<<=1;
			else
				break;
		else
			if(d[i<<1].w<d[i].w || d[i<<1|1].w<d[i].w)
				if(d[i<<1].w<d[i<<1|1].w)
					swap(d[i<<1],d[i]),i<<=1;
				else
					swap(d[i<<1|1],d[i]),i=i<<1|1;
			else
				break;
	return;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;for(int i=1;i<=m;i++)cin>>u>>v>>w,add(u,v,w),add(v,u,w);
	for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++)cin>>a[i][j],add(n+i,j,a[i][j]),add(j,n+i,a[i][j]);}
	for(int j=0;j<(1<<k);j++)
	{
		ll=j;
		sum=n-1;
		dl=0;
		lans=0;
		for(int i=1;i<=k;i++)lans+=((ll&1)^1)*c[i],sum+=(ll&1)^1,flagj[n+i]=ll&1,ll>>=1;
		for(int i=1;i<=n+k;i++)vis[i]=0;
		vis[1]=1;
		for(int i=head[1];i;i=e[i].nx)if(flagj[e[i].v]==0)ls.v=e[i].v,ls.w=e[i].w,ad();
		while(sum)
		{
			ls=d[1];del();
			u=ls.v;
			if(vis[u]==0)
			{
				--sum;
				lans+=ls.w;
				vis[u]=1;
				for(int i=head[u];i;i=e[i].nx)if(flagj[e[i].v]==0 && vis[e[i].v]==0)ls.v=e[i].v,ls.w=e[i].w,ad();
			}
		}
		ans=min(ans,lans);
	}
	cout<<ans;
	return 0;
}
