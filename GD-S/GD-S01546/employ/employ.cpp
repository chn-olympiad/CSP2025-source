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
const int N=509,moder=998244353;
int add(int x,int y) { return x+y>=moder?x+y-moder:x+y; } int Add(int &x,int y) { return x=x+y>=moder?x+y-moder:x+y; }
int sub(int x,int y) { return x<y?x-y+moder:x-y; } int Sub(int &x,int y) { return x=x<y?x-y+moder:x-y; }
int kuai(int a,int b) { ull rey=1,temp=a; for(;b;b>>=1) { if(b&1) rey=rey*temp%moder; } return rey; }
int n,m,c[N]={},cnt[N]={},fact[N]={},finv[N]={},C[N][N]={}; bool a[N]={};
/*namespace taskA {
	int f[N][N]={};
	bool solve() {
		int i;
		for(i=n;i>=0;--i) {
			Add(f[i+1][i],)
		}
		return true;
	}
}*/
namespace taskBF {
	int f[1<<18][19]={};
	void solve() {
		int i,j,k,S,ans=0;
		f[0][0]=1;
		for(S=0;S<(1<<n);++S) {
			i=__builtin_popcount(S);
			for(j=0;j<n;++j)
				if(!(S>>j&1))
					for(k=0;k<=i;++k)
						Add(f[S|(1<<j)][k+(a[i+1]&&i-k<c[j+1])],f[S][k]);
		}
		for(i=m;i<=n;++i) Add(ans,f[(1<<n)-1][i]);
		printf("%d\n",ans);
	}
}
bool ED;
int main()
{
	usefile("employ");
	int i,j; char ch;
	// cerr<<"Use memory: "<<((&ED)-(&ST))/1048576.0<<endl;
	read(n,m);
	do ch=gc(); while(ch!='0'&&ch!='1');
	for(i=1;i<=n;++i) a[i]=ch=='1',ch=gc();
	for(i=1;i<=n;++i) read(c[i]),++cnt[c[i]];
	sort(c+1,c+1+n);
	fact[0]=finv[0]=1;
	for(i=1;i<N;++i) fact[i]=(ull)fact[i-1]*i%moder;
	finv[N-1]=kuai(fact[N-1],moder-2);
	for(i=N-2;i;--i) finv[i]=(ull)finv[i+1]*(i+1)%moder;
	for(i=0;i<N;++i) for(j=0;j<=i;++j)
		C[i][j]=!j||i==j?1:add(C[i-1][j-1],C[i-1][j]);
	/*if(taskA::solve()) return 0;
	else */if(n<=18) taskBF::solve();
	return 0;
}