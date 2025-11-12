#include <bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
const int N = 1e3 + 9;
const int mod = 998244353 ;
char s[N] ;
int c[N] ;
int n , m ;
int ans = 1 ;
int sum ;
signed main ( ){
    freopen ( "employ.in" , "r" , stdin ) ;
    freopen ( "employ.out" , "w" , stdout ) ;
    IOS ;
    cin >> n >> m ;
    cin >> s + 1 ;
    ans = 1 ;
    for ( int i = 1 ;i <= n ; ++i ){
        cin >> c[i] ;
        sum += ( c[i] > 0 ) ;
    }
    for ( int i = 1 ; i <= sum ; ++i ){
        ans = ( ans * i ) % mod ;
        ans %= mod ;
    }
    cout << ans << "\n" ;
    return 0 ;
}