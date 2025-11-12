//17:25极限
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5 ;
int read()
{
    int x = 0 , sign = 1 ;
    char ch = getchar() ;
    for( ; !isdigit( ch ) ; ch = getchar() ) if( ch == '-' ) sign = -1 ;
    for( ; isdigit( ch ) ; ch = getchar() ) x = (x<<1) + (x<<3) + (ch^48) ;
    return x*sign ; 
}
int n , len[5] , ans ;
struct node{
    int x[4] ;
}a[N] ;
vector < node > q[4] ;
struct node2{
    int num , id ;
}xx[N] ; 
bool cmp( node2 a , node2 b ) { return a.num < b.num ; }
void mo( int m )
{
    int op1 , op2 , sign ;
    if( m == 1 ) op1 = 2 , op2 = 3 ;
    else if( m == 2 ) op1 = 1 , op2 = 3 ;
    else op1 = 1 , op2 = 2 ;
    for( int i = 0 ; i < len[m] ; i ++ ) xx[i].num = max( q[m][i].x[op1]-q[m][i].x[m] , q[m][i].x[op2]-q[m][i].x[m] ) , xx[i].id = i ;
    sort( xx , xx+len[m] , cmp ) ;
    for( int i = n ; i < len[m] ; i ++ )
    {
        int l = xx[i].id ;
        if( q[m][l].x[op1]-q[m][l].x[m]>q[m][l].x[op2]-q[m][l].x[m] ) sign = op1 ;
        else sign = op2 ;
        ans += q[m][l].x[sign] - q[m][l].x[m] ;
    }
    return ;
}
bool cmp1( node a , node b ) {return a.x[1] > b.x[1] ;}
bool cmp2( node a , node b ) {return a.x[2] > b.x[2] ;}
bool cmp3( node a , node b ) {return a.x[3] > b.x[3] ;}
signed main(){
    freopen( "club.in" , "r" , stdin ) ;
    freopen( "club.out" , "w" , stdout ) ;  
    int T = read();
    while( T -- )
    {
        n = read() ;
        ans = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            for( int j = 1 ; j <= 3 ; j ++ ) a[i].x[j] = read() ;
            int maxx = max( { a[i].x[1] , a[i].x[2] , a[i].x[3] } ) ;
            if( maxx == a[i].x[1] ) {q[1].push_back( a[i] ) ;ans += a[i].x[1] ;}
            else if( maxx == a[i].x[2] ) {q[2].push_back( a[i] ) ;ans += a[i].x[2] ;}
            else {q[3].push_back( a[i] ) ;ans += a[i].x[3] ;}
        }
        sort( q[1].begin() , q[1].end() , cmp1 ) ;
        sort( q[2].begin() , q[2].end() , cmp2 ) ;
        sort( q[3].begin() , q[3].end() , cmp3 ) ;
        n >>= 1 ;
        for( int i = 1 ; i <= 3 ; i ++ ) len[i] = q[i].size() ;
        if( q[1].size() > n ) mo( 1 ) ;
        else if( q[2].size() > n ) mo( 2 ) ;
        else if( q[3].size() > n ) mo( 3 ) ;
        printf( "%lld\n" , ans ) ;
        for( int i = 1 ; i <= 3 ; i ++ ) q[i].clear() ;
    }
    return 0;
}