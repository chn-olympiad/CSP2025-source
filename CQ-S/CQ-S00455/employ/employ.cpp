#include<bits/stdc++.h>
#define ll long long
#define N 1005
#define mod 998244353
using namespace std;
inline ll qmi(ll a,ll b,ll p){
	ll res = 1%p,t = a;
	while(b){
		if(b&1) res=res*t%p;
		t=t*t%p;
		b>>=1;
	}
	return res;
}
ll n,m,i,j,k,l,c[N],jc[N],inv[N],C[N][N],ans,zer,one,f[N][N],g[N][N],pre,qzh[N],chs,cnt[N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,s+1);
	C[0][0]=1;
	for(i=0;i<=1000;i++){
		for(j=0;j<=1000;j++){
			if(i) C[i][j]+=C[i-1][j];
			if(i&&j) C[i][j]+=C[i-1][j-1];
			if(C[i][j]>=mod) C[i][j]-=mod;
		}
	}
	for(i=1;i<=n;i++) scanf("%lld",&c[i]),qzh[c[i]]++,cnt[c[i]]++;
	for(i=1;i<=1000;i++) qzh[i]+=qzh[i-1];
	jc[0]=1;
	for(i=1;i<=1000;i++) jc[i]=jc[i-1]*i%mod;
	inv[1000]=qmi(jc[1000],mod-2,mod);
	for(i=1000;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	for(i=1;i<=n;i++) zer+=(s[i]=='0'),one+=(s[i]=='1');
	f[0][0] = 1;
	for(i=1;i<=n;i++){
		if(s[i]=='0'){
			for(j=0;j<=n;j++){
				for(k=0;k<=chs;k++){
					if(!f[j][k]) continue;
					for(l=0;l<=cnt[j+pre+1];l++) g[j][k+l] = (g[j][k+l]+f[j][k]*C[chs-k][l]%mod*C[cnt[j+pre+1]][l]%mod*jc[l])%mod;
				}
			}
			pre++;
		}
		else{
			for(j=0;j<=n;j++){
				for(k=0;k<=chs;k++){
					if(!f[j][k]) continue;
					g[j][k] = (g[j][k]+f[j][k])%mod;
					for(l=0;l<=cnt[j+pre+1];l++) g[j+1][k+1+l] = (g[j+1][k+1+l]+f[j][k]*C[chs-k][l]%mod*C[cnt[j+pre+1]][l]%mod*jc[l]%mod*(qzh[j+pre]-k))%mod;
				}
			}
			chs++;
		}
		for(j=0;j<=n;j++) for(k=0;k<=n;k++) f[j][k]=g[j][k],g[j][k]=0;
	}
	for(i=0;i<=one-m;i++) for(j=0;j<=chs;j++) if(f[i][j]&&n-qzh[i+pre]>=0) ans=(ans+f[i][j]*C[n-qzh[i+pre]][chs-j]%mod*jc[chs-j]%mod)%mod;
	ans=ans*jc[zer]%mod;
	printf("%lld\n",ans);
	return 0;
}
