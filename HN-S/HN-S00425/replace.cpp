#include <bits/stdc++.h>
#include <bits/extc++.h>
// using namespace __gnu_pbds;
#define ull unsigned long long
using namespace std;
#define rint register int
const int N = 2e5 + 5 , M = 5e6 + 5;
int n , q;
string s1 , s2 , t1 , t2;
struct node { ull d1 , d2 , l , r; } a[ N ];
struct node2 { ull d1 , d2 , l; int id; } b[ M ];
ull d1 = 0 , d2 = 0 , s = 0 , t = 0; 
bool cmp ( node a , node b )
{
  if ( a. d1 != b. d1 ) return a. d1 < b. d1;
  if ( a. d2 != b. d2 ) return a. d2 < b. d2;
  if ( a. l != b. l ) return a. l < b. l;
  return a. r < b. r;
}
bool cmp2 ( node2 a , node2 b )
{
  if ( a. d1 != b. d1 ) return a. d1 < b. d1;
  if ( a. d2 != b. d2 ) return a. d2 < b. d2;
  return a. l < b. l;
}
bool cmp3 ( node a , node2 b )
{
  if ( a. d1 != b. d1 ) return a. d1 < b. d1;
  if ( a. d2 != b. d2 ) return a. d2 < b. d2;
  return a. l < b. l;
}
__gnu_pbds :: gp_hash_table < ull , int > mp[ N ];
int out[ N ];
signed main ()
{
  freopen ( "replace.in" , "r" , stdin );
  freopen ( "replace.out" , "w" , stdout );
  ios :: sync_with_stdio ( 0 ); cin. tie ( 0 ); 
  cin >> n >> q;
  for ( rint i = 1 ; i <= n ; i ++ )
  {
    cin >> s1 >> s2; int m = s1. size ();
    int l = 0 , r = m - 1;
    while ( l < m && s1[ l ] == s2[ l ] ) l ++;
    while ( ~ r && s1[ r ] == s2[ r ] ) r --;
    d1 = 0 , d2 = 0 , s = 0 , t = 0; for ( rint i = l ; i <= r ; i ++ ) d1 = d1 * 131 + s1[ i ] , d2 = d2 * 131 + s2[ i ]; 
    for ( rint i = l - 1 ; ~ i ; i -- ) s = s * 131 + s1[ i ];
    for ( rint i = r + 1 ; i < m ; i ++ ) t = t * 131 + s1[ i ];
    a[ i ] = { d1 , d2 , s , t };
  }
  sort ( a + 1 , a + n + 1 , cmp );
  int tot = 0;
  for ( rint i = 1 ; i <= q ; i ++ )
  {
    cin >> t1 >> t2; int m = t1. size (); 
    int l = 0 , r = m - 1;
    while ( l < m && t1[ l ] == t2[ l ] ) l ++;
    while ( ~ r && t1[ r ] == t2[ r ] ) r --;
    d1 = 0 , d2 = 0 , s = 0 , t = 0; for ( rint i = l ; i <= r ; i ++ ) d1 = d1 * 131 + t1[ i ] , d2 = d2 * 131 + t2[ i ]; 
    for ( rint j = l - 1 ; j >= -1 ; j -- )
    {
      ++ tot; b[ tot ] = { d1 , d2 , s , i };
      if ( ~ j ) s = s * 131 + t1[ j ];
    }
    for ( rint j = r + 1 ; j <= m ; j ++ )
    {
      mp[ i ][ t ] = 1;
      if ( j < m ) t = t * 131 + t1[ j ];
    }
  }
  sort ( b + 1 , b + tot + 1 , cmp2 );
  for ( rint i = 1 , l = 0 , r = 0 ; i <= tot ; i ++ )
  {
    while ( l <= n && cmp3 ( a[ l ] , b[ i ] ) ) l ++;
    if ( ! l || l == n + 1 ) continue;
    r = l - 1;
    while ( b[ i ]. d1 == a[ r + 1 ]. d1 && b[ i ]. d2 == a[ r + 1 ]. d2 && b[ i ]. l == a[ r + 1 ]. l ) r ++;
    for ( rint j = l ; j <= r ; j ++ )
      out[ b[ i ]. id ] += mp[ b[ i ]. id ][ a[ j ]. r ];
  }
  for ( rint i = 1 ; i <= q ; i ++ )
    cout << out[ i ] << '\n';
  return 0;
}