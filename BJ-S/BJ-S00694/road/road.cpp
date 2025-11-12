#include<bits/stdc++.h>
using namespace std ;
const int N = 1e4 + 10 , M = 1e6 + 10 , K = 15 ;
int n , m , k , u[ M ] , v[ M ] , w[ M ] , c[ K ] , a[ K ][ N ] ;
namespace solve1{
    struct Info{
        int x , y , l ;
        bool operator <( const Info &A ){
            return l < A.l ;
        }
    }edges[ M + N * K ] ;
    int len = 0 , f[ N + K ] ;
    int find( int x ){
        if( f[ x ] == x ){
            return x ;
        }
        return f[ x ] = find( f[ x ] ) ;
    }
    inline void work(){
        for( int i = 1 ; i <= n + k ; i++ ){
            f[ i ] = i ;
        }
        for( int i = 1 ; i <= m ; i++ ){
            Info tmp ;
            tmp.x = u[ i ] , tmp.y = v[ i ] , tmp.l = w[ i ] ;
            edges[ ++len ] = tmp ;
        }
        for( int i = 1 ; i <= k ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                Info tmp ;
                tmp.x = n + i , tmp.y = j , tmp.l = a[ i ][ j ] ;
                edges[ ++len ] = tmp ;
            }
        }
        sort( edges + 1 , edges + len + 1 ) ;
        int cnt = 0 ;
        long long ans = 0 ;
        for( int i = 1 ; i <= len && cnt < n + k - 1 ; i++ ){
            int fx = find( edges[ i ].x ) , fy = find( edges[ i ].y ) ;
            if( fx != fy ){
                f[ fx ] = fy ;
                ans += edges[ i ].l ;
            }
        }
        printf( "%lld\n" , ans ) ;
    }
}
namespace solve2{
    struct Info{
        int x , y , l ;
        bool operator <( const Info &A ){
            return l < A.l ;
        }
    }edges[ M ] ;
    int len = 0 , f[ N ] ;
    int find( int x ){
        if( f[ x ] == x ){
            return x ;
        }
        return f[ x ] = find( f[ x ] ) ;
    }
    inline void work(){
        for( int i = 1 ; i <= n ; i++ ){
            f[ i ] = i ;
        }
        for( int i = 1 ; i <= m ; i++ ){
            Info tmp ;
            tmp.x = u[ i ] , tmp.y = v[ i ] , tmp.l = w[ i ] ;
            edges[ ++len ] = tmp ;
        }
        sort( edges + 1 , edges + len + 1 ) ;
        int cnt = 0 ;
        long long ans = 0 ;
        for( int i = 1 ; i <= len && cnt < n - 1 ; i++ ){
            int fx = find( edges[ i ].x ) , fy = find( edges[ i ].y ) ;
            if( fx != fy ){
                f[ fx ] = fy ;
                ans += edges[ i ].l ;
            }
        }
        printf( "%lld\n" , ans ) ;
    }
}
namespace solve3{
    struct Info{
        int x , y , l ;
        bool operator <( const Info &A ){
            return l < A.l ;
        }
    }edges[ M + N * K ] ;
    int len = 0 , f[ N + K ] , p[ K ] , cnt ;
    long long res = 1e18 ;
    int find( int x ){
        if( f[ x ] == x ){
            return x ;
        }
        return f[ x ] = find( f[ x ] ) ;
    }
    long long Kruskal(){
        long long pls = 0 ;
        len = 0 ;
        for( int i = 1 ; i <= n + cnt ; i++ ){
            f[ i ] = i ;
        }
        for( int i = 1 ; i <= m ; i++ ){
            Info tmp ;
            tmp.x = u[ i ] , tmp.y = v[ i ] , tmp.l = w[ i ] ;
            edges[ ++len ] = tmp ;
        }
        for( int i = 1 ; i <= k ; i++ ){
            if( !p[ i ] ){
                continue ;
            }
            for( int j = 1 ; j <= n ; j++ ){
                Info tmp ;
                tmp.x = n + i , tmp.y = j , tmp.l = a[ i ][ j ] ;
                edges[ ++len ] = tmp ;
            }
            pls += c[ i ] ;
        }
        sort( edges + 1 , edges + len + 1 ) ;
        int cnt = 0 ;
        long long ans = 0 ;
        for( int i = 1 ; i <= len && cnt < n + cnt - 1 ; i++ ){
            int fx = find( edges[ i ].x ) , fy = find( edges[ i ].y ) ;
            if( fx != fy ){
                f[ fx ] = fy ;
                ans += edges[ i ].l ;
            }
        }
        return ans + pls ;
    }
    inline void dfs( int i ){
        if( i == k + 1 ){
            res = min( res , Kruskal() ) ;
            return;
        }
        dfs( i + 1 ) ;
        p[ i ] = 1 , cnt++ ;
        dfs( i + 1 ) ;
        p[ i ] = 0 , cnt-- ;
    }
    inline void work(){
        dfs( 1 ) ;
        printf( "%lld\n" , res ) ;
    }
}
int main(){
    freopen( "road.in" , "r" , stdin ) ;
    freopen( "road.out" , "w" , stdout ) ;
    scanf( "%d%d%d" , &n , &m , &k ) ;
    for( int i = 1 ; i <= m ; i++ ){
        scanf( "%d%d%d" , &u[ i ] , &v[ i ] , &w[ i ] ) ;
    }
    bool all0 = 1 ;
    for( int i = 1 ; i <= k ; i++ ){
        scanf( "%d" , &c[ i ] ) ;
        if( c[ i ] != 0 ){
            all0 = 0 ;
        }
        bool flag = 0 ;
        for( int j = 1 ; j <= n ; j++ ){
            scanf( "%d" , &a[ i ][ j ] ) ;
            if( a[ i ][ j ] == 0 ){
                flag = 1 ;
            }
        }
        if( !flag ){
            all0 = 0 ;
        }
    }
    if( all0 ){
        solve1::work() ;
        return 0 ;
    }
    if( k == 0 ){
        solve2::work() ;
        return 0 ;
    }
    solve3::work() ;
    return 0 ;
}