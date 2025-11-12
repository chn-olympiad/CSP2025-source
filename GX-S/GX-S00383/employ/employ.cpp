#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n , m , c[502] ;
    string s ;
    cin >> n >> m ;
    cin >> s ;
    for ( long long i = 1 ; i <= n ; i ++)
    {
        cin >> c[i] ;
    }
    long long d = 0 ;
    for ( long long i = 0 ; i < s.size() ; i ++)
    {
        if ( s[i] == '1' )
        {
            d++;
        }
    }
    if ( d == s.size() )
    {
        long long ans = n ;
        for ( long long i = 1 ; i <= n ; i ++)
        {
            if ( c[i] == 0 )
            {
                ans--;
            }
        }
        long long z = 1 ;
        for ( long long i = ans ; i >= 2 ; i --)
        {
            z *= i ;
            z%=998244353 ;
        }
        cout << z%998244353 ;
    }
    else
    {
        cout << 0 ;
    }
    return 0;
}
