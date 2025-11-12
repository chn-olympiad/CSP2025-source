#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
auto III=freopen("road.in","r",stdin);
auto OOO=freopen("road.out","w",stdout);
#define LL long long
#define pb push_back
#define vec vector
#define arr array
#define ALL(x) begin(x), end(x)
#define SIZ(x) signed((x).size())
#define rep(i,l,r) for(int i=l, i##_=r; i<=i##_; i++)
#define per(i,l,r) for(int i=l, i##_=r; i>=i##_; i--)
void tomax(auto& x,auto&& y){if(y>x)x=y;}
void tomin(auto& x,auto&& y){if(y<x)x=y;}
using namespace std; namespace __{

constexpr int N=2e4+5, E=1e6+5, K=10+5;
int n,m,k;
vec<arr<int,3>> f;
int c[K],a[K][N];

struct UU{
	int fa[N]; void bld(int n){ rep(i,0,n) fa[i]=i; }
	int find(int x){ return x==fa[x] ? x : fa[x]=find(fa[x]); }
	void mer(int u,int v){ u=find(u), v=find(v), fa[v]=u; }
} U;

LL kru(auto& e,int tp=0){
	sort(ALL(e));
	U.bld(n+20);
	LL res=0;
	for(auto [w,u,v]:e){
		if(U.find(u)==U.find(v)) continue;
		U.mer(u,v);
		res+=w;
		if(tp) f.pb({w,u,v});
	}
	return res;
}

void main(){
	cin.tie(0)->sync_with_stdio(0);
	// signed cse; for(cin>>cse; cse--; clear())
[&](){
	cin>>n>>m>>k;
	vec<arr<int,3>> e;
	rep(i,1,m){ int u,v,w; cin>>u>>v>>w; e.pb({w,u,v}); }
	rep(j,1,k){
		cin>>c[j];
		rep(i,1,n) cin>>a[j][i];
	}
	LL ans=kru(e,1);
	rep(s,0,(1<<k)-1){
		auto bk=f;
		LL bsc=0;
		rep(j,1,k) if(s>>(j-1)&1){
			bsc+=c[j];
			rep(i,1,n){
				f.pb({a[j][i],n+j,i});
			}
		}
		LL t=kru(f);
		tomin(ans,bsc+t);
		bk.swap(f);
	}
	cout<<ans<<'\n';
}();}}
signed main(){__::main();return 0;}
