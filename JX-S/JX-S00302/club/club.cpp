#include<bits/stdc++.h>
using namespace std ;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N = 2e5 + 9 ;
int n ;
int t ;
struct node{
    int w[5] ;
    int maxn , pos , maxn2 ;
}a[N] ;
int p[5] ;
int sum[5] ;
int n2 ;
int o[N] , tot ;
int work ( ){
    tot = 0 ;
    int ans = 0 ;
    for ( int i = 1 ; i <= 3 ; ++i ){
        if ( p[i] > n2 ){
            for ( int j = 1 ; j <= n ; ++j ){
                if ( a[j].pos == i ){
                    o[++tot] = a[j].maxn - a[j].maxn2 ;
                }
            }
            int lxq = p[i] - n2 ;
            sort ( o + 1 , o + tot + 1 ) ;
            for ( int j = 1 ; j <= lxq ; ++j ){
                ans -= o[j] ;
            }
        }
        ans += sum[i] ;
    }
    return ans ;
}
int main ( ){
    freopen ( "club.in" , "r" , stdin ) ;
    freopen ( "club.out" , "w" , stdout ) ;
    IOS ;
    cin >> t ;
    while ( t-- ){
        cin >> n ;
        n2 = ( n / 2 ) ;
        for ( int i = 1 ; i <= n ; ++i ){
            a[i].maxn = 0 ;
            for ( int j = 1 ; j <= 3 ; ++j ){ 
                cin >> a[i].w[j] ;
                if ( a[i].w[j] > a[i].maxn ){
                    a[i].maxn = a[i].w[j] ;
                    a[i].pos = j ;
                }
            }
            p[a[i].pos] ++ ;
            sum[a[i].pos] += a[i].maxn ;
            a[i].maxn2 = 0 ;
            for ( int j = 1 ; j <= 3 ; ++j ){
                if ( j == a[i].pos ) continue ;
                a[i].maxn2 = max ( a[i].maxn2 , a[i].w[j] ) ;
            }
        }
        cout << work ( ) << "\n" ;
        sum[1] = sum[2] = sum[3] = 0 ;
        p[1] = p[2] = p[3] = 0 ;
    }
    return 0 ;
}