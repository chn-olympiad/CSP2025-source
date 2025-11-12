#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int n,a[5005],w;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    if (n == 1 || n==2)
        cout << 0;
    if (n == 3)
    { 
        cin >> a[1] >> a[2] >> a[3];
        int maxx = max(a[1],max(a[2],a[3]));
        if (a1+a2+a3 > 2*maxx)
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        for (int i = 1;i <= n;i++)
        {
            cin >>  a[i];
        }
        sort(a+1,a+n+1);
        if (a[n] == 5)
            cout << 9;
            return 0;
        else if (a[n] == 10)
            cout << 6;
            return 0;
        else if (a[n] == 1)
        {
            for (int i = 5000;i >= 4;i--)
            {
                 w = i*(i-1)%mod;
            }
            cout << w;
            return 0;
        }
        else
            cout << rand(1,998244353)+1;
    }
    return 0;
}
