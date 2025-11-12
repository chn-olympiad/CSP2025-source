#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e6+1e5+5,K=15;
const long long inf=(long long)4e18+5;
class DSU
{
	private:
		int fa[N];
		int find(int u)
		{
			if(fa[u]==u)return u;
			return fa[u]=find(fa[u]);
		}
	public:
		void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
		void merge(int u,int v){fa[find(u)]=v;}
		bool same(int u,int v){return find(u)==find(v);}
}dsu;
struct edge{int u,v,w;}e[M];
bool cmp(edge x,edge y){return x.w<y.w;}
long long ans=inf;
void kruskal(int n,int m,long long sum)
{
	dsu.init(n);
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(!dsu.same(u,v))dsu.merge(u,v),cnt++,sum+=w;
		if(sum>=ans)return;
		if(cnt==n-1)break;
	}
	ans=sum;
}
int u[M],v[M],w[M],c[K],a[K][N];
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	int tot=(1<<k)-1;
	for(int i=0;i<=tot;i++)
	{
		int siz=0,cnt=n,sum=0;
		for(int j=1;j<=m;j++)e[++siz]={u[j],v[j],w[j]};
		for(int j=1;j<=k;j++)
		{
			if(i>>j-1&1^1)continue;
			cnt++,sum+=c[j];
			for(int l=1;l<=n;l++)e[++siz]={l,cnt,a[j][l]};
		}
		kruskal(cnt,siz,sum);
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
	for(;T;T--)solve();
	return 0;
}
