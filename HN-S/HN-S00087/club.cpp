#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int a[N][3], id[N], cnt[4];

priority_queue < int, vector < int >, greater < int > > q;

signed main ( ) {
  freopen ( "club.in", "r", stdin );
  freopen ( "club.out", "w", stdout );
  int t; cin >> t;
  while ( t -- ) {
    cnt[1] = cnt[2] = cnt[3] = 0;
    int n, B, ans = 0; cin >> n; B = n / 2;
    for ( int i = 1; i <= n; i ++ ) {
      int x, y, z, mx;
      cin >> x >> y >> z;
      mx = max ( x, max ( y, z ) );
      a[i][0] = x; a[i][1] = y; a[i][2] = z;
      if ( x == mx ) id[i] = 1;
      else if ( y == mx ) id[i] = 2;
      else id[i] = 3;
      cnt[id[i]] ++;
      ans += mx;
    }
    if ( cnt[1] <= B and cnt[2] <= B and cnt[3] <= B ) {
      cout << ans << "\n";
      continue;
    } 
    int Id = ( cnt[1] > B ? 1 : ( cnt[2] > B ? 2 : 3 ) ), c = max ( cnt[1], max ( cnt[2], cnt[3] ) );
    for ( int i = 1; i <= n; i ++ ) {
      sort ( a[i], a[i] + 3 );
      if ( id[i] == Id ) q.emplace ( a[i][2] - a[i][1] );
    }
    c -= B;
    while ( c -- ) {
      ans -= q.top ( ); 
      q.pop ( );
    }
    cout << ans << "\n";
    while ( !q.empty ( ) ) q.pop ( ); 
    
  }
}
/*
Ren5Jie4Di4Ling5%


*/