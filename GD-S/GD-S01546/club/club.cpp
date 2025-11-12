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
const int N=100099;
int T,n,a[N][3]={},c[3]={},p[N]={},val[N]={};
bool ED;
int main()
{
	usefile("club");
	int i,maxp; ll ans=0;
	read(T);
	loop : --T;
	read(n),c[0]=c[1]=c[2]=0;
	for(i=1,ans=0;i<=n;++i) {
		read(a[i][0],a[i][1],a[i][2]);
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
			++c[0],ans+=a[i][0],p[i]=0;
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
			++c[1],ans+=a[i][1],p[i]=1;
		else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1])
			++c[2],ans+=a[i][2],p[i]=2;
	}
	if(c[0]<=(n>>1)&&c[1]<=(n>>1)&&c[2]<=(n>>1)) {
		printf("%lld\n",ans);
	} else {
		if(c[0]>(n>>1)) maxp=0;
		else if(c[1]>(n>>1)) maxp=1;
		else if(c[2]>(n>>1)) maxp=2;
		for(i=1;i<=n;++i) {
			if(p[i]==maxp) {
				if(maxp==0) val[i]=max(a[i][1],a[i][2])-a[i][0];
				else if(maxp==1) val[i]=max(a[i][0],a[i][2])-a[i][1];
				else if(maxp==2) val[i]=max(a[i][0],a[i][1])-a[i][2];
			} else val[i]=-1e9;
		}
		sort(val+1,val+1+n,greater<int>());
		for(i=1;i<=c[maxp]-(n>>1);++i)
			ans+=val[i];
		printf("%lld\n",ans);
	}
	if(T) goto loop;
}