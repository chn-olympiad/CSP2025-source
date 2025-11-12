#include <bits/stdc++.h>
using namespace std ;
const int mod = 998244353 ;
int n , a[5005] ;
int ans  ;
void dfs ( int x , int sum , int maxx , int b ) {
	
	if ( b > 2 && sum > maxx * 2 ) {
		ans ++ ;
		ans = ans % mod ; 
	}
	
	for ( int i = x + 1 ; i <= n ; i ++ ) {
		dfs ( i , sum + a[i] , max (a[i] , maxx) , b + 1 ) ; 
	}
	
	return ;
}

int main () {
	freopen ("polygon.in" , "r" , stdin ) ;
	freopen ("polygon.out" , "w" , stdout ) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	
//	for ( int k = 3 ; k <= n ; k ++ ) {
//		for ( int i = 1 ; i <= n - k ; i ++ ) {
//			
//		}
//	}
	
	dfs ( 0 , 0 ,  0 , 0 ) ;
	
	cout << ans ;
	
	return 0 ;
}
/*
5
1 2 3 4 5

*/
