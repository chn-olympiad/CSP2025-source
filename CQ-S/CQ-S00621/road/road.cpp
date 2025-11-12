/*
出发！前进！ 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 10015
	#define M 1000005
	#define INF 0x3f3f3f3f3f3f3f3f
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	#undef c
	int n,m,k,fa[N],sz[N],Cval[11];struct edge{int u,v,w;bl operator<(const edge&b)const{return w<b.w;}}E[M];vector<edge>e[11];
	ll ans=INF;bl tag[1024];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	il bl merge(int x,int y){if((x=find(x))==(y=find(y)))return 0;if(sz[x]>sz[y])swap(x,y);fa[x]=y,sz[y]+=sz[x];return 1;}
	il vector<edge>duel(vector<edge>&a,vector<edge>&b){
		vector<edge>d;d.reserve(n);
		for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;int l=0,r=0;
		while(l<a.size()&&r<b.size()){
			if(a[l].w<=b[r].w){
				if(merge(a[l].u,a[l].v))d.pb(a[l]);
				++l;
			}else{
				if(merge(b[r].u,b[r].v))d.pb(b[r]);
				++r;
			}
		}
		for(;l<a.size();++l)if(merge(a[l].u,a[l].v))d.pb(a[l]);
		for(;r<b.size();++r)if(merge(b[r].u,b[r].v))d.pb(b[r]);
		return d;
	}
	vd dfs(int state,vector<edge>&now){
		tag[state]=1;
		ll res=0;
		for(edge&pos:now)res+=pos.w;for(int i=1;i<=k;i++)if((state>>(i-1))&1)res+=Cval[i];
		ans=min(ans,res);
		for(int i=1;i<=k;i++)if((((state>>(i-1))&1)^1)&&!tag[state|(1<<(i-1))]){
			vector<edge>to=duel(now,e[i]);
			dfs(state|(1<<(i-1)),to);
		}
	}
	signed main(){
		n=read(),m=read(),k=read();
		for(int i=1,u,v,w;i<=m;i++)u=read(),v=read(),w=read(),E[i]=(edge){u,v,w};
		sort(E+1,E+1+m);for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;e[0].reserve(n);
		for(int i=1;i<=m;i++)if(merge(E[i].u,E[i].v))e[0].pb(E[i]);
		for(int i=1;i<=k;i++){
			Cval[i]=read(),e[i].reserve(n);
			for(int j=1,w;j<=n;j++)w=read(),e[i].pb((edge){n+i,j,w});
			sort(e[i].begin(),e[i].end());
		}vector<edge>now=e[0];
		dfs(0,now);
		printf("%lld",ans);
		return 0;
	}
}signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	TYX_YNXK::main();
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 512MB
*/
/*
至少不会保龄了是吧。
简单来说，最小生成树。
除此以外，还有 k=10 个额外点。额外点额外建立，额外连边。
乍一看没思路。。
主要是 1e9log 不太能过吧。
额外点加了就一定会用。
哦哦哦首先不难证明只有原图最小生成树的边会用到。
然后边集 1e4，1024*1e5log 1e8 的 log 看着就可以过了。
差点写 LCT。
不过应该还可以优化。你考虑插入 1e4 条边，但始终还是只需要跑新树边和插入边的最小生成树。
dfs 式，最多 1024 个状态，每个 1e4 的 alpha，真的能过了。

讲个笑话：我又假了一次，2^2^10。幸好不难改。
另外第 4 个大样例最快很不正常，有时间回来对拍。 
*/
