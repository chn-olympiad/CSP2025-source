#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define ll long long
const int N = 1e4 + 100 , M = 1e6 + 1e5 + 5;
int n , m , k;
struct edge { int u , v , w; } e[ M ];
int w[ 11 ][ N ] , c[ 11 ] , sz[ N ] , fa[ N ];
bool vis[ M ];
int find ( int x ) { return x == fa[ x ] ? x : fa[ x ] = find ( fa[ x ] ); }
void merge ( int x , int y )
{
  x = find ( x ) , y = find ( y );
  if ( x == y ) return;
  if ( sz[ x ] > sz[ y ] ) swap ( x , y );
  sz[ y ] += sz[ x ] , fa[ x ] = y;
}
ll ans = 0;
ll solve ( int s , ll ans )
{
  iota ( fa + 1 , fa + n + k + 1 , 1 );
  fill ( sz + 1 , sz + n + k + 1 , 1 );
  for ( rint i = 1 ; i <= m && ans <= :: ans ; i ++ ) if ( e[ i ]. u <= n || ( ( s >> ( e[ i ]. u - n - 1 ) ) & 1 ) )
    if ( find ( e[ i ]. u ) != find ( e[ i ]. v ) )
      ans += e[ i ]. w , merge ( e[ i ]. u , e[ i ]. v );
  return ans;
}
signed main ()
{
  freopen ( "road.in" , "r" , stdin );
  freopen ( "road.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 );   
  cin >> n >> m >> k;
  iota ( fa + 1 , fa + n + k + 1 , 1 );
  fill ( sz + 1 , sz + n + k + 1 , 1 );
  for ( rint i = 1 ; i <= m ; i ++ )
    cin >> e[ i ]. u >> e[ i ]. v >> e[ i ]. w;
  int mm = m; bool tag = 1;
  for ( rint i = 1 ; i <= k ; i ++ )
  {
    cin >> c[ i ]; tag &= ( ! c[ i ] ); bool fl = 0;
    for ( rint j = 1 ; j <= n ; j ++ )
    {
      int w; cin >> w;
      e[ ++ m ] = { n + i , j , w };
      fl |= ( ! w );
    }
    tag &= fl;
  }
  sort ( e + 1 , e + m + 1 , [ & ] ( edge a , edge b ) { return a. w < b. w; } );
  if ( ! tag )
  {
    for ( rint i = 1 ; i <= m ; i ++ ) if ( e[ i ]. u <= n && find ( e[ i ]. u ) != find ( e[ i ]. v ) )
      ans += e[ i ]. w , merge ( e[ i ]. u , e[ i ]. v ) , vis[ i ] = 1;
  }
  else
  {
    for ( rint i = 1 ; i <= m ; i ++ ) if ( find ( e[ i ]. u ) != find ( e[ i ]. v ) )
      ans += e[ i ]. w , merge ( e[ i ]. u , e[ i ]. v ) , vis[ i ] = 1;
    cout << ans << '\n'; return 0;
  }
  mm = 0;
  for ( rint i = 1 ; i <= m ; i ++ ) if ( vis[ i ] || e[ i ]. u > n )
    e[ ++ mm ] = e[ i ];
  m = mm;
  for ( rint i = 1 ; i < ( 1 << k ) ; i ++ )
  {
    ll res = 0; for ( rint j = 0 ; j < k ; j ++ ) if ( ( i >> j ) & 1 ) res += c[ j + 1 ];
    ans = min ( ans , solve ( i , res ) );
  }
  cout << ans << '\n';
  return 0;
}