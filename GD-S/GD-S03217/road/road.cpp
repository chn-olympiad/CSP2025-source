#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e6+10,mod=1e9+7;
struct scs
{
	int u,v,w;
}a[M],b[N],e[N];
bool cmp(scs x,scs y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int c[20],w[20][N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp);
	int cur=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		b[++cur]=a[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>w[i][j];
	}
	int mn=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		int tc=0;
		int ans=0;
		for(int j=1;j<=cur;j++) e[++tc]=b[j];
		for(int j=1;j<=k;j++) if(i&(1<<(j-1)))
		{
			ans+=c[j];
			for(int i=1;i<=n;i++) e[++tc]={i,n+j,w[j][i]};
		}
		if(ans>mn) continue;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		sort(e+1,e+tc+1,cmp);
		for(int i=1;i<=tc;i++)
		{
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;
			fa[fx]=fy;
			ans+=e[i].w;
			if(ans>mn) break;
		}
		mn=min(mn,ans);
	}
	cout<<mn;
	return 0;
}
/*
80pts at min
也不知道评测机多快
不管了，收
*/
