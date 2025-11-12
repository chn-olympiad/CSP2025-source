#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=505,MOD=998244353;
int n,m,a[MAXN],c[MAXN],lc[MAXN],rc[MAXN];
ll f[MAXN][MAXN],g[MAXN][MAXN],C[MAXN][MAXN],fac[MAXN];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) { char o; cin>>o,a[i]=o=='1'; }
	for(int i=1,x;i<=n;++i) cin>>x,++c[x];
	for(int i=0;i<=n;++i) lc[i]=(i?lc[i-1]:0)+c[i];
	for(int i=n;i>=0;--i) rc[i]=rc[i+1]+c[i];
	for(int i=fac[0]=1;i<=n;++i) fac[i]=fac[i-1]*i%MOD;
	for(int i=0;i<=n;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	f[0][0]=1;
	for(int i=1;i<=n;++i) {
		memset(g,0,sizeof(g));
		for(int j=0;j<i;++j) for(int k=0;k<i;++k) if(f[j][k]) {
			for(int x=0;x<=k&&x<=c[j+1];++x) {
				g[j+1][k-x]=(g[j+1][k-x]+f[j][k]*max(0,lc[j]-(i-1-k))%MOD*C[c[j+1]][x]%MOD*C[k][x]%MOD*fac[x])%MOD;
			}
			if(!a[i]) {
				for(int x=0;x<=k+1&&x<=c[j+1];++x) {
					g[j+1][k+1-x]=(g[j+1][k+1-x]+f[j][k]*C[c[j+1]][x]%MOD*C[k+1][x]%MOD*fac[x])%MOD;
				}
			} else g[j][k+1]=(g[j][k+1]+f[j][k])%MOD;
		}
		memcpy(f,g,sizeof(f));
	}
	ll ans=0;
	for(int j=0;j<=n-m;++j) ans=(ans+f[j][rc[j+1]]*fac[rc[j+1]])%MOD;
	cout<<ans<<"\n";
	return 0;
}
