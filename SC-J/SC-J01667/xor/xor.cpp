#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 7 ;
unordered_map< int , int > p ;
int a[N] ;
int dp[N] ;
signed main() {
	freopen( "xor.in" , "r" , stdin ) ;
	freopen( "xor.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n , k ;
	cin >> n >> k ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}int mx = 0 ;
	int now = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		now ^= a[i] ;
		dp[i] = dp[ i - 1 ] ;
		if ( now == k )	dp[i] = max( dp[i] , 1 ) ;
		if ( p[ k ^ now ] != 0 ) {
			dp[i] = max( dp[i] , dp[ p[ k ^ now ] ] + 1 );
		}p[now] = i ;
		mx = max( mx , dp[i] ) ;
	}cout << mx ;
	return 0 ;
}
