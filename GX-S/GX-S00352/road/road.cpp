#include<bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
const int N = 1e4 + 5;
int n , m , k;
int u[ M ] , v[ M ] , w[ M ];
int w1[ N ];
int main() {
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	cin >> n >> m >> k;
	for (int i = 1 ; i <= m ; i++ ) {
		cin >> u[ i ] >> v[ i ] >> w[ i ];
	}
	for (int i = 1 ; i <= n ; i++ ) {
		cin >> w1[ i ];
	}
	return 0;
}
