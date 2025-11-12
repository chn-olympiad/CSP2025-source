#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define ll long long
#define maxn 1007
#define M 998244353

using namespace std;

ll n , m , S , a[maxn] , b[maxn] , f[maxn][maxn] , g[maxn][maxn] , q[maxn] , t[maxn];
ll c[maxn][maxn] , p[maxn];

int main()
{
    freopen( "employ.in" ,"r" , stdin );
    freopen( "employ.out" ,"w" , stdout );
    ios ::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> n >>m; m = n - m; c[0][0] = 1;
    for( int i = 1 ; i<= n ; ++i ) {
        c[i][0] = 1;
        for( int j = 1 ; j <= n ; ++j ) c[i][j] = ( c[i - 1][j] + c[i - 1][j - 1] ) % M;
    }
    for( int i = 1 ;i <= n ; ++i ) {
        char ch; cin >>ch; a[i] = ch - '0';
    }
    for( int i = 1 ;i <= n; ++i ) {
        cin >>b[i]; t[b[i]] ++;
    }
    p[0] = 1; q[0] = t[0];
    for( int i =1 ; i <= n ; ++i ) p[i] = p[i - 1] * (ll)i % M;
    for( int i = 1 ; i <= n ; ++i ) q[i] = t[i] + q[i - 1];
    f[0][t[0]] ++; ll sum = 0;
    for( int i = 1 ;i <= n; ++i ) {
            for( int j = sum ;j <= m ; ++j ) {
                for( int k = 0 ; k <= n ; ++k ) {
                    ll tmp = q[j] - ( j - sum );
                   if( tmp < 0 ) continue;
                    tmp = tmp - k;
                    if( tmp < 0 ) continue;
                    tmp = i - sum - 1 - ( j - sum ) - tmp;
                    if( tmp < 0 ) continue;
                    if( a[i] == 1 ) {
                        g[j][k] = ( g[j][k] + f[j][k] ) %M ;
                            for( int l = 0 ; l <= t[j + 1] ; ++l ) {
                                ll s = c[tmp][l] * c[t[j + 1]][l] % M * p[l] % M * (ll)k % M;
                                if( k + t[j + 1] - l - 1 >= 0 )
                                    g[j + 1][k + t[j + 1] - l - 1] = ( g[j + 1][k + t[j + 1] - l - 1] + f[j][k] * s ) % M;
                            }
                    }else {
                         for( int l = 0 ; l <= t[j + 1] ; ++l ) {
                                ll s = c[tmp][l] * c[t[j + 1]][l] % M * p[l] % M;
                                g[j + 1][k + t[j + 1] - l] = ( g[j + 1][k + t[j + 1] - l] + f[j][k] * s ) % M;
                            }
                    }
                }
        }
        if( a[i] == 0 ) sum ++;
         for( int j = 0 ;j <= m ; ++j )
                for( int k = 0 ;k<= n ; ++k ) {
                   f[j][k] = g[j][k]; g[j][k] = 0;
                 //if( f[j][k] ) cout <<i << " " << j <<" " <<k <<" " <<i - q[j] - sum + k << " " <<f[j][k] << "\n";
                }
    }
    ll ans = 0;
    for( int i = 0 ;i <= m ; ++i )  {
        for( int j = 0; j <= n ; ++j ) {
            ll tmp = n - q[i] - sum + j;
            if( tmp < 0 ) continue;
         //   cout << n - q[j] - tmp <<"\n";
            ans = ( ans + f[i][j] * c[n - q[i]][tmp] % M * p[tmp] ) % M;
        }
    }
    for( int i = 1 ; i <= sum ; ++i ) ans = ans * (ll)i % M;
    cout << ans << "\n";
    return 0;
}
