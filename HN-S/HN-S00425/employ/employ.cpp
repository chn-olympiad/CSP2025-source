#include <bits/stdc++.h>
using namespace std;
#define rint register int
const int N = 500 + 5 , mod = 998244353;
char s[ N ];
int f[ 1 << 18 ][ 19 ] , c[ N ] , sz[ 1 << 18 ];  
void add ( int & x , int y ) { ( ( x += y ) >= mod ) && ( x -= mod ); } 
signed main ()
{
  freopen ( "employ.in" , "r" , stdin );
  freopen ( "employ.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ); 
  int n , m;
  cin >> n >> m;
  for ( rint i = 1 ; i <= n ; i ++ ) cin >> s[ i ];
  for ( rint i = 1 ; i <= n ; i ++ ) cin >> c[ i ]; 
  f[ 0 ][ 0 ] = 1;
  for ( rint i = 1 ; i < ( 1 << n ) ; i ++ )
  {
    sz[ i ] = sz[ i >> 1 ] + ( i & 1 );
    int sz = :: sz[ i ]; 
    for ( rint j = 0 ; j < sz ; j ++ )
    {
      for ( rint k = 1 ; k <= n ; k ++ ) if ( ( ( i >> ( k - 1 ) ) & 1 ) )
      {
        int l = j + ( ( s[ sz ] == '0' ) || ( j >= c[ k ] ) );
        add ( f[ i ][ l ] , f[ i ^ ( 1 << ( k - 1 ) ) ][ j ] );
      }
    }
  }
  int ans = 0;
  for ( rint i = 0 ; i <= n - m ; i ++ )
    add ( ans , f[ ( 1 << n ) - 1 ][ i ] );
  cout << ans << '\n';
  return 0;
}