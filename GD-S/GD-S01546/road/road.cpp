#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<bitset>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define infile(filename) freopen(filename".in","r",stdin)
#define outfile(filename) freopen(filename".out","w",stdout)
#define usefile(filename) infile(filename),outfile(filename)
using namespace std; typedef long long ll; typedef unsigned long long ull;
inline char gc() { static const int BUF=1<<20; static char ch[BUF]={},*l=ch,*r=ch; return (l==r&&(r=(l=ch)+fread(ch,1,BUF,stdin),l==r))?EOF:*l++; }
template <typename T> void read(T &a) { static char ch,fushu; a=fushu=0; do ch=gc(); while(ch!='-'&&(ch<48||ch>57)); if(ch=='-') fushu=1,ch=gc(); do a=(a<<1)+(a<<3)+(ch^48),ch=gc(); while(ch>47&&ch<58); if(fushu) a=-a; return ; }
template <typename T,typename ...Args> void read(T &a,Args &...args) { read(a),read(args...); }
template <typename T> void ckmin(T &a,T b) { if(b<a) a=b; }
template <typename T> void ckmax(T &a,T b) { if(a<b) a=b; }
bool ST;
const int N=10009,M=1000099,KK=12;
int n,m,K,em=0,fa[N]={},sz[N]={},c[KK]={},a[KK][N]={};
struct Edge { int x,y,z; bool SP;
	friend bool operator < (const Edge &a,const Edge &b) {
		return a.z<b.z;
	}
} eg[M],e[N*KK];
bool ED;
int father(int x) { return fa[x]=fa[x]==x?x:father(fa[x]); }
void link(int x,int y) { x=father(x),y=father(y);
	if(x==y) return ; if(sz[x]>sz[y]) swap(x,y);
	fa[x]=y,sz[y]+=sz[x]; }
bool same(int x,int y) { return father(x)==father(y); }
int main()
{
	infile("road");
	outfile("road");
	int i,j,S; ll ans,sum;
	read(n,m,K);
	for(i=1;i<=m;++i) read(eg[i].x,eg[i].y,eg[i].z),eg[i].SP=false;
	for(i=1;i<=K;++i) { read(c[i]); for(j=1;j<=n;++j) read(a[i][j]); }
	sort(eg+1,eg+1+m);
	for(i=1;i<=n;++i) fa[i]=i,sz[i]=1;
	for(i=1,ans=0;i<=m;++i)
		if(!same(eg[i].x,eg[i].y))
			ans+=eg[i].z,link(eg[i].x,eg[i].y),e[++em]=eg[i];
	for(i=1;i<=K;++i) for(j=1;j<=n;++j) e[++em]=(Edge){i+n,j,a[i][j],true};
	sort(e+1,e+1+em);
	for(S=2;S<(1<<(K+1));S+=2) {
		for(i=1;i<=n+K;++i) fa[i]=i,sz[i]=1;
		for(i=1,sum=0;i<=em;++i)
			if((!e[i].SP||(S>>(e[i].x-n)&1))&&!same(e[i].x,e[i].y))
				sum+=e[i].z,link(e[i].x,e[i].y);
		for(i=1;i<=KK;++i) if(S>>i&1) sum+=c[i];
		ckmin(ans,sum);
	}
	printf("%lld\n",ans);
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<"MB"<<endl;
}