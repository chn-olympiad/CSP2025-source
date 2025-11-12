#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
ll n,m,p[N],t[N],ts[N],dp[N][N][N],inv[N],fac[N];
const ll mod=998244353;
ll qpow(ll a,ll b){
	ll res=1ll;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod,b>>=1;
	} return res;
}
ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		ll a;scanf("%1lld",&a);
		p[i]=p[i-1]+(a==0);
	}
	for(ll i=1;i<=n;i++){
		ll a;scanf("%lld",&a);
		t[a]++;
	}
	ts[0]=t[0];
	for(ll i=1;i<=n;i++) ts[i]=ts[i-1]+t[i];
	fac[0]=1;
	for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(ll i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	dp[0][0][t[0]]=1;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<=i;j++){
			for(ll s=max(ts[j+p[i]]-i,0ll);s<=ts[j+p[i]];s++){
				if(p[i+1]>p[i]){
					for(ll o=0;o<=t[j+p[i]+1];o++){
//						(dp[i+1][j][s+t[j+p[i]+1]-o-1]+=dp[i][j][s]*C(i+s-ts[j+p[i]]+1,o)%mod*C(t[j+p[i]+1],o)%mod*fac[o]%mod)%=mod;
						(dp[i+1][j][s+t[j+p[i]+1]-o]+=dp[i][j][s]*C(i+s-ts[j+p[i]],o-1)%mod*C(t[j+p[i]+1],o)%mod*fac[o]%mod)%=mod;//==j+1
						(dp[i+1][j][s+t[j+p[i]+1]-o]+=dp[i][j][s]*C(i+s-ts[j+p[i]],o)%mod*C(t[j+p[i]+1],o)%mod*fac[o]%mod)%=mod;//>j+1
						if(s>0) (dp[i+1][j][s+t[j+p[i]+1]-o-1]+=dp[i][j][s]*C(i+s-ts[j+p[i]],o)%mod*C(t[j+p[i]+1],o)%mod*fac[o]%mod)%=mod;//<=j
					}
				}
				else{
					if(s>0) (dp[i+1][j+1][s-1+t[j+p[i]+1]]+=dp[i][j][s]*s%mod)%=mod;
					if(n>i+s) (dp[i+1][j][s]+=dp[i][j][s])%=mod; 
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n-p[n]-m;i++){
		ll o=dp[n][i][0],r=n-ts[i+p[n]];
//		printf("%lld %lld %lld\n",i,o,r);
		for(ll j=i+p[n]+1;j<=n;j++){
			if(!t[j]) continue;
			o=o*C(r,t[j])%mod*fac[t[j]]%mod;
			r-=t[j];
		}
		(ans+=o)%=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
