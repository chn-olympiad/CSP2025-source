#include<bits/stdc++.h>
using namespace std;
string S ;
int A[100010] , sum= 0;
int main()
{
    freopen( "number.in" , "r" , stdin );
    freopen( "number.out" , "w" , stdout );
    cin >> S;
    if ( S.size() == 1 )
    {

        cout << S;
        return 0;
    }

    for ( int i = 0 ; i < S.size() ; i++ )
    {


            if ( S[i] == '0' )
            {
                A[i] == 0;
            }
            if ( S[i] == '1')
            {

                A[i] == 1;
            }
            if ( S[i] == '2')
            {
                A[i] == 2;
            }
            if ( S[i] == '3')
            {
                A[i] == 3;
            }
            if ( S[i] == '4')
            {
                A[i] == 4;
            }
            if ( S[i] == '5')
            {
                A[i] == 5;
            }
            if ( S[i] == '6')
            {
                A[i] == 6;
            }
            if ( S[i] == '7')
            {
                A[i] == 7;
            }
            if ( S[i] == '8')
            {
                A[i] == 8;
            }
            if ( S[i] == '9')
            {
                A[i] == 9;
            }
            sum++;
    }
    int n = S.size();
    sort ( A + 1 , A + n );
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( A[i] < A[j] )
            {
                swap ( A[i] , A[j] );
            }
        }
    }
    for ( int i = 0 ; i <= sum ; i++) // print
    {
        cout << A[i];
    }
    return 0;

}
