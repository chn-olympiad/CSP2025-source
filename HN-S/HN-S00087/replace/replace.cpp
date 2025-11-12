#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 3e6 + 5;

vector < int > as[N], up[N];

long long base[2] = { 91, 131 }, mod[2] = { 19491001, 19260817 };

string s[N][2], sk[N];

int pos[N], ipos[N], len[N];

#define pii pair < int, int >
#define fi first
#define se second

map < pii, int > mp;

int Ans[N];

namespace ACAM {
  int ch[N*8][26], tot, fail[M], rt, Cnt[N*8];
  vector < int > ps[N*8];
  vector < pii > gg[N*8];
  vector < int > g[N*8];
  void init ( ) {
    for ( int i = 1; i <= tot; i ++ ) {
      fail[i] = 0; 
      gg[i].clear ( );
      ps[i].clear ( );
      g[i].clear ( );
      for ( int j = 0; j < 26; j ++ ) ch[i][j] = 0;
    }
    rt = tot = 1;
  }
  void insert ( string s, int ID, int l ) {
    int r = l + len[ID] - 1, p = rt;
    for ( int i = 0; i < s.size ( ); i ++ ) {
      if ( i >= l and i <= r ) continue;
      int c = s[i] - 'a';
      if ( !ch[p][c] ) ch[p][c] = ++tot;
      p = ch[p][c];
    }
    ps[p].emplace_back ( s.size ( ) - r - 1 );
  }

int OUTPUT = 0;

  void Get_Fail ( ) {
    queue < int > q;
    for ( int i = 0; i < 26; i ++ ) {
      if ( ch[rt][i] ) q.emplace ( ch[rt][i] ), g[rt].emplace_back ( ch[rt][i] );
      else ch[rt][i] = rt;
      fail[ch[rt][i]] = rt;  
    } 
    while ( !q.empty ( ) ) {
      int x = q.front ( ); q.pop ( );
      // cout << x << "\n"; OUTPUT++;
      // if ( OUTPUT > 30 ) exit ( 0 ); 
      for ( int i = 0; i < 26; i ++ ) {
        if ( ch[x][i] ) {
          q.emplace ( ch[x][i] );
          fail[ch[x][i]] = ch[fail[x]][i];
          g[ch[fail[x]][i]].emplace_back ( ch[x][i] );
        }
        else ch[x][i] = ch[fail[x]][i];
      }
    }
  }
  void doit ( string s, int ID, int l, int id ) {
    int r = len[ID] + l - 1, p = rt;
    for ( int i = 0; i < s.size ( ); i ++ ) {
      if ( i >= l and i <= r ) {
        if ( i == r ) gg[p].emplace_back ( 0, id );
        continue;
      }
      int c = s[i] - 'a';
      p = ch[p][c];
      if ( i > r ) gg[p].emplace_back ( i - r, id );
    }
  }

  void dfs ( int x ) {
    for ( auto i : ps[x] ) Cnt[i] ++;
    for ( auto i : gg[x] ) Ans[i.se] += Cnt[i.fi];
    for ( auto i : g[x] ) dfs ( i );
    for ( auto i : ps[x] ) Cnt[i] --;
  }
}


int main ( ) {
  freopen ( "replace.in", "r", stdin );
  freopen ( "replace.out", "w", stdout );
  ios::sync_with_stdio ( false );
  cin.tie ( 0 ), cout.tie ( 0 );
  int n, q, tot = 0; cin >> n >> q;
  for ( int i = 1; i <= n; i ++ ) {
    cin >> s[i][0] >> s[i][1];
    int l = -1, r = -1;
    for ( int j = 0; j < s[i][0].size ( ); j ++ )
      if ( s[i][0][j] != s[i][1][j] ) { l = j; break; }
    for ( int j = s[i][0].size ( ) - 1; j >= 0; j -- )
      if ( s[i][0][j] != s[i][1][j] ) { r = j; break; }
    if ( l == -1 ) continue;
    long long x = 0, y = 0;
    for ( int j = l; j <= r; j ++ ) 
      x = ( x * base[0] + s[i][0][j] ) % mod[0], y = ( y * base[0] + s[i][1][j] ) % mod[0]; 
    if ( mp[{ x, y }] == 0 ) mp[{ x, y }] = ++ tot, len[tot] = r - l + 1;
    pos[i] = l;
    up[mp[{ x, y }]].emplace_back ( i );
    // cout << i << ": " << l << " " << r << " " << x << " " << y << "\n";
  }
  // cout << "---------------\n";
  for ( int i = 1; i <= q; i ++ ) {
    string s1, s2; cin >> s1 >> s2;
    int l = -1, r = -1;
    for ( int j = 0; j < s1.size ( ); j ++ )
      if ( s1[j] != s2[j] ) { l = j; break; }
    for ( int j = s1.size ( ) - 1; j >= 0; j -- )
      if ( s1[j] != s2[j] ) { r = j; break; }
    // if ( l == -1 ) continue;
    long long x = 0, y = 0;
    for ( int j = l; j <= r; j ++ )
      x = ( x * base[0] + s1[j] ) % mod[0], y = ( y * base[0] + s2[j] ) % mod[0];
    int ID = mp[{ x, y }];
    if ( ID == 0 ) continue; sk[i] = s1; ipos[i] = l;
    // cout << i << " " << l << " " << r << " " << x << " " << y << "\n";
    as[ID].emplace_back ( i );
  }

  for ( int i = 1; i <= tot; i ++ ) {
    int fk = 0;
    if ( as[i].size ( ) == 0 or up[i].size ( ) == 0 ) continue; 
    ACAM::init ( );
    for ( auto j : up[i] ) {
      if ( s[j][0].size ( ) == len[i] ) ++ fk;
      else ACAM::insert ( s[j][0], i, pos[j] );
    }
    ACAM::Get_Fail ( );
    for ( int j : as[i] ) {
      Ans[j] += fk;
      if ( sk[j].size ( ) != len[i] ) ACAM::doit ( sk[j], i, ipos[j], j ); 
    }
    ACAM::dfs ( ACAM::rt );
    
  }
  for ( int i = 1; i <= q; i ++ ) cout << Ans[i] << "\n";

}