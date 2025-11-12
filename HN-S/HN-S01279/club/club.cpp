#include<bits/stdc++.h>

using namespace std ;

struct member {
	int a , b , c ;
	
	bool operator<( const member &i ) const {
		return a > i.a ;
	}
}e[100005];

int n , ans ;
int a[100005] ;

int dp[205][105][105][105] ;

void clear() {
	for( int i = 1 ; i <= n ; i ++ ) {
		for( int j = 0 ; j <= min( i , n / 2 ) ; j ++ ) {
			for( int k = 0 ; k <= min( i - j , n / 2 ) ; k ++ ) {
				int x = j , y = k , z = i - j - k ;
				if( z <= n / 2 ) {
					dp[i][x][y][z] = 0 ;
				}
			}
		}
	}
}

void solve() {
	ans = 0 ;
	int fb = 0 , fc = 0 ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ) {
		cin >> e[i].a >> e[i].b >> e[i].c ;
		fb = max( fb , e[i].b ) ;
		fc = max( fc , e[i].c ) ;
	}
	if( n <= 200 ) {
		clear() ;
		for( int i = 1 ; i <= n ; i ++ ) {
			for( int j = 0 ; j <= min( i , n / 2 ) ; j ++ ) {
				for( int k = 0 ; k <= min( i - j , n / 2 ) ; k ++ ) {
					int x = j , y = k , z = i - j - k ;
					if( z <= n / 2 ) {
						if( x - 1 >= 0 ) {
							dp[i][x][y][z] = max( dp[i][x][y][z] , dp[i - 1][x - 1][y][z] + e[i].a ) ;
						}
						if( y - 1 >= 0 ) {
							dp[i][x][y][z] = max( dp[i][x][y][z] , dp[i - 1][x][y - 1][z] + e[i].b ) ;
						}
						if( z - 1 >= 0 ) {
							dp[i][x][y][z] = max( dp[i][x][y][z] , dp[i - 1][x][y][z - 1] + e[i].c ) ;
						}
						if( i == n ) {
							ans = max( ans , dp[i][x][y][z] ) ;
						}
					}
				}
			}
		}
		cout << ans << '\n' ;
	} else if( !fb && !fc ) {
		sort( e + 1 , e + n + 1 ) ;
		for( int i = 1 ; i <= n / 2 ; i ++ ) {
			ans += e[i].a ;
		}
		cout << ans << '\n' ;
	} else if( !fc ) {
		sort( e + 1 , e + n + 1 ) ;
		for( int i = 1 ; i <= n ; i ++ ) {
			ans += e[i].a ;
			a[i] = e[i].b - e[i].a ;
		}
		sort( a + 1 , a + n + 1 ) ;
		for( int i = n ; i > n / 2 ; i -- ) {
			ans += a[i] ;
		}
		cout << ans << '\n' ;
	}
}

int T ;

int main() {
  freopen( "club.in" , "r" , stdin ) ;
  freopen( "club.out" , "w" , stdout ) ;
  cin >> T ;
  while( T -- ) {
  	solve() ;
	}
  return 0 ;
}
//70pts
