#include <bits/stdc++.h>
using namespace std;
int n , a[5010] , b[5010] , ans ;
void dfs( int x , int y , int z ){
    b[y] = a[x] ;
    if ( y == 1 ){
        int maxn = 0 , m = 0 ;
        for ( int i = 1 ; i <= z ; i ++ ){
            m += b[i] ;
            if ( b[i] > maxn ){
                maxn = b[i] ;
            }
        }
        if ( m > maxn * 2 ){
            ans ++ ;
        }
        return ;
    }
    for ( int i = x + 1 ; i <= n ; i ++ ){
        dfs(i,y-1,z);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n ;
    for ( int i = 1 ; i <= n ; i ++ ){
        cin >> a[i] ;
    }
    for ( int i = 1 ; i <= n ; i ++ ){
        for ( int j = 3 ; j <= n ; j ++ ){
            dfs(i,j,j) ;
            for ( int k = 1 ; k <= j ; k ++ ){
                b[k] = 0 ;
            }
        }
    }
    cout << ans ;
    return 0;
}
