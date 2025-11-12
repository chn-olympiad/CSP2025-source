#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100 ;
int n , k , ans , tot ;
int a[N] , sum[N] ;
int f[N][2] ;
int main() {
	freopen( "xor.in" , "r" , stdin ) ; freopen( "xor.out" , "w" , stdout ) ;
	cin>>n>>k ;
	int maxn_jianzhi = 0 ;
	for( int i = 1 ; i <= n ; i++ ) {
		cin>>a[i] ;
		sum[i] = sum[i-1] ^ a[i] ;
		if( sum[i] == k ) tot++ , sum[i] = 0 ;
		maxn_jianzhi = max( maxn_jianzhi, a[i] ) ;
	}
	cout<<tot; 
	return 0 ;
}
