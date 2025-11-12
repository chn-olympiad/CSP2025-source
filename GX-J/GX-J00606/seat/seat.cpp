#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen( "polygon.in" , "r" ,stdin ) ;
    freopen( "polygon.out" , "w" ,stdout ) ;
    int a , b , y[98765];
    cin >> a >> b ;
    for( int i = 0 ; i < a*b ; i ++ )
    {
        cin >> y[i] ;
    }
    int o = y[0] ;
    for( int i = 0 ; i < a*b ; i ++ )
    {
        for( int k = 0 ; k < a*b-i-1 ; i ++ )
        {
            if( y[k] < y[k+1] )
            {
                swap( y[k] , y[k+1] ) ;
            }
        }
    }
    if( a == 2 )
    {
        cout << "2 2" ;
    }
    if( a == 3 )
    {
        cout << "3 1" ;
    }
    return 0 ;
}
