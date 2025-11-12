#include <iostream>
#include <algorithm>

#define ll long long
#define maxn 1000007

using namespace std;

ll n , T , ans , o , a[maxn][3] , b[maxn] , t[maxn] , p[maxn];

int main()
{
    freopen( "club.in" ,"r" , stdin );
    freopen( "club.out" ,"w" , stdout );
    ios ::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> T;
    while( T -- ) {
        cin >>n;
        for( int i = 1 ;i <= n ; ++i ) cin >> a[i][0] >>a[i][1] >> a[i][2];
        for( int i = 1 ; i <= n ; ++i ) {
            ll tmp = max( a[i][0] , max( a[i][1] , a[i][2] ) );
            if( tmp == a[i][0] ) {
                b[i] = 0;
            }else if( tmp == a[i][1] ) {
                b[i] = 1;
            }else b[i] = 2;
            t[b[i]] ++; ans += a[i][b[i]];
        }
        o = 3;
        if( t[0] >= n / 2 ) o =0;
        else if( t[1] >= n / 2 ) o = 1;
        else if( t[2] >= n / 2 ) o = 2;
        for( int i = 1 ;i <= n ; ++i ) {
            if( b[i] == o ) {
                ll mx = 0;
                for( int k = 0 ; k < 3 ; ++k )
                    if( k != o ) mx = max( mx , a[i][k] );
                p[i]= a[i][o] - mx;
            } else p[i] = 1145141145141145140;
        }
        sort( p + 1 , p + n + 1 );
        for( int i = 1 ; i <= t[o] - n / 2 ; ++i ) ans -= p[i];
        cout <<ans  <<"\n";
        for( int i = 1 ;i <= n ; ++i ){
            p[i] = b[i] = ans = 0;
        }
        t[0] = t[1] = t[2] = 0;
    }
    return 0;
}
