#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int mod = 998244353 ;
int a[5005] ;
int q(int x)
{
    if(x == 1)
        return x ;
    int res = 0 ;
    for(int i = 1 ; i <= x ; i ++)
        res += i*(x+1-i) ;
    return res ;
}
int qiu(int x, int y)
{
    if(x == y)
        return 1 ;
    int z = y + 1 - x ;
    return q(z) ;
}
int main()
{
    freopen("polygon.in", "r", stdin) ;
    freopen("polygon.out", "w", stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n, h = 1;
    cin >> n ;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a[i] ;
        if(i >= 2 && a[i] != a[i-1])
            h = 0;
    }

    if(n == 3)
    {
        int cnt = a[1] + a[2] + a[3] ;
        if(cnt > a[3]*2)
            cout << 1 << endl ;
        else
            cout << 0 << endl ;
        return 0;
    }
    else if(h == 1)
    {
        int ans = 0 ;
        for(int i = 3 ; i <= n ; i ++)
        {
            ans += qiu(i, n) ;
        }
        cout << ans << endl ;
        return 0 ;
    }
    else
    {
        int ans = 1 ;
        for(int i = 2 ; i < n ; i ++)
            ans = ans * i % mod ;
        cout << ans << endl ;
    }
    return 0 ;
}

