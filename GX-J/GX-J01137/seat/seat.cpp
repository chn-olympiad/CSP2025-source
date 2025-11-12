#include<bits/stdc++.h>
using namespace std;
int S[11][11] ;
int A[121];
int N ,M;
int main()
{
    freopen( "seat.in" , "r" , stdin );
    freopen( "seat.out" , "w" , stdout );
    cin >> N >> M;
    int n = N * M;
    for ( int i = 0 ; i  < n ; i++ )
    {
        cin >> A[i];
    }
    if( N == 1 && M == 1 )
    {

        cout << 1 << " " << 1;
        return 0;
    }
    if ( A[0] == 1 )
    {
        cout << N << " " << M;
        return 0;
    }
    if ( A[0] == N * M )
    {
        cout << 1 << " " << 1;
        return 0;
    }
    int x = A[0];
    sort ( A  , A + n  );
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
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < M ; j++ )
        {
            S[i][j] == A[i];
        }
    }
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < M ; j++ )
        {
            if ( A[i] == A[0] )
            {
                cout << i << " " << j;
            }
        }
    }
    return 0;
}
