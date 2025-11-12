#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, a[5010];
unordered_map<int, unordered_map<int, unordered_map<int, int>>>b;
int f ( int x, int y, int z ) {
	if ( x == n )
		return y > z << 1;
	if ( b.count ( x ) && b[x].count ( y ) && b[x][y].count ( z ) )
		return b[x][y][z];
	return b[x][y][z] = ( f ( x + 1, y, z ) + f ( x + 1, y + a[x], max ( z, a[x] ) ) ) % mod;
}
signed main() {
	freopen ( "polygon.in", "r", stdin );
	freopen ( "polygon.out", "w", stdout );
	scanf ( "%lld", &n );
	for ( int i = 0; i < n; i++ )
		scanf ( "%lld", a + i );
	for ( int i = 0; i < n; i++ )
		if ( a[i] ^ 1 ) {
			printf ( "%lld", f ( 0, 0, 0 ) );
			return 0;
		}
	int res = 1, tm = n, bo = 2;
	while ( tm ) {
		if ( tm & 1 )
			( res *= bo ) %= mod;
		( bo *= bo ) %= mod;
		tm >>= 1;
	}
	printf ( "%lld", res - n - ( n - 1 ) *n / 2 - 1 );
	return 0;
}
