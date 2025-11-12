#include<bits/stdc++.h>
using namespace std ;
const int N = 510 , M = 510 , P = 998244353 ;
int n , m , s[ N ] , c[ N ] ;
char str[ N ] ;
namespace solve1{
    int dp[ N ][ N ] ;
    bool b[ N ] ;
    int dfs( int i , int cnt ){
        if( n - cnt < m ){
            return 0 ;
        }
        /*if( dp[ i ][ cnt ] ){
            return dp[ i ][ cnt ] ;
        }*/
        if( i == n + 1 ){
            if( n - cnt >= m ){
                return 1 ;
            }
        }
        int res = 0 ;
        for( int j = 1 ; j <= n ; j++ ){
            if( b[ j ] ){
                continue ;
            }
            b[ j ] = 1 ;
            if( cnt >= c[ j ] || s[ i ] == 0 ){
                res = ( 1LL * res + dfs( i + 1 , cnt + 1 ) ) % P ;
            }
            else{
                res = ( 1LL * res + dfs( i + 1 , cnt ) ) % P ;
            }
            b[ j ] = 0 ;
        }
        dp[ i ][ cnt ] = res ;
        return res ;
    }
    inline void work(){
        printf( "%d\n" , dfs( 1 , 0 ) ) ;
    }
}
int main(){
    freopen( "employ.in" , "r" , stdin ) ;
    freopen( "employ.out" , "w" , stdout ) ;
    bool all1 = 1 ;
    scanf( "%d%d%s" , &n , &m , str + 1 ) ;
    for( int i = 1 ; i <= n ; i++ ){
        s[ i ] = str[ i ] - '0' ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        scanf( "%d" , &c[ i ] ) ;
    }
    solve1::work() ;
    return 0 ;
}