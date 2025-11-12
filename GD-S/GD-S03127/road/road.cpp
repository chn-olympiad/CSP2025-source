#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MS=20005,S=2000005;
const ll inf=1e17;

struct node
{
	int x,y,w;
};

int n,m,k;
int c[15],a[15][MS];
node ed[S];
int tot;
node res[S];
int fa[S],hei[S],siz[S];

int fnd(int x){return fa[x]==x?x:fa[x]=fnd(fa[x]);}
inline bool merge(int x,int y)
{
	int rx=fnd(x),ry=fnd(y);
	if(rx==ry) return false;
	if(hei[rx]<hei[ry]) swap(rx,ry);
	fa[ry]=rx;
	hei[rx]=max(hei[rx],hei[ry]+1);
	siz[rx]+=siz[ry];
	return true;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>ed[i].x>>ed[i].y>>ed[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	sort(ed+1,ed+m+1,[&](node x,node y){return x.w<y.w;});
	for(int i=1;i<=n;i++) fa[i]=i,hei[i]=1,siz[i]=1;
	for(int i=1;i<=m;i++) if(merge(ed[i].x,ed[i].y)) res[++tot]=ed[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
		{
			tot++;
			res[tot].x=n+i,res[tot].y=j,res[tot].w=a[i][j];
		}
	sort(res+1,res+tot+1,[&](node x,node y){return x.w<y.w;});
	ll ans=inf;
	for(int st=0;st<(1<<k);st++)
	{
		ll sm=0;
		for(int i=1;i<=k;i++) if(st>>i-1&1) sm+=c[i];
		for(int i=1;i<=n+k;i++) fa[i]=i,hei[i]=1,siz[i]=(i<=n);
		for(int i=1;i<=tot&&sm<ans&&siz[fnd(1)]<n;i++)
		{
			int x=res[i].x,y=res[i].y,w=res[i].w;
			if(x>n&&(st>>x-n-1&1^1)) continue;
			if(merge(x,y)) sm+=w;
		}
		ans=min(ans,sm);
	}
	cout<<ans<<'\n';
	return 0;
}
