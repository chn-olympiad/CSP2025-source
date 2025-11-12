#include <bits/stdc++.h>
using namespace std;
#define rint register int
const int N = 2e5 + 5;
int t , n , mid; int x[ N ][ 3 ] , id[ N ];
// int cnt[ 4 ];
priority_queue < pair < int , int > > q;
int cnt[ 4 ];
int ans = 0;
void insert ( int i )
{
  int a , b , c; a = 0 , b = 1 , c = 2;
  if ( x[ i ][ a ] < x[ i ][ b ] ) swap ( a , b );
  if ( x[ i ][ a ] < x[ i ][ c ] ) swap ( a , c );
  if ( x[ i ][ b ] < x[ i ][ c ] ) swap ( b , c );
  cnt[ a ] ++; ans += x[ i ][ a ];
}
bool vis[ N ];
void dfs ( int c , int cnt , int res )
{
  if ( cnt > mid ) return;
  if ( c > n ) 
  {
    // if ( res == 417649 ) { for ( rint i = 1 ; i <= n ; i ++ ) cerr << vis[ i ] << ' '; cerr << '\n'; }
    ans = max ( ans , res );
    return;
  }
  vis[ c ] = 0;
  dfs ( c + 1 , cnt + 1 , res + x[ c ][ 0 ] );
  vis[ c ] = 1;
  dfs ( c + 1 , cnt , res + x[ c ][ 1 ] );
  vis[ c ] = 0;
}
void solve ( )
{
  cin >> n; mid = n >> 1; ans = 0; cnt[ 0 ] = cnt[ 1 ] = cnt[ 2 ] = 0;
  while ( q. size () ) q. pop ();
  for ( rint i = 1 ; i <= n ; i ++ )
  {
    id[ i ] = i;
    for ( rint j = 0 ; j < 3 ; j ++ )
      cin >> x[ i ][ j ];
    insert ( i );
  }
  if ( max ( { cnt[ 0 ] , cnt[ 1 ] , cnt[ 2 ] } ) <= mid ) { cout << ans << '\n'; return; }
  if ( cnt[ 0 ] >= cnt[ 1 ] && cnt[ 0 ] >= cnt[ 2 ] ) { for ( rint i = 1 ; i <= n ; i ++ ) x[ i ][ 1 ] = max ( x[ i ][ 1 ] , x[ i ][ 2 ] ); }
  else if ( cnt[ 1 ] >= cnt[ 0 ] && cnt[ 1 ] >= cnt[ 2 ] ) for ( rint i = 1 ; i <= n ; i ++ ) swap ( x[ i ][ 0 ] , x[ i ][ 1 ] ) , x[ i ][ 1 ] = max ( x[ i ][ 1 ] , x[ i ][ 2 ] );
  else for ( rint i = 1 ; i <= n ; i ++ ) swap ( x[ i ][ 0 ] , x[ i ][ 2 ] ) , x[ i ][ 1 ] = max ( x[ i ][ 1 ] , x[ i ][ 2 ] );
  ans = 0;
  sort ( id + 1 , id + n + 1 , [ & ] ( int i , int j ) { return x[ i ][ 0 ] > x[ j ][ 0 ]; } ); 
  for ( rint j = 1 ; j <= n ; j ++ )
  {
    int i = id[ j ];
    if ( x[ i ][ 1 ] >= x[ i ][ 0 ] ) { ans += x[ i ][ 1 ]; vis[ i ] = 1; continue; }
    if ( q. size () < mid ) q. push ( { x[ i ][ 1 ] - x[ i ][ 0 ] , i } ) , ans += x[ i ][ 0 ];
    else 
    {
      // assert ( q. top (). first + x[ i ][ 0 ] != 0 );
      if ( q. top (). first + x[ i ][ 0 ] - x[ i ][ 1 ] > 0 ) 
      {
        ans += x[ i ][ 0 ] + q. top (). first , vis[ q. top (). second ] = 1 , q. pop () , q. push ( { x[ i ][ 1 ] - x[ i ][ 0 ] , i } );
      }
      else ans += x[ i ][ 1 ];
    }
  }
  cout << ans << '\n';
}
signed main ()
{
  freopen ( "club.in" , "r" , stdin );
  freopen ( "club.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 );
  cin >> t;
  while ( t -- ) 
    solve ( );
  return 0;
}