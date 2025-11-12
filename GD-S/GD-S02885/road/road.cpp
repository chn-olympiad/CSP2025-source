#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k,fa[N];
struct edge{
	int u,v,w;
}oe[M],e[M+N*K];
struct uuu{
	int c,a[N];
}a[K];
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
void init()
{
	for(int i=1;i<=m;i++) e[i]=oe[i];
}
int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int kruskal(int tn,int tm)
{
	sort(e+1,e+1+tm,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=tm && cnt<tn-1;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int uu=find(u),vv=find(v);
		if(uu!=vv)
		{
			cnt++;
			fa[uu]=vv;
			sum+=w;
		}
	}
	return sum;
}
void solve1()
{
	init();
	int sum=0,tm=m,tn=n;
	for(int i=1;i<=k;i++)
	{
		sum+=a[i].c;
		tn++;
		for(int j=1;j<=n;j++) e[++tm]=(edge){tn,j,a[i].a[j]};
	}
	for(int i=1;i<=tn;i++) fa[i]=i;
	sum+=kruskal(tn,tm);
	cout<<sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>oe[i].u>>oe[i].v>>oe[i].w;
	bool fl=0;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].c;
		if(a[i].c) fl=1;
		for(int j=1;j<=n;j++) cin>>a[i].a[j];
	}
	int llim=0;
	if(!fl)
	{
//		llim=(1<<k)-1;
		solve1();
		return 0;
	}
	int ans=1e18;
	for(int zt=llim;zt<(1<<k);zt++)
	{
		init();
		int sum=0,tm=m,tn=n;
		for(int i=1;i<=k;i++)
		{
			if(zt&(1<<(i-1)))
			{
				sum+=a[i].c;
				tn++;
				for(int j=1;j<=n;j++) e[++tm]=(edge){tn,j,a[i].a[j]};
			}
		}
		for(int i=1;i<=tn;i++) fa[i]=i;
		sum+=kruskal(tn,tm);
		ans=min(ans,sum);
	}
	cout<<ans;
}
