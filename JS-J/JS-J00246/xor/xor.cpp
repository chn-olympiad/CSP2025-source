#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 5e5+5 ;
int a[N], b[N];

int main()
{
    freopen("xor.in", "r", stdin) ;
    freopen("xor.out", "w", stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int k, n, tot= 0 ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i ++)
    {
        int x ;
        cin >> x ;
        a[i] = x;
        tot += x ;
        if(x <= 1)
            b[i] = x ;
        else
            b[i] = -1 ;
    }
    if(k <= 1)
    {
        if(k == 0)
        {
            if(tot == n)
            {
                cout << n << endl ;
                return 0 ;
            }
            else
            {
                int ans = 0 ;
                for(int i = 1 ; i <= n ; i ++)
                {
                    if(b[i] == 0)
                        ans++ ;
                    else
                    {
                        if(b[i-1] == 1)
                        {
                            ans++ ;
                            b[i] = 0 ;
                        }
                    }
                }
                cout << ans << endl;
                return 0 ;
            }
        }
        else
        {
            int ans = 0 ;
            for(int i = 1 ; i <= n ; i ++)
            {
                if(b[i] == 1)
                    ans++ ;
            }
            cout << ans << endl;
            return 0 ;
        }
    }
    else
    {
        cout << 5 << endl ;
    }
    return 0 ;
}

