#include<bits/stdc++.h>
using namespace std;
int n , sum , cnt , a[5005] , vis[5005];
void dfs( int k , int u , int op , int io) {
	if ( u > n || k > n ) return ;
	if ( io > op * 2 && u >= 3 ) {
		cnt ++ ;
	}
	dfs( k + 1 , u + 1 , max ( op , a[k + 1]) , io + a[k + 1]);
	dfs( k + 1 , u , op , io) ;
}
int main() {
	freopen( "polygon.in" , "r" , stdin ) ;
	freopen( "polygon.out" , "w" , stdout );
	cin >> n ;
	for ( int i = 1; i <= n ; i ++ ) {
		scanf ( "%d" , &a[i] ) ;
	}
	dfs(0 , 0 , 0 , 0) ;
	cout << cnt ;
	return 0;
}
