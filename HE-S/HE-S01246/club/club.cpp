#include<bits/stdc++.h>

using namespace std ;
int main(){
    freopen("club.in","r",stdin) ;
    freopen("club.out","w",stdout) ;
    int t ;
    char j[1000] ;
    cin >> t ;
    for ( int i = 1 ; i <= t ; i++ ) {
        cin >> n ;
        for ( int q = 1 ; q <= n ; q++ ) {
            for ( int w = 1 ; w <= 3 ; w++ ) {
                cin >> j[w] ;
            }
        }
    }
    int sum = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int q = j[1] ; q <= j[3] ; q++ ) {
            if ( j[1] > j[2] && j[1] > j[3] ) {
                sum = sum + j[1] ;
            }
            if ( j[2] > j[1] && j[2] > j[3] ) {
                sum = sum + j[2] ;
            }
            if ( j[3] > j[2] && j[3] > j[1] ) {
                sum = sum + j[1] ;
            }
        }
        cout << sum ;
        sum = 0 ;
    }


    return 0 ;
}
