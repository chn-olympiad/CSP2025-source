#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <cstdlib>

#define ll long long
#define maxn 1000007
#define base 13331
#define M 998244353

using namespace std;

ll n , q , tot , cnt , w[maxn] , a[maxn] , L[maxn] , R[maxn] , pos[maxn] , num , rt[maxn] , ans[maxn];
string s[maxn][2] , t , t2;
map< ll , ll >f , g;
int ch[maxn / 10 * 55 ][26]; vector< int >v[maxn / 10 * 55 ] , qu[maxn / 10 * 55 ] , ak[maxn];
ll sm[maxn];

void dfs( int k )
{
    for( int i = 0 ; i < v[k].size() ; ++i )
        sm[v[k][i]] ++;
    for( int i = 0 ; i < qu[k].size() ; ++i ) {
        int now = qu[k][i];
        for( int j = 0 ;j < ak[now].size() ; ++j )
            ans[now] += sm[ak[now][j]];
    }
    for( int i = 0 ; i< 26 ; ++i ) {
        if( ch[k][i] ) dfs( ch[k][i] );
    }
    for( int i = 0 ; i < v[k].size() ; ++i )
        sm[v[k][i]] --;
}

int main()
{
    freopen( "replace.in" ,"r" , stdin );
    freopen( "replace.out" ,"w" , stdout );
    ios ::sync_with_stdio( false );
    cin.tie( 0 );
    srand( time( 0 ) );
    cin >> n >> q;
    for( int i = 1 ;i <= n ; ++i ) rt[i] = ++num;
    for( int i = 1 ; i <= n ; ++i ) {
        cin >>s[i][0] >> s[i][1];
        int l = s[i][0].size() , r = -1;
        for( int j = 0 ;j < s[i][0].size() ; ++j )
            if( s[i][0][j] != s[i][1][j] ) {
                l = min( l , j ); r= max( r , j );
            }
        if( r == -1 ) continue;
        L[i] = l; R[i] = r;
       // cout <<i <<" " << l <<" " <<r <<" " <<"\n";
        for( int j = l ;j <= r ; ++j )
            w[i] = ( w[i] * base + s[i][0][j] ) % M;
        ll sum = 0;
        for( int j = l ;j <= r ; ++j )
            sum = ( sum * base + s[i][1][j] ) % M;
        w[i] = w[i] * M + sum;
        if( f[w[i]] ) {
            pos[i] = f[w[i]];
        }else f[w[i]] = pos[i] = ++tot;
        for( int j = r + 1 ; j < s[i][0].size() ; ++j ) {
            a[i] =( a[i] * base + s[i][0][j] ) % M;
        }
        if( !g[a[i]] ) {
            g[a[i]] = ++cnt;
        }
        a[i] = g[a[i]]; int now = rt[pos[i]];
      //  continue;
        for( int j = l - 1 ; j >= 0 ; --j ) {
            int c = s[i][0][j] - 'a';
            if( !ch[now][c] ) {
                ch[now][c] = ++num;
            }
            now = ch[now][c];
        }
       v[now].push_back( a[i] );
    }
    for( int i = 1 ; i <= q ; ++i ) {
        cin >>t >>t2; int l = t.size() , r = -1;
        if( t.size() != t2.size() ) continue;
        for( int j = 0 ; j < t.size() ; ++j ) {
            if( t[j] != t2[j] ) {
                l = min( l , j ); r = max( r , j );
            }
        }
        ll s1 = 0 , s2 = 0;
        for( int j = l ; j <= r ; ++j ) {
            s1 = ( s1 * base + t[j] ) % M;
            s2 = ( s2 * base + t2[j] ) % M;
        }
        s1 = s1 * M + s2;
       // cout << s1 <<"\n";
        s1 = f[s1];
      //  cout << s1 << "\n";
        if( s1 ) {
            ak[i].push_back( g[0] ); ll sum = 0;
            for( int j = r + 1 ; j < t2.size() ; ++j ) {
                sum = ( sum * base + t[j] ) % M;
                ak[i].push_back( g[sum] );
            }
            int now = rt[s1];
            for( int j = l - 1 ; j >= 0 ; --j ) {
                int c = ( t[j] - 'a' );
                if( !ch[now][c] ) break;
                now = ch[now][c];
            }
            if( now ) {
                qu[now].push_back( i );
            }
        }

    }
    for( int i = 1 ; i <= n; ++i ) {
        dfs( rt[i] );
    }
   for( int i = 1 ; i <= q ; ++i ) cout << ans[i] <<"\n";
    return 0;
}
