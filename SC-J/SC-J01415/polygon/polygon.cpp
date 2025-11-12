#include<bits/stdc++.h>
using namespace std ;
const int N=5010 , Mod=998244353 ;
#define ll unsigned long long
ll a[N] , dp[2*N] , n ;
int main() {
	freopen("polygon.in","r",stdin) ;
	freopen("polygon.out","w",stdout) ;
	cin>> n ;
	for ( int i=1 ; i<=n ; i++ ) {
		cin>> a[i] ;
	}
	ll s=0 ;
	sort(a+1,a+1+n) ;
//	for ( int i=1 ; i<=n ; i++ ) {
//		cout<< a[i] << " " ;
//	}
//	cout<< endl ;
	for ( int i=1 ; i<=n ; i++ ) {
		for ( int j=10001-a[i] ; j<=10000 ; j++ ) {
			dp[10001]+=dp[j] ;
			dp[10001]%=Mod ;
		}
		for ( int j=10000 ; j>a[i] ; j-- ) {
			dp[j]+=dp[j-a[i]] ;
			dp[j]%=Mod ;
			if ( i>=3 && j>=2*a[i]+1 ) {
				s+=dp[j-a[i]] ;
				s%=Mod ;
			}
		}
		dp[a[i]]++ ;
//		for ( int j=1 ; j<=6 ; j++ ) {
//			cout<< dp[j] << " " ;
//		}
//		cout<< endl ;
	}
	cout<< s ;
	return 0 ;
}