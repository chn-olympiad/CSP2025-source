#include<bits/stdc++.h>

using namespace std ;

const int mod = 998244353 ;

int n , m ;
int ans ;
string s ;
int c[505] ;
long long P[505] ;
int v[505] ;

void dfs( int x , int cnt , int pass ) {
	if( cnt >= m ) {
		ans = ( ans + P[n - x] ) % mod ;
		return ;
	}
	for( int i = n ; i >= 1 ; i -- ) {
		if( !v[i] && pass < c[i] ) {
			v[i] = 1 ;
			dfs( x + 1 , cnt + ( s[x] == '1' ) , pass + ( s[x] == '0' ) ) ;
			v[i] = 0 ;
		}
	}
}

long long pow( long long x ) {
	long long sum = 1 , m = mod - 2 ;
	while( m ) {
		if( m & 1ll ) {
			sum = sum * x % mod ;
		}
		x = x * x % mod ;
		m /= 2 ;
	}
	return sum ;
}

long long C( int n , int m ) {
	if( n < 0 || n + 1 < m ) {
		return 0 ;
	}
	return P[n] * pow( P[m] ) % mod * pow( P[n - m] ) % mod ;
}

int main() {
  freopen( "employ.in" , "r" , stdin ) ;
  freopen( "employ.out" , "w" , stdout ) ;
  cin >> n >> m ;
  cin >> s ;
  int f = 0 , d = 0 ;
  P[0] = 1 ;
  for( int i = 1 ; i <= n ; i ++ ) {
  	P[i] = P[i - 1] * i % mod ;
  	f += s[i - 1] == '1' ;
  	cin >> c[i] ;
  	d += c[i] == 0 ;
	}
	if( n <= 18 || m == 1 || f == n ) {
		sort( c + 1 , c + n + 1 ) ;
		dfs( 0 , 0 , 0 ) ;
		cout << ans ;
	} else if( f < m || n - d < m ) {
		cout << 0 ;
	}
  return 0 ;
}
//20pts
