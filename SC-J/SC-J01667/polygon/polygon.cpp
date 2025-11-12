#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 5e3 + 7 ;
const int MX = 5e3 + 7 ;
const int MOD = 998244353 ;
int a[N] ;
int dp[2][5][2 * MX][2] ;
signed main() {
	freopen( "polygon.in" , "r" , stdin ) ;
	freopen( "polygon.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	int n ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}sort( a + 1 , a + 1 + n ) ;
	dp[0][0][0][0] = 1 ;
	int cnt = 0 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		memset( dp[ i & 1 ] , 0 , sizeof( dp[ i & 1 ] ) ) ;
		dp[i&1][0][0][0] = 1 ;
		for ( int j = 1 ; j <= min( 3ll , i ) ; j ++ ) {
			for ( int k = 1 ; k <= 2 * a[n] ; k ++ ) {
				dp[i&1][j][k][0] = dp[ ( i - 1 ) & 1 ][j][k][0] + dp[ ( i - 1 ) & 1 ][j][k][1] ;
				dp[i&1][j][k][0] %= MOD ;
				if ( k - a[i] >= 0 ) {
					dp[ i & 1 ][j][k][1] += dp[ ( i - 1 ) & 1 ][ j - 1 ][ k - a[i] ][0] + dp[ ( i - 1 ) & 1 ][ j - 1 ][ k - a[i] ][1] ;
					if ( j == 3 ) {
						dp[ i & 1 ][j][k][1] += dp[ ( i - 1 ) & 1 ][j][ k - a[i] ][0] + dp[ ( i - 1 ) & 1 ][j][ k - a[i] ][1] ;
					}
					dp[ i & 1 ][j][k][1] %= MOD ;
				}
			}
		}
		for ( int j = 1 ; j <= 2 * a[i] ; j ++ ) {
			cnt += dp[ i & 1 ][3][j][1] ;
			cnt %= MOD ;
		}
	}
	int all = 1 ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		all *= 2 ;
		all %= MOD ;
	}all = ( all - n - ( n * ( n - 1 ) / 2 ) - 1 + MOD ) % MOD ;
	cout << ( all - cnt + MOD ) % MOD ; 
	return 0 ;
}
/*
__int128 rp = 0 ;
while ( rp + 1 > 0 )	rp ++ ;
*/
