#include<bits/stdc++.h>
using namespace std;

int n, m, k, cost;

int main(){
	freopen( "road.in", "r", stdin );
	freopen( "road.out", "w", stdout );
	
	scanf( "%d%d%d", &n, &m, &k );
	for( int i = 0; i < m; i++ ) {
		int u, v, q;
		scanf( "%d%d%d", &u, &v, &q );
		cost += q;
	}
	printf( "%d", cost );
	return 0;
}
