#include<bits/stdc++.h>
using namespace std;
map < string , int > ma ;
map < string , string > rep ;
int n , m , ans = 0 ;
string xx[200005] ;
bool f[200005] , fpl[200005] ;
void dfs( string now , string t )
{
    // cout << now << "\n" ;
    if( now == t )
    {
        ans ++ ;
        return ;
    }
    if( ma.count( now ) ) return ;
    ma[ now ] = 1 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        int pl = now.find( xx[i] ) ;
        if( pl == -1 || f[i] || fpl[pl] ) continue ;
        f[i] = true ;
        fpl[pl] = true ;
        string nowx = now ;
        nowx.erase( pl , xx[i].size() ) ;
        nowx.insert( pl , rep[xx[i]] ) ;
        dfs( nowx , t ) ;
        f[i] = false ;
        fpl[pl] = false ;
    }
    return ;
}
int main(){
    freopen( "replace.in" , "r" , stdin ) ;
    freopen( "replace.out" , "w" , stdout ) ;  
    ios::sync_with_stdio(0);
    cin >> n >> m ;
    string a , b ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        cin >> a >> b ;
        rep[a] = b ;
        xx[i] = a ;
    }
    for( int i = 1 ; i <= m ; i ++ )
    {
        cin >> a >> b ;
        dfs( a , b ) ;
        cout << ans << "\n" ;
        ans = 0 ;
    }
    return 0;
}