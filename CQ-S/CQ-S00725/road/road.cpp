#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
int n, m, k, ans, c[N], fa[N], t[15][N];

struct node{
	int v, u, w;
}s[N];

bool cmp( node x, node y ) {
	return x.w < y.w;
}

int get( int x ) {
	if ( fa[x] == x ) return x;
	return fa[x] = get( fa[x] );
}

int main() {
	freopen( "road.in", "r", stdin );
	freopen( "road.out", "w", stdout );
	cin >> n >> m >> k;
	for ( int i = 1; i <= n; i++ ) fa[i] = i;
	for ( int i = 1; i <= m; i++ ) cin >> s[i].v >> s[i].u >> s[i].w;
	for ( int i = 1; i <= k; i++ ) {
		cin >> c[i];
		for ( int j = 1; j <= n; j++ ) cin >> t[i][j]; 
	}
	sort( s + 1, s + m + 1, cmp );
	for ( int i = 1; i <= m; i++ ) {
		int u = s[i].u, v = s[i].v, w = s[i].w;
		if ( get( u ) == get( v ) ) continue;
		else {
			int minn = INT_MAX;
			for ( int i = 1; i <= k; i++ ) {
				minn = min( minn, c[i] + t[i][u] + t[i][v] );
			}
			ans += min( w, minn );
			fa[u] = v;
		}
	}
	cout << ans;
	fclose( stdin );
	fclose( stdout );
	return 0;
}
