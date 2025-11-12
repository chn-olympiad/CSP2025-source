#include <bits/stdc++.h>
using namespace std;
int n , m , b[105] ;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m ;
    for ( int i = 1 ; i <= n * m ; i ++ ){
        cin >> b[i] ;
    }
    int k = b[1] ;
    sort(b+1,b+n*m+1) ;
    int l = n * m ;
    for ( int i = 1 ; i <= m ; i ++ ){
        if ( i % 2 ){
            for ( int j = 1 ; j <= n ; j ++ ){
                if ( b[l] == k ){
                    cout << i << " " << j ;
                    return 0;
                }
                l -- ;
            }
        }
        else {
            for ( int j = n ; j >= 1 ; j -- ){
                if ( b[l] == k ){
                    cout << i << " " << j ;
                    return 0;
                }
                l -- ;
            }
        }
    }
    return 0;
}
