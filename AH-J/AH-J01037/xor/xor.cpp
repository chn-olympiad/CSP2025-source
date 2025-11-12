#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N=500005 ;
const int N2=10000005 ;
ll a[N],b[N],l[N2],r[N2] ;

int main(){
    freopen("xor.in", "r", stdin) ;
    freopen("xor.out", "w", stdout) ;
	ll n,k,ans=0,mmm=0 ;
	cin >> n >> k ;
	for (ll i=1 ; i<=n ; i++){
		cin >> a[i] ;
		if (a[i]==0) mmm++ ;
	}
	ll cnt,sum=1 ;
	for (ll m=1 ; m<=n ; m++){
		cnt=a[m] ;
		for (ll i=m ; i<=n ; i++){
			if (cnt==k) l[sum]=m,r[sum]=i,sum++ ;
			ll lc=cnt ;
			cnt=(lc^a[i+1]) ;
		}
	}
//	for (ll i=1 ; i<sum ; i++){
//		cout << l[i] << " " << r[i] ;
//		cout << endl ;
//	}
	ll minn=1000005,rmin ;
	r[sum]=l[sum-1] ;
	for (ll i=1 ; i<sum ; i++){
//		if (l[i]>s && l[i]>po) po=r[i],ans++ ;
//		minn=min(minn,r[i]) ;
//		if (l[i]>=minn) ans++,minn=r[i] ;
		
		minn=min(minn,r[i]) ;
		if (l[i]>=minn) ans++,minn=r[i+1],rmin=r[i] ;
	}
	if (minn>rmin) ans++ ;
	if (k==0) cout << mmm ;
	else cout << ans ;
	return 0 ;
}
