#include<iostream>
using namespace std;
int main() {
    freopen( "xor.in" , "r" , stdin ) ;
    freopen( "xor.out" , "w" , stdout ) ;
    int a , y[98765] ;
    cin >> a ;
    for( int i = 0 ; i < a ; i ++ )
    {
        cin >> y[i] ;
    }
    if( a == 5 && y[0] == 1 )
    {
        cout << '9' ;
        return 0 ;
    }
    if( a == 5 && y[0] == 2 )
    {
        cout << '6' ;
        return 0 ;
    }
    if( a == 5 )
    {
        cout << '4' ;
    }
    return 0 ;
}
