#include<bits/stdc++.h>
using namespace std;
long long N , sum = 0;
int A[5010];
int main()
{
    freopen( "polygon.in" , "r" , stdin );
    freopen( "polygon.out" , "w" , stdout );
    cin >> N;
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }
    for ( int i = 0 ; i <= n ; i++ )
    {
        for ( int j = 0 ; j <= n ; j++ )
        {
            if ( (a[j] + a[j + 1] )>= max( a[j] , a[j + 1]  , a[j + 2]  )
                {

                    sum++;
                }

        }
        for ( int k = 0 ; k <= n ; k++ )
        {
            if ( (a[k] + a[k + 1] + a[ k + 2]) >= max( a[k] , a[k + 1]  , a[k + 2] , a[k + 3]  )
                {

                    sum++;
                }

        }
        for ( int r = 0 ; r <= n ; r++ )
        {
            if ( (a[r] + a[r + 1] + a[ r + 2] + a[r + 3]) >= max( a[r] , a[r + 1]  , a[r + 2] , a[r + 3] , a[ r + 4  ] )
                {

                    sum++;
                }

        }
        for ( int v = 0 ; v <= n ; v++ )
        {
            if ( (a[v] + a[v + 1] + a[ v + 2] + a[v + 3] + a[  v + 4]) >= max( a[v] , a[v + 1]  , a[v + 2] , a[v + 3] , a[ v + 4  ] , a[v + 5] )
                {

                    sum++;
                }

    }
    cout << sum;
}
