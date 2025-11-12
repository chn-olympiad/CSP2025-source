#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+10,M=2e6+10;
int b[15][N],d[15],fa[N],sz[N];
struct node
{
	int u,v,w;
}a[M],e[M],f[M];
bool cmp(node x,node y){return x.w<y.w;}
int find(int u)
{
	if(fa[u]==u) return u;
	return fa[u]=find(fa[u]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	ll sm=0,fg=1;
	for(int i=1;i<=k;i++)
	{
		cin>>d[i];
		sm+=d[i];
		int tg=0;
		for(int j=1;j<=n;j++)
			cin>>b[i][j],tg|=(b[i][j]==0);
		fg&=tg;
	}
	if(sm==0&&fg)
	{
		ll ans=0;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				a[++m]={n+i,j,b[i][j]};
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=m;i++)
		{
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fx=find(u),fy=find(v);
			if(fx==fy) continue;
			fa[fx]=fy;
			ans+=w;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+m,cmp);
	ll ans=1e18;
	for(int s=0;s<(1<<k);s++)
	{
		int ln=0;
		ll res=0;
		for(int j=1;j<=k;j++)
		{
			if((s>>(j-1))&1) 
			{
				res+=d[j];
				for(int p=1;p<=n;p++) e[++ln]={n+j,p,b[j][p]};
			}
		}
		sort(e+1,e+1+ln,cmp);
		int p1=1,p2=1,g=0;
		while(p1<=m||p2<=ln)
		{
			if(p1>m||(a[p1].w>e[p2].w&&p2<=m)) f[++g]=e[p2++];
			else f[++g]=a[p1++];
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int i=1;i<=g;i++)
		{
			int u=f[i].u,v=f[i].v,w=f[i].w;
			int fx=find(u),fy=find(v);
			if(fx==fy) continue;
			fa[fx]=fy;
			res+=w;
		}
		//~ cout<<s<<" "<<ln<<endl;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
