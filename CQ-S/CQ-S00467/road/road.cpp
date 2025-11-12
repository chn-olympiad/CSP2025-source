#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
typedef long long ll;
int n,m,K,prt[M],sz[M],cnt,c[11];
struct edge
{
	int x,y,w;
	bool operator < (const edge &a)const {return w<a.w;}
}e[M],g[N],a[11][N],b[M*2],tmp[M*2];
int find(int x) {return x==prt[x]?x:prt[x]=find(prt[x]);}
void merge(int x,int y)
{
	if((x=find(x))==(y=find(y))) return;
	if(sz[x]>sz[y]) swap(x,y);
	prt[x]=y,sz[y]+=sz[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].w;
	for(int i=0;i<K;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) a[i][j].x=n+i+1,a[i][j].y=j,cin>>a[i][j].w;
		sort(a[i]+1,a[i]+1+n);
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n+K;i++) prt[i]=i,sz[i]=1;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].x)==find(e[i].y)) continue;
		ans+=e[i].w,g[++cnt]=e[i],merge(e[i].x,e[i].y);
	}
	for(int s=1;s<(1<<K);s++)
	{
		int len=cnt;
		for(int i=1;i<=cnt;i++) b[i]=g[i];
		ll res=0;
		for(int i=0;i<K;i++) if(s>>i&1)
		{
			res+=c[i];
			for(int j=1;j<=len;j++) tmp[j]=b[j];
			for(int p=1,x=1,y=1;p<=len+n;p++)
			{
				if(y>n||(x<=len&&tmp[x].w<a[i][y].w)) b[p]=tmp[x],x++;
				else b[p]=a[i][y],y++;
			}
			len+=n;
		}
		for(int i=1;i<=n+K;i++) prt[i]=i,sz[i]=1;
		for(int i=1;i<=len;i++)
			if(find(b[i].x)!=find(b[i].y)) res+=b[i].w,merge(b[i].x,b[i].y);
		// cerr<<"?? "<<s<<" "<<res<<"\n";
		// for(int i=1;i<=len;i++) cerr<<b[i].x<<" "<<b[i].y<<" "<<b[i].w<<"\n";
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}