# include<bits/stdc++.h>
using namespace std ;
# define ll long long
ll n , k ;
const int N = 500005 ;
ll a[N] ;
ll solveB(){

ll ans = 0 ;
    if ( k == 1 ) {
        for ( ll i = 1 ; i <= n ; ++ i ){
            if (a[i] == 1) ans ++ ;
        }
        return ans ;
    }
    else {
        ll q = 0 ;
        for ( ll i = 1 ; i <= n ; ++ i ){
            if ( a[i] == 0 ) {
                q = 0 ;
                ans ++ ;
            }
            else {
                q = ( q ^ a[i] ) ;
                if ( q == 0 ){
                    ans ++ ;
                    q = 0 ;
                }
            }
        }
        return ans ;
    }


}

int main(){
    freopen("xor.in" , "r" , stdin ) ;
    freopen("xor.out" , "w" , stdout ) ;
    cin >> n >> k ;
    bool ddd = true ;
    for ( ll i = 1 ; i <= n ; ++ i ){
        cin >> a[i] ;
        if ( a[i] != 0 || a[i] != 1 ) ddd = false ;
    }
    if ( ddd == true ){
        cout << solveB ;
        return 0 ;
    }

    ll ans = 0 ;
    ll i = 1 ;
    while( i <= n ){
        ll s = a[i] ;
        if ( s == k ){
            ans ++ ;
            i ++ ;
        }
       else {
            int fl = 0 ;
            for( ll j = i + 1 ; j <= n ; ++ j ){
                s = (s^a[j]) ;
                if( s == k || a[j] == k ){
                    ans ++ ;
                    i = j + 1 ;
                    fl = 1 ;
                    break ;
                }
            }
            if ( fl == 0 ) i ++ ;
       }


    }

    cout << ans ;





return 0 ;}
