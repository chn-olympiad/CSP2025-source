//尽力
#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int x = 0 , sign = 1 ;
    char ch = getchar() ;
    for( ; !isdigit( ch ) ; ch = getchar() ) if( ch == '-' ) sign = -1 ;
    for( ; isdigit( ch ) ; ch = getchar() ) x = (x<<1) + (x<<3) + (ch^48) ;
    return x*sign ; 
}
int n , m , k , block[1005][15] , ans , use[15] ;
bool vis[1005] ;
struct node{
    int v , val ;
};
vector < node > a[1005] ;
void dfs( int x , int con )
{
    if( con == n-1 ) return ;
    vis[x] = true ;
    int minx , minnum = 2147483647 , used = 0 ;
    for( int i = 1 ; i <= k ; i ++ )
    {
        for( int j = 1 ; j <= n ; j ++ )
        {
            if( vis[j] ) continue ;
            if( block[x][i] + block[j][i] + ( use[i] ? 0 : block[0][i] ) < minnum )
            {
                minnum = block[x][i] + block[j][i] + ( use[i] ? 0 : block[0][i] ) ;
                minx = j ;
                used = i ;
            }
        }
    }
    for( int i = 0 ; i < a[x].size() ; i ++ )
    {
        int v = a[x][i].v , w = a[x][i].val ;
        if( vis[v] ) continue ;
        if( w < minnum )
        {
            minnum = w ;
            minx = v ;
            used = 0 ;
        }
    }
    if( !used ) use[used] = 1 ;
    ans += minnum ;
    dfs( minx , con+1 ) ;
}
struct node2{
    int u , v , w ;
}ax[1000005] ;
bool cccmp( node2 a , node2 b ) {return a.w < b.w ;}
int f[10005] ;
int find( int x )
{
    if( f[x] == x ) return x ;
    else return f[x] = find( f[x] ) ;
}
void doing()
{
    for( int i = 1 ; i <= m ; i ++ )
    {
        ax[i].u = read() , ax[i].v = read() , ax[i].w = read() ;
    }
    for( int i = 1 ; i <= n ; i ++ ) f[i] = i ;
    int ans = 0 ;
    sort( ax+1 , ax+m+1 , cccmp ) ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        int u = ax[i].u , v = ax[i].v , w = ax[i].w ;
        u = find( u ) , v = find( v ) ;
        if( u == v ) continue ;
        f[v] = u ;
        ans += w ;
    }
    printf( "%lld" , ans ) ;
    exit( 0 ) ;
}
signed main(){
    freopen( "road.in" , "r" , stdin ) ;
    freopen( "road.out" , "w" , stdout ) ;  
    n = read() , m = read() , k = read() ;
    int u , v , w ;
    if( k == 0 ) doing() ;
    for( int i = 1 ; i <= m ; i ++ )
    {
        u = read() , v = read() , w = read() ;
        a[u].push_back( { v , w } ) ;
        a[v].push_back( { u , w } ) ;
    }
    int signx = 0 , ff ;
    for( int i = 1 ; i <= k ; i ++ )
    {
        ff = 0 ;
        for( int j = 0 ; j <= n ; j ++ )
        {
            block[j][i] = read() ;
            if( block[j][i] != 0 ) ff = 1 ;
        }
        if( ff == 0 ) signx = 1 ;
    }
    if( signx ) {cout << "0" ;exit(0) ;}
    else dfs( 1 , 0 ) ;
    for( int i = 1 ; i <= k ; i ++ ) if( use[i] ) ans += block[0][i] ;
    printf( "%lld" , ans );
    return 0;
}