#include<bits/stdc++.h>
using namespace std;
long long a[ 5005 ], ans , hod = 998244353 ;
int dfs( int x , int dep , int sum , int k ){
	int c = 0;
	if( dep >= 3 ){
		if( sum > a[ k ] * 2 ){
			c++;
//			cout << "x == " << x << endl;
//			cout << "sum = " << sum << endl;
//			cout << "k = " << k << endl;
		}
	}
	for( int i = x - 1 ; i >= 1 ; i-- ){
		c += dfs( i , dep + 1 , sum + a[ i ] , k );
	}
	return c;
}
int s;
int main(){
	freopen( "polygon.in" , "r" , stdin );
	freopen( "polygon.out" , "w" , stdout );
	cin >> s;
	for( int i = 1 ; i <= s ; i++ ){
		cin >> a[ i ];
	}
	sort( a + 1 , a + s + 1 );
	for( int i = 1 ; i <= s ; i++ ){
		ans += dfs( i , 0 , a[ i ] , i );
	}
	cout << ( ans + ans / 2 ) % hod;
	return 0;
}
