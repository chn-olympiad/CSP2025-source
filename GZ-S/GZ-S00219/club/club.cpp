//GZ-S00219   ¿Ó≈‡Íª    ±ı∫˛÷–—ß
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5 ;
int t , n ;
int s1 , s2 , s3 ;
int ans ;
int maxn ;
bool f ;
int sum[3][5] ;
int cnt ;
int ans1[N] ;


struct num {
	int x ;
	int y ;
	int z ;
	int is_use ;
} a[N];

bool cmp1 ( num a , num b ) {
	if( a.x > b.x ) {
		return true ;
	} else if( a.x == b.x ) {
		if( a.y < b.y ) {
			return true ;
		} else if( a.y == b.y ) {
			if( a.z < b.z ) {
				return true ;
			} else {
				return false ;
			}
		} else {
			return false ;
		}
	} else {
		return false ;
	}
}

bool cmp2 ( num a , num b ) {
	if( a.y > b.y ) {
		return true ;
	} else if( a.y == b.y ) {
		if( a.z < b.z ) {
			return true ;
		} else {
			return false ;
		}
	} else {
		return false ;
	}
}

bool cmp3 ( num a , num b ) {
	if( a.z > b.z ) {
		return true ;
	} else {
		return false ;
	}
}

int main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin >> t ;
	while( t-- ) {

		cnt++ ;

		cin >> n ;

		for( int i = 1 ; i <= n ; i++ ) {
			scanf( "%d%d%d" , &a[i].x , &a[i].y , &a[i].z ) ;
			if( a[i].y != 0 || a[i].z != 0 ) {
				f = true ;
			}
			a[i].is_use = 0 ;
		}

		if( n == 2 ) {
			for( int i = 1 ; i <= n ; i++ ) {
				sum[i][1] = a[i].x ;
				sum[i][2] = a[i].y ;
				sum[i][3] = a[i].z ;
			}
			for( int i = 1 ; i <= 3 ; i++ ) {
				for( int j = 1 ; j <= 3 ; j++ ) {
					if( i != j ) {
						ans = max( ans , sum[1][i] + sum[2][j] ) ;
					}
				}
			}
			ans1[cnt] = ans ;
			s1 = 0 ;
			s2 = 0 ;
			s3 = 0 ;
			ans = 0 ;
			continue ;
		}

		if( f == false ) {
			sort( a + 1 , a + n + 1 , cmp1 ) ;
			for( int i = 1 ; i <= n / 2 ; i++ ) {
				ans += a[i].x ;
			}
			ans1[cnt] = ans ;
			s1 = 0 ;
			s2 = 0 ;
			s3 = 0 ;
			ans = 0 ;
			continue ;
		}

		sort( a + 1 , a + n + 1 , cmp1 ) ;

		for( int i = 1 ; i <= n ; i++ ) {
			if( s1 < n / 2 && a[i].x > a[i].y && a[i].x > a[i].z && a[i].is_use == 0 ) {
				ans += a[i].x ;
				a[i].is_use = 1 ;
				s1++ ;
			}
		}

		sort( a + 1 , a + n + 1 , cmp2 ) ;

		for( int i = 1 ; i <= n ; i++ ) {
			if( s2 < n / 2 && a[i].y > a[i].z && a[i].is_use == 0 ) {
				ans += a[i].y ;
				a[i].is_use = 1 ;
				s2++ ;
			}
		}
		sort( a + 1 , a + n + 1 , cmp3 ) ;
		for( int i = 1 ; i <= n ; i++ ) {
			if( s3 < n / 2 && a[i].z > a[i].y && a[i].z > a[i].x && a[i].is_use == 0 ) {
				ans += a[i].z ;
				a[i].is_use = 1 ;
				s3++ ;
			}
		}
		if( s3 + s2 + s1 != n ) {
			for( int i = 1 ; i <= n ; i++ ) {
				if( a[i].is_use == 0 ) {
					if( s1 < n / 2 ) {
						ans += a[i].x ;
						s1++ ;
					} else if( s2 < n / 2 ) {
						ans += a[i].y ;
						s2++ ;
					} else if( s3 < n / 2 ) {
						ans += a[i].z ;
						s3++ ;
					}
				}
			}
			ans1[cnt] = ans ;
		} else {
			ans1[cnt] = ans ;
		}
		s1 = 0 ;
		s2 = 0 ;
		s3 = 0 ;
		ans = 0 ;
	}

	for( int i = 1 ; i <= cnt ; i++ ) {
		cout << ans1[i] << "\n" ;
	}
	return 0 ;
	
}
