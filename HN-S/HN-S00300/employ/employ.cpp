#include<bits/stdc++.h>
using namespace std;
int n , m , a[505] , ansx[25] , ans1 ;
string s ;
bool f[25] ;
void dfs( int x )
{
    if( x > n )
    {
        //check
        int total = 0 , gets = 0 ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            // cout << ansx[i] << " " ;
            if( s[i] == '1' && ansx[i] > total ) gets ++ ;
            else total ++ ;
        }
        // cout << gets << "\n" ;
        if( gets >= m ) ans1 ++ ;
    }
    else 
    {
        for( int i = 1 ; i <= n ; i ++ )
        {
            if( f[i] ) continue ;
            f[i] = true ;
            ansx[x] = a[i] ;
            dfs( x+1 ) ;
            f[i] = false ;
        }
    }
    return ;
}
void solve1()
{
    cin >> s ;
    s = " " + s ;
    for( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
    dfs( 1 ) ;
    cout << ans1 ;
}
int dp[505][505] ;
void solve2()
{
    cin >> s ;
    s = " " + s ;
    for( int i = 1 ; i <= n ; i ++ ) cin >> a[i] ;
}
int main(){
    freopen( "employ.in" , "r" , stdin ) ;
    freopen( "employ.out" , "w" , stdout ) ; 
    ios::sync_with_stdio(0); 
    cin >> n >> m ;
    if( n <= 18 ) solve1() ;
    else solve2() ;
    return 0;
}