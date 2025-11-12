#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3 + 10 ;
int n , q ;
char s[ N ][ 3 ][ N ] , t[ 3 ][ N ] , ans ;
int main(){
    freopen( "replace.in" , "r" , stdin ) ;
    freopen( "replace.out" , "w" , stdout ) ;
    scanf( "%d%d" , &n , &q ) ;
    for( int i = 1 ; i <= n ; i++ ){
        scanf( "%s %s" , s[ i ][ 1 ] + 1 , s[ i ][ 2 ] + 1 ) ;
    }
    while( q-- ){
        ans = 0 ;
        scanf( "%s %s" , t[ 1 ] + 1 , t[ 2 ] + 1 ) ;
        int l1 = strlen( t[ 1 ] + 1 ) , l2 = strlen( t[ 2 ] + 1 ) ;
        for( int i = 1 ; i <= n ; i++ ){
            int l = strlen( s[ i ][ 1 ] + 1 ) ;
            for( int p = 1 ; p + l - 1 <= l1 ; p++ ){
                bool flag = 1 ;
                for( int j = 1 ; j <= l ; j++ ){
                    if( s[ i ][ 1 ][ j ] != t[ 1 ][ j + p - 1 ] ){
                        flag = 0 ;
                    }
                }
                if( !flag )
                    continue ;
                char str[ N ] ;
                for( int j = 1 ; j < p ; j++ ){
                    str[ j ] = t[ 1 ][ j ] ;
                }
                for( int j = p ; j <= p + l - 1 ; j++ ){
                    str[ j ] = s[ i ][ 2 ][ j ] ;
                }
                for( int j = p + l ; j <= l1 ; j++ ){
                    str[ j ] = t[ 1 ][ j ] ;
                }
                flag = 1 ;
                for( int j = 1 ; j <= l1 ; j++ ){
                    if( t[ 1 ][ j ] != t[ 2 ][ j ] ){
                        flag = 0 ;
                    }
                }
                if( flag ){
                    ans++ ;
                }
            }
        }
        printf( "%d\n" , ans ) ;
    }
    //printf( "%d\n" , ans ) ;
    return 0 ;
}