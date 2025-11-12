#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int M = 1e4 + 5;

struct node {
  int u, v, w;
} g[N], p[N], t[N];

int fa[N], n, m, k, f[15][M], cst[15];

int find ( int x ) {
  return fa[x] == x ? x : fa[x] = find ( fa[x] );
}

long long doit ( int x ) {
  for ( int i = 1; i < n; i ++ ) t[i] = p[i];
  for ( int i = 1; i <= n + 10; i ++ ) fa[i] = i;
  int d = n - 1;
  for ( int i = 0; i < k; i ++ ) {
    if ( ( x >> i ) & 1 ) {
      for ( int j = 1; j <= n; j ++ ) 
        t[++ d] = { n + i + 1, j, f[i][j] };
    }
  }
  sort ( t + 1, t + d + 1, [ ] ( node x, node y ) { return x.w < y.w; } );
  long long ans = 0;
  for ( int i = 1; i <= d; i ++ ) {
    int x = find ( t[i].u ), y = find ( t[i].v );
    if ( x == y ) continue;
    fa[x] = y; ans += t[i].w;
  }
  return ans;
}

int main ( ) {
  freopen ( "road.in", "r", stdin );
  freopen ( "road.out", "w", stdout );
  ios::sync_with_stdio ( false );
  cin.tie ( 0 ), cout.tie ( 0 );
  cin >> n >> m >> k;
  for ( int i = 1; i <= n; i ++ ) fa[i] = i;
  for ( int i = 1; i <= m; i ++ )
    cin >> g[i].u >> g[i].v >> g[i].w;
  sort ( g + 1, g + m + 1, [ ] ( node x, node y ) { return x.w < y.w; } );
  int cnt = 0; long long gg = 0;
  for ( int i = 1; i <= m; i ++ ) {
    int x = g[i].u, y = g[i].v;
    if ( find ( x ) == find ( y ) ) continue;
    p[++ cnt] = g[i]; fa[find ( x )] = find ( y );
    gg += g[i].w;
  }
  // cout << gg << "\n";
  for ( int i = 0; i < k; i ++ ) {
    cin >> cst[i];
    for ( int j = 1; j <= n; j ++ ) cin >> f[i][j];
  }
  long long ans = 1e18; 
  for ( int i = 0; i < 1 << k; i ++ ) {
    long long sum = 0;
    for ( int j = 0; j < k; j ++ )
      if ( ( i >> j ) & 1 ) sum += cst[j];
    sum += doit ( i );
    ans = min ( ans, sum );
  }  
  // cout << doit ( 4 ) << "\n";
  cout << ans << "\n";
}