#include<bits/stdc++.h>
using namespace std ;
int T ;
int n , a[ 100010 ][ 4 ] ;
vector<pair<int,int>> x , y , z ;
inline void calc( vector<pair<int,int>> &obj1 , vector<pair<int,int>> &obj2 , vector<pair<int,int>> &obj3 , int p1 , int p2 , int p3 ){
    while( obj1.size() > n / 2 ){
        int i = obj1.size() - 1 ;
        int id = obj1[ i ].second ;
        if( a[ id ][ p2 ] >= a[ id ][ p3 ] ){
            obj2.push_back( make_pair( a[ id ][ p2 ] , id ) ) ;
        }
        else{
            obj3.push_back( make_pair( a[ id ][ p3 ] , id ) ) ;
        }
        obj1.pop_back() ;
    }
}
inline void solve(){
    x.clear() , y.clear() , z.clear() ;
    scanf( "%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ){
        scanf( "%d%d%d" , &a[ i ][ 1 ] , &a[ i ][ 2 ] , &a[ i ][ 3 ] ) ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( a[ i ][ 1 ] >= a[ i ][ 2 ] && a[ i ][ 1 ] >= a[ i ][ 3 ] ){
            x.push_back( make_pair( (-a[ i ][ 1 ]) + max( a[ i ][ 2 ] , a[ i ][ 3 ] ) , i ) ) ;
        }
        else if( a[ i ][ 2 ] >= a[ i ][ 1 ] && a[ i ][ 2 ] >= a[ i ][ 3 ] ){
            y.push_back( make_pair( (-a[ i ][ 2 ]) + max( a[ i ][ 1 ] , a[ i ][ 3 ] ) , i ) ) ;
        }
        else{
            z.push_back( make_pair( (-a[ i ][ 3 ]) + max( a[ i ][ 1 ] , a[ i ][ 2 ] ) , i ) ) ;
        }
    }
    sort( x.begin() , x.end() ) ;
    sort( y.begin() , y.end() ) ;
    sort( z.begin() , z.end() ) ;
    if( x.size() > n / 2 ){
        calc( x , y , z , 1 , 2 , 3 ) ;
    }
    else if( y.size() > n / 2 ){
        calc( y , x , z , 2 , 1 , 3 ) ;
    }
    else if( z.size() > n / 2 ){
        calc( z , x , y , 3 , 1 , 2 ) ;
    }
    int ans = 0 ;
    for( auto i : x ){
        ans += a[ i.second ][ 1 ] ;
    }
    for( auto i : y ){
        ans += a[ i.second ][ 2 ] ;
    }
    for( auto i : z ){
        ans += a[ i.second ][ 3 ] ;
    }
    printf( "%d\n" , ans ) ;
}
int main(){
    freopen( "club.in" , "r" , stdin ) ;
    freopen( "club.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        solve() ;
    }
    return 0 ;
}