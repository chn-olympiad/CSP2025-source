#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353,M=(1<<18)+5;
int n,m,f[M][N],c[N],l[M],ans,t[N],fac[N];char s[N];
inline void ad(int &u,int v) {u+=v;(u>=mod&&(u-=mod));}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	fac[0]=1;for(int i=1;i<=n;++i) fac[i]=fac[i-1]*1ll*i%mod;
	for(int i=1;i<=n;++i) scanf("%d",c+i),++t[c[i]];
	if(m==1) {
		for(int i=1;i<=n;++i) t[i]+=t[i-1];
		int cnt=0,now=1;
		for(int i=1;i<=n;++i) if(s[i]=='1') {
			ans=(ans+now*1ll*(n-t[i-1])%mod*fac[n-cnt-1])%mod;
			now=now*1ll*(t[i-1]-cnt)%mod;++cnt;
		}
		printf("%d\n",ans);
		return 0;
	}
	if(m==n) {
		for(int i=n;~i;--i) t[i]+=t[i+1];
		f[n][n]=1;
		for(int i=n;i;--i) {
			for(int j=0;j<=i;++j) {
				f[i-1][j]=(f[i-1][j]+f[i][j])%mod;
				if(s[i]=='1'&&j) f[i-1][j-1]=(f[i-1][j-1]+f[i][j]*1ll*(t[i-j+1]-(n-j)))%mod;
			}
		}
		printf("%d\n",f[0][0]);
		return 0;
	}
	f[0][0]=1;
	for(int i=1;i<(1<<n);++i) l[i]=l[i>>1]+(i&1);
	for(int i=0;i<(1<<n);++i) {
		for(int j=0;j<=l[i];++j) {
			for(int k=1;k<=n;++k) if(!(i&(1<<k-1))) {
				ad(f[i|(1<<k-1)][j+(s[l[i]+1]=='1'&&l[i]-j<c[k])],f[i][j]);
			}
		}
	}
	for(int i=m;i<=n;++i) ad(ans,f[(1<<n)-1][i]);
	printf("%d\n",ans);
	return 0;
}