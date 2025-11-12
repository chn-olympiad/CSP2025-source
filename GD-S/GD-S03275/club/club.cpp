#include<bits/stdc++.h>
using namespace std;
int t , n , a[100005][3] , d[100005] , u[100005] , v[100005] , w[100005];
int main() {
	freopen( "club.in" , "r" , stdin );
	freopen( "club.out" , "w" , stdout);
	scanf ( "%d" , &t );
	while ( t -- ) {
		long long sum = 0 ;
		int x = 0 , y = 0 , z = 0 , tp = 0 ;
		memset( a , 0 , sizeof(a) ) ;
		memset(u , 0 , sizeof(u));
		memset(v , 0 , sizeof(v));
		memset(w , 0 , sizeof(w));
		scanf ( "%d" , &n );
		for ( int i = 1; i <= n ; i ++ ) {
			scanf ( "%d%d%d" , &a[i][1] , &a[i][2] , &a[i][3] ) ;
			tp = max ( a[i][1] , max ( a[i][2] , a[i][3]));
			if ( tp == a[i][1] ) {
				u[++x] = i;
			} else if ( tp == a[i][2]) {
				v[++y] = i;
			} else {
				w[++z] = i;
			}
			sum += tp;
		}
		if ( x > n / 2 ) {
			int o = x - ( n / 2 ) , l[100005] , cnt = 0;
			for ( int i = 1; i <= x ; i ++ ) {
				l[++cnt] = a[u[i]][1] - max ( a[u[i]][2] , a[u[i]][3] );
			}
			sort ( l + 1, l + cnt + 1 );
			for ( int i = 1 ; i <= o ; i ++ ) {
				sum -= l[i];
			}
		} else if ( y > n / 2 ) {
			int o = y - ( n / 2 ) , l[100005] , cnt = 0;
			for ( int i = 1; i <= y ; i ++ ) {
				l[++cnt] = a[v[i]][2] - max ( a[v[i]][1] , a[v[i]][3] );
			}
			sort ( l + 1, l + cnt + 1 );
			for ( int i = 1 ; i <= o ; i ++ ) {
				sum -= l[i];
			}
		} else if ( z > n / 2 ) {
			int o = z - ( n / 2 ) , l[100005] , cnt = 0;
			for ( int i = 1; i <= z ; i ++ ) {
				l[++cnt] = a[w[i]][3] - max ( a[w[i]][2] , a[w[i]][1] );
			}
			sort ( l + 1, l + cnt + 1 );
			for ( int i = 1 ; i <= o ; i ++ ) {
				sum -= l[i];
			}
		}
		cout << sum << endl ;
	}
	return 0;
}
