#include <bits/stdc++.h>
using namespace std ;
int T , n , a[100005] , b[100005] , c[100005] ;
int summ ;

void dfs ( int x , int sum , int aans , int bans , int cans ) {
	if ( x > n ) {
		summ = max ( summ , sum ) ;
		return ;
	}
	
	if ( aans < n / 2 ) {
		dfs ( x + 1 , sum + a[x] , aans + 1 , bans , cans ) ;
	} 
	if ( bans < n / 2 ) {
		dfs ( x + 1 , sum + b[x] , aans , bans + 1 , cans ) ;
	} 
	if ( cans < n / 2 ) {
		dfs ( x + 1 , sum + c[x] , aans , bans , cans + 1 ) ;
	} 
	
	
	
	
	return ;
}

int main () {
	freopen ("club.in" , "r" , stdin) ;
	freopen ("club.out" , "w" , stdout) ;
	
	ios::sync_with_stdio (false) ;
	cin.tie(0) , cout.tie(0) ;
	
	cin >> T ;
	while ( T -- ) {
		cin >> n ;
		summ = -1 ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			cin >> a[i] >> b[i] >> c[i] ;
		}
		
		dfs ( 1 , 0 , 0 , 0 , 0) ;
		cout << summ << endl ;
	} 
	
	
	
	return 0 ;
} 
