#include<bits/stdc++.h>
#define sf scanf 
#define pf printf  
#define rep(x,y,z) for(int x=y;x<=z;x++) 
#define per(x,y,z) for(int x=y;x>=z;x--) 
using namespace std;
typedef long long ll;
namespace wing_heart {
	constexpr int N=5e2+7,mod=998244353;
	struct modint {
		int x;
		modint (int y=0) : x(y) {}
		modint operator + (modint b) const { return x+b.x<mod ? x+b.x : x+b.x-mod; }
		modint operator * (modint b) const { return 1ll*x*b.x%mod; }
		modint &operator += (modint &b) { return *this = *this + b; }
		modint &operator *= (modint &b) { return *this = *this * b; }
	};
	int n,m;
	char s[N];
	int c[N];
	namespace sub1 {
		constexpr int M=18;
		modint f[1<<M][M];
		void main() {
			f[0][0] = 1;
			rep(i,0,(1<<n)-2) {
				int siz = __builtin_popcount(i);
				rep(j,0,siz) if(f[i][j].x) {
					modint F = f[i][j];
					rep(k,1,n) if(!((i>>(k-1))&1)) {
						int v = i|(1<<(k-1));
						if(c[k]<=j || s[siz+1]=='0') f[v][j+1] += F;
						else f[v][j] += F;
					}
					// pf("%d %d %d\n",i,j,f[i][j].x);
				}
			}
			modint ans=0;
			rep(i,0,n-m) ans+=f[(1<<n)-1][i];
			pf("%d\n",ans.x);
			exit(0);
		}
	}
	namespace sub2 {
		void main() {
			rep(i,1,n) if(s[i]=='0') puts("0"), exit(0);
			rep(i,1,n) if(c[i]==0) puts("0"), exit(0);
			modint ans=1;
			rep(i,1,n) ans=ans*i;
			pf("%lld\n",ans.x);
			exit(0);
		}
	}
	void main() {
		sf("%d%d",&n,&m);
		sf("%s",s+1);
		rep(i,1,n) sf("%d",&c[i]);
		if(n<=18) sub1 :: main();
		if(m==n) sub2 :: main();
	}
} 
int main() {
	#ifdef LOCAL 
	// freopen("in.txt","r",stdin);
	freopen("my.out","w",stdout);
	#else 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif 
	wing_heart :: main();
}