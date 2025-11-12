#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6;
int sum,n,m,k,x,y,z,sz,a[12][10004],c[12],fa[10025],ans,szz,ssa,cc;
struct node
{
	int u,v,w;
}e[N],ee[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int get(int ac)
{
	if(ac==fa[ac]) return ac;
	return fa[ac]=get(fa[ac]);
}
void sol()
{
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			sz++;
			e[sz].u=n+i,e[sz].v=j,e[sz].w=a[i][j];
			sz++;
			e[sz].v=n+i,e[sz].u=j,e[sz].w=a[i][j];
		}
	sort(e+1,e+sz+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=sz;i++)
	{
		x=get(e[i].u),y=get(e[i].v);
		if(x!=y)
		{
			fa[x]=y;
			ans+=e[i].w;
		}
	}
	cout<<ans;
}
void wor(int kk)
{
	sz=szz,ssa=0;
	for(int i=1;i<=sz;i++) ee[i]=e[i];
	for(int i=1;i<=k;i++)
		if(kk&(1<<(i-1)))
		{
			cc+=c[i];
			for(int j=1;j<=n;j++)
			{
				sz++;
				ee[sz].u=n+i,ee[sz].v=j,ee[sz].w=a[i][j];
				sz++;
				ee[sz].v=n+i,ee[sz].u=j,ee[sz].w=a[i][j];
			}
		}
	sort(ee+1,ee+sz+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=sz;i++)
	{
		x=get(ee[i].u),y=get(ee[i].v);
		if(x!=y)
		{
			fa[x]=y;
			ssa+=ee[i].w;
		}
	}
	ans=min(ans,ssa+cc);
}
void force()
{
	ans=1e17,szz=sz;
	for(int i=0;i<(1<<k);i++) wor(i);
	cout<<ans<<'\n';
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		sz++;
		e[sz].u=x,e[sz].v=y,e[sz].w=z;
		sz++;
		e[sz].u=y,e[sz].v=x,e[sz].w=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		sum+=c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(!sum) sol();
	else force();
	return 0;
}
