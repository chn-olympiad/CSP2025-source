#include<bits/stdc++.h>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define _antirep(i,a,b) for(int i=(a);i>=(b);--i)
#define int LL
using namespace std;
typedef long long LL;

const int N=1e4+5,M=1e6+5,K=15;

int n,m,k;
int c[K],a[K][N];
struct node
{
	int u,v,w; 
	bool operator<(const node &T)const{
		return w<T.w;
	}
}e[M];
int now[K],fa[N];
vector<node>g[K];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
} 
void init()
{
	_rep(o,1,k)
	{
		_rep(i,1,n) 
			_rep(j,i+1,n) 
				g[o].push_back((node){i,j,a[o][i]+a[o][j]});  
		sort(g[o].begin(),g[o].end());	now[o]=0;	
	}
}
void solve()
{
	sort(e+1,e+m+1);
	_rep(i,1,n) fa[i]=i;
	int cnt=0,ans=0;
	_rep(i,1,m)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		_rep(o,1,k)
		{
			if(now[o]==0)
			{
				int fu=find(g[o][0].u),fv=find(g[o][0].v);
				if(fu!=fv&&g[o][0].w+c[o]<=w)  
				{ 
					fa[fv]=fu;
					ans+=g[o][0].w+c[o];
					now[o]=1;
					if(++cnt>=n-1) break;
				} 
			} 
			if(now[o]!=0)
			{
				while(now[o]<g[o].size()&&g[o][now[o]].w<=w)
				{
					int fu=find(g[o][now[o]].u),fv=find(g[o][now[o]].v);
					if(fu==fv) now[o]++;
					else 
					{
						fa[fv]=fu;
						ans+=g[o][now[o]].w;
						now[o]++;
						if(++cnt>=n-1) break;
					}
				}
			} 
		}
		if(cnt>=n-1) break;
		
		u=find(u),v=find(v);
		if(u!=v)
		{
			fa[v]=u;
			ans+=w;
			if(++cnt>=n-1) break;
		}
	}
	
	cout<<ans<<"\n";
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m>>k;
	_rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w; 
	_rep(i,1,k)
	{
		cin>>c[i];
		_rep(j,1,n) cin>>a[i][j];
	}
	
	init();
	solve();
	return 0;
}
