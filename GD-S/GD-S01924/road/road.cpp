#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1000010,N=10010,K=15,V=1030;
const ll Inf=1ll<<60;
int n,m,k,fa[N+K],c[K],sz[V];
ll ans;
struct edge{
	int u,v,w;
	inline bool operator <(edge e)const
	{
		return w<e.w;
	}
}e[M],se[V][N],te[K][N];
inline int Find(int u)
{
	if(fa[u]==u) return u;
	return fa[u]=Find(fa[u]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;sz[0]<n-1;i++)
	{
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		ans+=e[i].w;
		se[0][++sz[0]]=e[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>te[i][j].w;
			te[i][j].u=i+n,te[i][j].v=j;
		}
		sort(te[i]+1,te[i]+n+1);
	}
	for(int s=1;s<(1<<k);s++)
	{
		ll sum=0;
		int x,cnt=0;
		for(int i=1;i<=k;i++)
		{
			if(((s>>i-1)&1)) sum+=c[i],x=i,cnt++;
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int p0=1,p1=1,y=s^(1<<x-1);
		for(int i=1;i<n+cnt;i++)
		{
			while(p0<=sz[y]&&Find(se[y][p0].u)==Find(se[y][p0].v)) p0++;
			while(p1<=n&&Find(te[x][p1].u)==Find(te[x][p1].v)) p1++;
			if(p0>sz[y]||(p1<=n&&te[x][p1].w<se[y][p0].w))
			{
				fa[Find(te[x][p1].u)]=Find(te[x][p1].v);
				sum+=te[x][p1].w;
				se[s][++sz[s]]=te[x][p1];
				p1++;
//				cout<<te[x][p1].w<<"\n";
			}
			else
			{
				fa[Find(se[y][p0].u)]=Find(se[y][p0].v);
				sum+=se[y][p0].w;
				se[s][++sz[s]]=se[y][p0];
				p0++;
//				cout<<"2\n";
			}
		}
		ans=min(ans,sum);
//		cout<<s<<" "<<sum<<endl;
	}
	cout<<ans;
	return 0;
}
