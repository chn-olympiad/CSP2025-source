#include <bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define ll long long
using namespace std;
const int N=1e5+10,M=2e6+10;

int n,m,k;
int fa[N],c[N],sz[N],du[N],sum[N];
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			e[++m].u=i+n;e[m].v=j;
			cin>>e[m].w;
		}
	}
	sort(e+1,e+m+1,cmp);
	int ans=1e18;
	for(int S=0;S<(1<<k);S++)
	{
		int cxt=0,res=0;
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;sz[i]=1;
			du[i]=sum[i]=0;
		}
		int pp=__builtin_popcountll(S);
		for(int i=1;i<=m;i++)
		{
			if(e[i].u>n&&!(S&(1<<(e[i].u-n-1)))) continue;
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx!=fy)
			{
				if(sz[fx]>sz[fy]) swap(fx,fy);
				if(e[i].u>n)
				{
					du[e[i].u-n]++;
					sum[e[i].u-n]+=e[i].w;
				}
				res+=e[i].w;
				fa[fx]=fy;
				sz[fy]+=sz[fx];
				sz[fx]=0;
				cxt++;
			}
			if(cxt==n+pp-1) break;
		}
		for(int i=1;i<=k;i++)
		{
			if(du[i]==1) res-=sum[i];
			else if(du[i]>1) res+=c[i];
		}
		ans=min(ans,res); 
	}
	cout<<ans<<endl;
	return 0;
}

