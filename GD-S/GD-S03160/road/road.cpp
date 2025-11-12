#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,y,x) for(int i=(y);i>=(x);i--)
bool memst;
namespace cyzz
{
	#define N 10050
	#define M 1000005
	#define K 11
	#define inf (ll)(1e18+7)
	int n,m,k,a[K];
	struct Edge
	{
		short u,v;int w;
		bool operator<(const Edge &_)
			{return w<_.w;}
	};
	vector<Edge>E,e[K];
	struct DSU
	{
		int fa[N];
		void init(int x){rep(i,0,x) fa[i]=i;}
		inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
		inline void merge(int x,int y){x=find(x);y=find(y);fa[x]=y;}
	}D;
	ll val[1<<K];
	vector<Edge>f[1<<K];
	void MAIN()
	{
		cin>>n>>m>>k;
		rep(i,1,m)
		{
			int x,y,z;cin>>x>>y>>z;
			E.eb(Edge{short(x),short(y),z});
		}
		rep(i,0,k-1)
		{
			cin>>a[i];
			rep(j,1,n)
			{
				int x;cin>>x;
				e[i].eb(Edge{short(n+i+1),short(j),x});
			}
			sort(e[i].begin(),e[i].end());
		}
		sort(E.begin(),E.end());
		D.init(n);vector<Edge>nE;
		ll ans=0;
		for(Edge i:E)
		{
			int x=D.find(i.u),y=D.find(i.v);
			if(x!=y) ans+=i.w,nE.eb(i),D.fa[x]=y;
		}
		f[0]=E=nE;
		rep(s,1,(1<<k)-1)
		{
			int l=__builtin_ctz(s);val[s]=val[s^(1<<l)]+a[l];
			D.init(n+k);vector<Edge>tmp(f[s^(1<<l)].size()+e[l].size());
			merge(f[s^(1<<l)].begin(),f[s^(1<<l)].end(),e[l].begin(),e[l].end(),tmp.begin());
			ll ret=val[s];
			for(Edge i:tmp)
			{
				int x=D.find(i.u),y=D.find(i.v);
				if(x!=y) ret+=i.w,f[s].eb(i),D.fa[x]=y;
			}
			ans=min(ans,ret);
		}
		cout<<ans;
	}
}bool memed;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cyzz::MAIN();
	debug("%.2lfms %.2lfMB",1.0*clock()/CLOCKS_PER_SEC*1000,
		abs(&memst-&memed)/1024./1024);
}
