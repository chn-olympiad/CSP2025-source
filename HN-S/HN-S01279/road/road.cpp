#include<bits/stdc++.h>

using namespace std ;

struct node {
	int u , v , w ;
	
	bool operator<( const node &i ) const {
		return w < i.w ;
	}
};

int f[10015] ;
int sz[10015] ;

int F( int x ) {
	return f[x] == x ? x : f[x] = F( f[x] ) ;
}

void S( int u , int v ) {
	if( sz[v] > sz[u] ) {
		swap( u , v ) ;
	}
	f[v] = u ;
}

int c[15] ;
int a[15][10005] ;
int u[1000005] ;
int v[1000005] ;
int w[1000005] ;
long long ans ;

node Edge[1050005] ;

int n , m , k ;

int main() {
  freopen( "road.in" , "r" , stdin ) ;
  freopen( "road.out" , "w" , stdout ) ;
  ios::sync_with_stdio( 0 ) , cin.tie( 0 ) , cout.tie( 0 ) ;
  cin >> n >> m >> k ;
  for( int i = 1 ; i <= m ; i ++ ) {
  	cin >> u[i] >> v[i] >> w[i] ;
	}
	for( int i = 1 ; i <= k ; i ++ ) {
		cin >> c[i] ;
		for( int j = 1 ; j <= n ; j ++ ) {
			cin >> a[i][j] ;
		}
	}
	ans = 1e18 + 7 ;
	for( int x = 0 ; x < 1 << k ; x ++ ) {
		long long cnt = 0 , t = 0 , q = n ;
		for( int i = 1 ; i <= m ; i ++ ) {
			Edge[i] = { u[i] , v[i] , w[i] } ;
		}
		for( int i = 1 ; i <= n ; i ++ ) {
			f[i] = i , sz[i] = 1 ;
		}
		for( int i = 0 ; i < k ; i ++ ) {
			if( x & ( 1 << i ) ) {
				f[++ q] = q , sz[q] = 1 ;
				cnt += c[i + 1] ;
				for( int j = 1 ; j <= n ; j ++ ) {
					++ t ;
					Edge[n + t] = { n + i + 1 , j , a[i + 1][j] } ;
				}
			}
		}
		sort( Edge + 1 , Edge + m + t + 1 ) ;
		for( int i = 1 , j = 1 ; i <= q ; i ++ ) {
			for( ; j <= m + t ; j ++ ) {
				int u = F( Edge[j].u ) , v = F( Edge[j].v ) ;
				if( u != v ) {
					S( u , v ) ;
					cnt += Edge[j].w ;
				}
			}
		}
		ans = min( ans , cnt ) ;
	}
	cout << ans << '\n' ;
  return 0 ;
}
//64pts
