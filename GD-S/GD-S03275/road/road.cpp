#include<bits/stdc++.h>
using namespace std;
int n , m , k , ans , o[25] , fa[20005] , b[12][10005] ;
struct s {
	int x , y , z;
}a[150005];
bool cmp ( s xx , s yy ) {
	return xx.z < yy.z;
}
int find( int x ) {
	if ( fa[x] == x) {
		return x;
	}
	return fa[x] = find(fa[x]);
}
int main() {
	freopen( "road.in" , "r" , stdin );
	freopen( "road.out" , "w" , stdout );
	cin >> n >> m >> k ;
	for ( int i = 1; i <= m ; i ++ ) {
		scanf ( "%d%d%d" , &a[i].x , &a[i].y , &a[i].z );
	}
	int s = 1;
	for ( int i = 1; i <= k ; i++ ) {
		scanf ( "%d" , &o[i]) ;
		for ( int j = 1; j <= n ;j ++ ) {
			scanf ( "%d" , &b[i][j] ) ;
			a[m + s].x = j;
			a[m + s].y = i + n ;
			a[m + s].z = b[i][j];
			++ s;
		}
	}
	long long cnt = 0 , op = 0;
	long long sum = 0;
	for ( int i = 1 ; i <= n + k ; i ++ ) {
		fa[i] = i;
	}
	sort ( a + 1 , a + m + s + 1, cmp ) ;
	for ( int i = 1; i <= m + s ; i ++ ) {
		int u = find(a[i].x);
		int v = find(a[i].y);
		if ( u == v) {
			continue;
		}
		fa[u] = v;
		cnt ++ ;
		sum += a[i].z;
		if ( a[i].x > n ) op ++;
		if ( a[i].y > n ) op ++ ;
		if ( cnt == n + op - 1) {
			break;
		}
	}
	cout << sum;
	return 0;
}
