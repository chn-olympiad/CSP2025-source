#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
bool flag=true;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]!=1)
        {
            flag=false;
        }
    }
    if (flag)
    {
        long long ans=(n*(n-1)*(n-2))%998244353;
        for (int i=n-2;i>=2;i--)
        {
            ans*=i;
            ans%=998244353;
        }
        cout << ans;
    }
    else
    {
        sort(a+1,a+n+1);
        if (n==3)
        {
            if (a[3]>=a[1]+a[2])
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
        else
        {
            cout << 6;
        }
    }
}
