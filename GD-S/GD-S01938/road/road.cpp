#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)
#define db double

const int N=1e4;
const int M=1e6;
const ll inf=1e18;

int n,m,k;
struct edge
{
	int u,v;
	ll w;
	bool operator <(edge b)
	{
		return w<b.w;
	}
}a[M+5];
ll b[11][N+5];
ll c[11];
int f[N+15];
int siz[N+15];
ll ans=0;

int findfa(int rt)
{
	if(f[rt]==rt)return rt;
	return f[rt]=findfa(f[rt]);
}

void Union(int u,int v)
{
	u=findfa(u);
	v=findfa(v);
	if(siz[u]>siz[v])swap(u,v);
	f[u]=v;
	siz[v]+=siz[u];
}

inline void init()
{
	for(int i = 1;i<=n+k;i++)
	{
		f[i]=i;
		siz[i]=1;
	}
}

void print()
{
	for(int i = 1;i<=n+k;i++)cout<<f[i]<<' '<<siz[i]<<' '<<i<<endl;
	cout<<endl;
}

void solve()
{
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i = 1;i<=k;i++)
	{
		cin>>c[i];
		for(int j = 1;j<=n;j++)cin>>b[i][j];
	}
	sort(a+1,a+m+1);
	init();
	for(int i = 1;i<=m;i++)
	{
		int u=findfa(a[i].u);
		int v=findfa(a[i].v);
		int w=a[i].w;
		if(u==v)continue;
		ans+=w;
		Union(u,v);
	}
	for(int I=1;I<(1<<k);I++)
	{
		init();
		ll now=0;
		vector<edge>vv;
		for(int i = 0;i<k;i++)
			if((I>>i)&1)
			{
				now+=c[i+1];
				for(int j=1;j<=n;j++)
					vv.push_back({n+i+1,j,b[i+1][j]});
			}
		sort(vv.begin(),vv.end());
		int j = 0;
		for(int i = 1;i<=m;i++)
		{
			int u,v,w;
			while(j<vv.size()&&vv[j].w<a[i].w)
			{
				u=findfa(vv[j].u);
				v=findfa(vv[j].v);
				w=vv[j].w;
				if(u==v)
				{
					j++;
					continue;
				}
				now+=w;
				Union(u,v);
				if(siz[findfa(v)]==n+k)break;
				if(now>=ans)break;
				j++;
			}
			u=findfa(a[i].u);
			v=findfa(a[i].v);
			w=a[i].w;
			if(u==v)continue;
			now+=w;
			Union(u,v);
			if(siz[findfa(v)]==n+k)break;
			if(now>=ans)break;
		}
		ans=min(ans,now);
		if(ans==0)break;
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
