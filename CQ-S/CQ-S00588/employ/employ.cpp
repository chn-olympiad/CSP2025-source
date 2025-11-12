#include <bits/stdc++.h>
using namespace std;

namespace Cherry {
	#define Add(x,y) (x+y<mod?x+y:x+y-mod)
	#define Del(x,y) (x<y?x-y+mod:x-y)
	const int N=505;
	const long long mod=998244353;
	int n,m;
	int a[N];
	char s[N];
	
	namespace Q1 {
		int ans;
		int f[(1<<18)+10][20];
		void solve() {
			f[0][0]=1;
			for(int S=0;S<(1<<n);S++) {
				int cnt=__builtin_popcount(S);
				for(int i=0;i<=cnt;i++) {
					if(!f[S][i]) continue;
					for(int j=1;j<=n;j++) {
						if(!((S>>(j-1))&1)) {
							int S2=S^(1<<(j-1));
							if(s[cnt+1]=='1'&&cnt-i<a[j]) f[S2][i+1]=Add(f[S2][i+1],f[S][i]);
							else f[S2][i]=Add(f[S2][i],f[S][i]);
						}
					}
				}
			}
			for(int i=m;i<=n;i++) ans=Add(ans,f[(1<<n)-1][i]);
			printf("%d\n",ans);
		}
	}
	
	namespace Q2 {
		int fac[N],cnt[N];
		void solve() {
			fac[0]=1;
			for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
			for(int i=1;i<=n;i++) cnt[a[i]]++;
			for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
			int ans=1,num=0;
			for(int i=1;i<=n;i++) {
				if(s[i]=='1') {
					if(cnt[i-1]<=num) ans=0;
					ans=1ll*ans*(cnt[i-1]-num)%mod;
					num++;
				}
			}
			ans=1ll*ans*fac[n-num]%mod;
			printf("%lld\n",Del(fac[n],ans));
		}
	}
	
	namespace Q3 {
		int ans=1;
		void solve() {
			for(int i=1;i<=n;i++) if(s[i]=='0'||!a[i]) ans=0;
			for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
			printf("%d\n",ans);
		}
	}
	
	int main() {
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		if(n<=18) return Q1::solve(),0;
		if(m==1) return Q2::solve(),0;
		if(m==n) return Q3::solve(),0;
		printf("0\n");

		return 0;
	}
}

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Cherry::main(); 

	return 0;
}
