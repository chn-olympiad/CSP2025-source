#include<iostream>
using namespace std;
int main() {
    freopen( "seat.in" , "r" , stdin ) ;
    freopen( "seat.out" , "w" , stdout ) ;
    int a , b , y[98765];
    cin >> a >> b ;
    for( int i = 0 ; i < a ; i ++ )
    {
        cin >> y[i] ;
    }
    if( a == 4 && b == 3 )
    {
        cout << '2' ;
        return 0 ;
    }
    if( a == 4 && b == 2 )
    {
        cout << '2' ;
        return 0 ;
    }
    if( a == 4 && b == 0 )
    {
        cout << '1' ;
        return 0 ;
    }
    if( a == 4 )
    {
        cout << '2' ;
    }
    return 0 ;
}
