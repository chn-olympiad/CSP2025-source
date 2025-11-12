#include <bits/stdc++.h>
using namespace std ;
bool cmp ( int x, int y ) {
    return x > y ;
}
int main () {
    freopen ("seat","r",stdin) ;
    freopen ("seat","w",stdout) ;
    int n, m, a [ 11 ] [ 11 ] ;
    vector <int> v ; cin >> n >> m ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> a [ i ] [ j ] ;
            v.push_back ( a [ i ] [ j ] ) ;
        }
    } sort ( v.begin (), v.end (), cmp ) ;
    int I = 0, s = a [ 1 ] [ 1 ] ;
    for ( int i = 1 ; i <= m ; i++ ) {
        if ( i % 2 == 1 ) {
            for ( int j = 1 ; j <= n ; j++ ) {
                a [ j ] [ i ] = v [ I ] ; I++ ;
                if ( a [ j ] [ i ] == s ) {
                    cout << i << ' ' << j ;
                    fclose (stdin) ;
                    fclose (stdout) ;
                    return 0 ;
                }
            }
        } else {
            for ( int j = n ; j >= 1 ; j-- ) {
                a [ j ] [ i ] = v [ I ] ; I++ ;
                if ( a [ j ] [ i ] == s ) {
                    cout << i << ' ' << j ;
                    fclose (stdin) ;
                    fclose (stdout) ;
                    return 0 ;
                }
            }
        }
    }
    return 0 ;
}
