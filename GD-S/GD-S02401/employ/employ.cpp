#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;
const int N=500,P=998244353;
int n,m,a[N+2];
char t[N+2];
int fac[N+2],ifac[N+2];
int qpow(int a,int n) {
	int x=1;
	for(; n; n>>=1,a=1ll*a*a%P) if(n&1) x=1ll*x*a%P;
	return x;
}
inline int C(int n,int m) {
	return m<0||m>n?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
inline void Add(int &x,int y) { (x+=y)<P||(x-=P); }
namespace sub0 {
	const int N=18;
	int f[1<<N][N+2],c[1<<N];
	void solve() {
		for(int i=0; i<N; ++i) for(int j=0; j<1<<i; ++j) c[j|1<<i]=c[j]+1;
		f[0][0]=1;
		for(int i=0; i<1<<n; ++i)
			for(int j=0; j<=n; ++j) if(f[i][j])
				for(int k=0; k<n; ++k) if(!(i>>k&1))
					Add(f[i|1<<k][j+(j>=a[k+1]||t[c[i]+1]=='0')],f[i][j]);
		int ans=0;
		for(int i=0; i<=n-m; ++i) Add(ans,f[(1<<n)-1][i]);
		printf("%d\n",ans);
	}
}
namespace subA {
	int f[N+2],g[N+2],c[N+2],s[N+2];
	void solve() {
		for(int i=1; i<=n; ++i) ++c[a[i]];
		partial_sum(c,c+n+1,s);
		f[c[0]]=1;
		for(int i=1; i<=n; ++i) {
			memset(g,0,sizeof(g));
			for(int j=0; j<=s[i-1]; ++j) {
				if(j<i) {
					Add(g[j],1ll*f[j]*C(s[i],s[i-1])%P);
					continue;
				}
				for(int k=0; k<=c[i]; ++k) {
					Add(g[j+k],1ll*f[j]*C(j-i+k,k)%P*C(s[i-1]-j+i-1+c[i]-k,c[i]-k)%P);
				}
			}
			memcpy(f,g,sizeof(f));
		}
		int ans=0;
		for(int i=0; i<=n-m; ++i) Add(ans,f[i]);
		for(int i=0; i<=n; ++i) ans=1ll*ans*fac[c[i]]%P;
		printf("%d\n",ans);
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=1ll*fac[i-1]*i%P;
	ifac[N]=qpow(fac[N],P-2);
	for(int i=N; i>=1; --i) ifac[i-1]=1ll*ifac[i]*i%P;
	scanf("%d%d%s",&n,&m,t+1);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	if(n==m) {
		if(count(t+1,t+n+1,'0')||*min_element(a+1,a+n+1)==0) return printf("0\n"),0;
		printf("%d\n",fac[n]);
		return 0;
	}
	if(n<=18) sub0::solve();
	else subA::solve();
	return 0;
}