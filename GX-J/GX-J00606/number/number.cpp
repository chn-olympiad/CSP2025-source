#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen( "number.in" , "r" , stdin ) ;
    freopen( "number.out" , "w" , stdout ) ;
    string y ;
    cin >> y ;
    for( int i = 0 ; i < y.size() ; i ++ )
    {
        for( int k = 0 ; k < y.size()-i-1 ; k ++ )
        {
            if( y[k] < y[k+1] )
            {
                swap( y[k] , y[k+1] ) ;
            }
        }
    }
     for( int i = 0 ; i < y.size() ; i ++ )
    {

        if( y[i] >= '0' && y[i] <= '9' )
        {
            cout << y[i] ;
        }
    }
    return 0 ;
}
