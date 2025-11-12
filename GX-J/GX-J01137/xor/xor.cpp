#include<bits/stdc++.h>
using namespace std;
int A[1000002];
int sum = 0;
int main()
{
    freopen( "xor.in" , "r" , stdin );
    freopen( "xor.out" , "w" , stdout );
    int n , k;
    cin >> n >> k;
    for ( int i = 0 ; i<= n ;i++ )
    {

        cin >> a[i];
    }
    if ( k == 0 )
    {

        cout << 1;
        return 0;
    }
    for ( int i = 0 ; i<= n ;i++ )
    {
        if ( a[i] ^ a[i + 1] == 0 || a[i] ^ a[i + 1] == 1 )
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
