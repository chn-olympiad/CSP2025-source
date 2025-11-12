#include<bits/stdc++.h>
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
#define rrep(i,r,l,k) for(int i=r;i>=l;i-=k)
#define loop(i,st,ed,nxt) for(int i=st;i!=ed;i=nxt)
#define int long long
using namespace std;
const int N=1e5+5,M=1e6+5;
int fa[M];
int c[10],a[10][N];
struct node{int u,v,w;}e[M],edge[M];
bool cmp(node A,node B){return A.w<B.w;}
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
void init(){}
void solve()
{
	int n,m,k,tot=0,ans=0;
	cin>>n>>m>>k;
	rep(i,1,n,1)fa[i]=i;
	rep(i,1,m,1)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,cmp);
	rep(i,1,m,1)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(fnd(u)!=fnd(v))
		{
			fa[fnd(u)]=fnd(v);
			edge[++tot].u=u;
			edge[tot].v=v;
			edge[tot].w=w;
			ans+=w;
		}
	}
	rep(i,0,k-1,1)
	{
		cin>>c[i];
		rep(j,1,n,1)cin>>a[i][j];
	}
	rep(s,0,(1<<k)-1,1)
	{
		rep(i,1,n+k,1)fa[i]=i;
		int cnt=0,res=0;
		rep(i,0,k-1,1)if(s&(1<<i))
		{
			res+=c[i];
			rep(j,1,n,1)
			{
				e[++cnt].u=n+i+1;
				e[cnt].v=j;
				e[cnt].w=a[i][j];
			}
		}
		rep(i,1,tot,1)
		{
			e[++cnt].u=edge[i].u;
			e[cnt].v=edge[i].v;
			e[cnt].w=edge[i].w;
		}
		sort(e+1,e+cnt+1,cmp);
		rep(i,1,cnt,1)
		{
			int u=fnd(e[i].u),v=fnd(e[i].v),w=e[i].w;
			if(u!=v)
			{
				fa[u]=v;
				res+=w;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
}
signed main()
{
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	//cin>>T;
	init();
	rep(i,1,T,1)
	{
		solve();
	}
	return 0;
}

