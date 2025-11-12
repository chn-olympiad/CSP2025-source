#include <bits/stdc++.h>
using namespace std;
int n , ans ;
long long int a[500010] , k , b ;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; i ++ ){
        cin >> a[i] ;
    }
    for ( int i = 1 ; i <= n ; i ++ ){
        if ( b == 0 ){
            b = a[i] ;
        }
        else {
            b ^= a[i] ;
        }
        if ( b == k ){
            ans ++ ;
            b = 0 ;
        }
    }
    cout << ans ;
    return 0;
}
