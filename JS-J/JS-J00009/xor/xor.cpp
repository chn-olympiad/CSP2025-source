#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5 ;
long long a [ N ] ;
int main () {
    freopen ("xor", "r", stdin) ;
    freopen ("xor", "w", stdout) ;
    long long n, k, x ; int j = 1 ;
    int c = 0 ; cin >> n >> k ;
    for ( int i = 1 ; i <= n ; i++ )
        cin >> a [ i ] ;
    x = a [ j ] ;
    while ( x == k && j <= n ) {
        j++ ; c++ ; x = a [ j ] ;
    }
    for ( int i = j + 1 ; i <= n ; i++ ) {
        x ^= a [ i ] ;
        if ( a [ i ] == k || x == k ) {
            if ( i < n ) x = a [ i++ ] ; c++ ;
        }
    } cout << c ;
    fclose (stdin) ;
    fclose (stdout) ;
    return 0 ;
}
