#include <bits/stdc++.h>
//
#define LL long long
using namespace std ;
const LL N=5500,P=998244353 ;
LL n,a[N],b[N],t,f[N],s,S,ans,c[N] ;
LL ksp (LL a,LL b)   {
	LL ans=1;
	while (b) {
		if (b&1) (ans*=a)%=P ;
		(a*=a)%=P ;
		b/=2; 
	} return ans ;
}
int main () {
	freopen ("polygon.in","r",stdin) ;
	freopen ("polygon.out","w",stdout) ;
//	freopen ("hh","w",stdout) ;
	cin>>n;
	bool ky=1 ;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]>1) ky=0 ;
	}
	sort(a+1,a+n+1);
	if (ky) {
		for (int i=1;i<=n;i++) {
			if (a[i]==1) s++;
		}
		ans=ksp(2,s)-1-s-(s-1)*s%P*ksp(2,P-2)%P ;
		(ans+=P)%=P ;
		cout<<ans;return 0 ;
	}
	for (LL i=1;i<=n;i++) {
//		cout<<a[i]<<" " ;
		S=t=0 ;
		for (LL j=1;j<=n;j++) {
			c[i]=0 ;
			if (a[i]>=a[j] && i!=j) b[++t]=a[j],S+=a[j] ;
			else break ;
		} 
		memset  (f,0,sizeof f) ;
		s=(ksp (2,t)-1+P)%P ;
		ans+=s; ans%=P ;
		for (LL j=1;j<=t;j++) {
			for (LL k=a[i];k>=b[j];k--){
				(f[k]+=f[k-b[j]])%=P ;
			}
			f[b[j]]+=1 ; f[b[j]]%=P;
		}
		for (LL k=a[i];k>=1;k--){
			ans-=f[k] ; (ans+=P)%=P ;
		}
		(ans+=P)%=P ;
//		cout<<ans<<"\n" ;
	}
	cout<<ans;
	return 0 ;
}
