#include<bits/stdc++.h>
#define ll long long
#define mod 998244353 
using namespace std;
void fil() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout) ;
}
ll qm(ll x,ll y) {
	ll ret=1;
	while(y) {
		if(y%2) ret=ret*x%mod ;
		x=x*x%mod ;y/=2 ;
	}
	return ret ;
}
const ll N=1000010 ;
ll fac[N],inv[N] ;
ll pref[N],c[N] ;
void init() {
	fac[0]=1;
	for(int i=1;i<N;i++) fac[i]=fac[i-1]* i%mod ;
	inv[N-1]=qm(fac[N-1],mod-2) ;
	for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod ;
}
ll C(ll x,ll y) {
	if(y>x) return 0;
	return fac[x]*inv[y]%mod *inv[x-y] %mod ;
}
ll n,m ;
ll pri=0;
char s[N] ;
int main() 
{
	fil() ;
	init() ;
	scanf("%lld%lld",&n,&m) ;
	scanf("%s",s+1) ;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&c[i]) ; 
	}
	sort(c+1,c+n+1) ;
	for(int i=0;i<(1<<n);i++) {
		ll flag=0,cnt=0;
		for(int j=1;j<=n;j++) {
			if(s[j]=='0'&&(i&(1<<j-1))) {
				flag=1;
			}
			if((i&(1<<j-1))) cnt++;
		}
		if(flag) continue ;
		if(cnt<m) continue ;
		for(int j=1;j<=n;j++) {
			pref[j]=pref[j-1]+((i&(1<<j-1))==0) ;
		}
		ll cntt=0;
		for(int j=1;j<=n;j++) {
			if((i&(1<<j-1))){
				pref[++cntt]=pref[j] ;
			}
		}
		sort(pref+1,pref+cntt+1) ;
		ll ans=1;
		ll zz=n+1;
		for(int j=cntt;j>=1;j--) {
			while(c[zz-1]>pref[j]&&zz-1>=1) {
				zz-- ;
			}
			ll tim=n-zz+1-(cntt-j) ;
			if(tim<0) {
				ans=0;break ;
			}
			ans=ans*tim%mod ;
		}
		ans*=fac[n-cnt] ;ans%=mod ; 
		pri+=ans ;pri%=mod ;
	}
	printf("%lld\n",pri) ;
	return 0;
}
/*
3 2
101
1 1 2
*/
