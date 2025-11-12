#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100 , mod = 998244353 ;
int a[N] ;
int n , tot ; 
//void dfs( int max1 , int min1 , int min2 , int sum , int num , int dep ) {
//	if( sum > 2 * max1 && num >= 3 ) { tot++ , tot %= mod ; } 
//	if( dep > n ) return ;
//	if( num == 0 ) dfs( a[dep] , a[dep] , a[dep] , a[dep] , num + 1 , dep + 1 ) ;
//	else if( num == 1 ) dfs( a[dep] , min1 , a[dep] , sum + a[dep] , num + 1 , dep + 1 ) ;
//	else if( num == 2 ) dfs( a[dep] , min1 , min2 , sum + a[dep] , num + 1 , dep + 1 ) ;
//	else { if( sum > ( a[dep] >> 1 ) ) dfs( a[dep] , min1 , min2 , sum + a[dep] , num + 1 , dep + 1 ) ; else return ; }
//	dfs( max1 , min1 , min2 , sum , num , dep + 1 ) ;
//}
void dfs( int x , int y_1 , int y_2 , int sum , int dep , int num ) {
	if( sum > 2 * x && num >= 3 ) {
		tot++ , tot %= mod ;
//		cout<<sum<<" "<<x*2<<" "<<num<<endl; 
	} 		
	if( dep > n ) return ;
	if( num == 0 ) dfs( a[dep] , a[dep] , a[dep] , a[dep] , dep + 1 , num + 1 ) ;
	else if( num == 1 ) dfs( a[dep] , y_1 , a[dep] , a[dep] + y_1 , dep + 1 , num + 1 ) ;
	else if( num == 2 ) dfs( a[dep] , y_1 , y_2 , sum+a[dep] , dep+1 , num+1 ) ;
	else dfs( a[dep] , y_1 , y_2 , sum + a[dep] , dep+1 , num + 1 ) ; 
	dfs( x , y_1 , y_2 , sum , dep+1 , num ) ; 
} 
int main() {
	freopen( "polygon.in" , "r" , stdin ) ; freopen( "polygon.out" , "w" , stdout ) ;
	cin>>n ; 
	for( int i = 1 ; i <= n ; i++ ) cin>>a[i] ;
	sort( a + 1 , a + n + 1 ) ;
	dfs( 0 , 0 , 0 , 0 , 1 , 0 ) ;
	cout<<tot - 2 ;
	return 0 ;
}
