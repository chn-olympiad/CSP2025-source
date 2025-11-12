#include<iostream>
#include<algorithm>
#include<queue>
#include<array>
#include<map>
auto III=freopen("replace.in","r",stdin);
auto OOO=freopen("replace.out","w",stdout);
#define LL long long
#define pb push_back
#define vec vector
#define arr array
#define ALL(x) begin(x), end(x)
#define SIZ(x) signed((x).size())
#define RNG(x,l,r) &(x)[l], 1 + &(x)[r]
#define rep(i,l,r) for(int i=l, i##_=r; i<=i##_; i++)
#define per(i,l,r) for(int i=l, i##_=r; i>=i##_; i--)
void tomax(auto& x,auto&& y){if(y>x)x=y;}
void tomin(auto& x,auto&& y){if(y<x)x=y;}
using namespace std; namespace __{

#define ULL unsigned long long
using T=arr<ULL,2>;
constexpr int N=4e5+5, INF32=1.01e9, V=5e6+5;
constexpr T B{131,233};
int n,Q,qc;
string a[N][2];
map<arr<T,2>,vec<int>> mp;
int L[N],R[N],ans[N],px[N],py[N],f[N],g[N],s1[N],s2[N];
arr<int,4> qs[N*2];

struct hh{
	vec<T> p,h;
	hh(const string& a){
		int n=SIZ(a);
		p.resize(n+5), h.resize(n+5);
		p[0]={1,1}, h[0]={1,1};
		rep(i,1,n) rep(j,0,1) p[i][j]=p[i-1][j]*B[j];
		rep(i,1,n) rep(j,0,1) h[i][j]=h[i-1][j]*B[j]+a[i-1];
	}
	T operator()(int l,int r){
		l++, r++; T t{};
		rep(j,0,1) t[j]=h[r][j]-h[l-1][j]*p[r-l+1][j];
		return t;
	}
};

struct OO{
	int tot{1},dfi,dfn[V],siz[V];
	arr<int,26> z[V];
	#define z(u,c) z[u][c-'a']
	void clear(){
		fill(RNG(z,0,tot+2),arr<int,26>{});
		fill(RNG(dfn,0,tot+2),0);
		fill(RNG(siz,0,tot+2),0);
		tot=1, dfi=0;
	}
	void ins(const string& a,int& p){
		int& u=p=1;
		for(auto c:a){
			if(!z(u,c)) z(u,c)=++tot;
			u=z(u,c);
		}
	}
	void dfs(int u){
		dfn[u]=++dfi,siz[u]=1;
		rep(c,'a','z') if(z(u,c)){
			dfs(z(u,c));
			siz[u]+=siz[z(u,c)];
		}
	}
} X,Y;

struct TT{
	int a[V];
	void add(int x,int w){for(;x<V;x+=x&-x)a[x]+=w;}
	int qry(int x,int r=0){for(;x>0;x-=x&-x)r+=a[x];return r;}
} O;

void main(){
	cin.tie(0)->sync_with_stdio(0);
	// signed cse; for(cin>>cse; cse--; clear())
[&](){
	cin>>n>>Q;
	rep(i,1,n) cin>>a[i][0]>>a[i][1];
	rep(j,1,Q) cin>>a[n+j][0]>>a[n+j][1];
	rep(i,1,n+Q){
		if(a[i][0]==a[i][1] || SIZ(a[i][0])!=SIZ(a[i][1])) continue;
		rep(k,0,SIZ(a[i][0])-1)
			if(a[i][0][k]!=a[i][1][k])
				{L[i]=k; break;}
		per(k,SIZ(a[i][0])-1,0)
			if(a[i][0][k]!=a[i][1][k])
				{R[i]=k; break;}
		hh h0(a[i][0]), h1(a[i][1]);
		auto t0=h0(L[i],R[i]);
		auto t1=h1(L[i],R[i]);
		mp[{t0,t1}].pb(i);
	}
	for(auto& [_,v]:mp){
		qc=0;
		X.clear();
		Y.clear();
		for(auto i:v){
			string t=a[i][0].substr(0,L[i]);
			reverse(ALL(t));
			X.ins(t,px[i]);
			Y.ins(a[i][0].substr(R[i]+1,SIZ(a[i][0])-1-R[i]),py[i]);
		}
		qc=0;
		X.dfs(1);
		Y.dfs(1);
		for(auto i:v){
			f[i]=X.dfn[px[i]];
			g[i]=Y.dfn[py[i]];
			s1[i]=X.siz[px[i]];
			s2[i]=Y.siz[py[i]];
			// cout<<f[i]<<' '<<s1[i]<<' '<<g[i]<<' '<<s2[i]<<endl;
			if(i<=n){
				qs[++qc]={f[i],g[i],g[i]+s2[i]-1,1};
				qs[++qc]={f[i]+s1[i],g[i],g[i]+s2[i]-1,-1};
			}else{
				qs[++qc]={f[i],INF32,g[i],-i};
			}
		}
		sort(RNG(qs,1,qc));
		rep(j,1,qc){
			auto& [_,l,r,w]=qs[j];
			if(w<-1){
				int i=-w-n;
				ans[i]+=O.qry(r);
			}else{
				O.add(l,w);
				O.add(r+1,-w);
			}
		}
	}
	rep(j,1,Q) cout<<ans[j]<<'\n';
}();}}
signed main(){__::main();return 0;}
