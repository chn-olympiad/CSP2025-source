#include <bits/stdc++.h>
using namespace std ;
bool cmp ( int x, int y ) {
    return x > y ;
} long long C ( int n, int m ) {
    long long a = 1 ;
    for ( int i = m ; i >= m - n + 1 ; i-- )
        a *= i ;
    for ( int i = n ; i >= 2 ; i-- )
       a /= i ;
    return a % 998244353 ;
}
int main () {
    freopen ("polygon", "r", stdin) ;
    freopen ("polygon", "w", stdout) ;
    int n, a [ 5005 ] ; cin >> n ;
    long long c = 0, s = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a [ i ] ;
    sort ( a + 1, a + n + 1, cmp ) ;
    for ( int i = 1 ; i <= n - 2 ; i++ ) {
        int x = a [ i ] * 2 - a [ i + 1 ] ;
        for ( int j = 2 ; j < n - i ; j++ ) {
            for ( int k = i + j ; k < n ; k++ ) {
                if ( x - a [ j ] >= 0 ) {
                    x -= a [ j ] ; c++ ;
                }
            }
        } c %= 998244353 ;
    } for ( int i = 3 ; i <= n ; i++ )
        s += C ( i, n ) ;
    if ( s < c ) c -= 998244353 ;
    cout << ( s - c ) % 998244353 ;
    fclose (stdin) ;
    fclose (stdout) ;
    return 0 ;
}
