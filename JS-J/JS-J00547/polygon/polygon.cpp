#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005]={};
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if (n<3)
    {
        cout << 0;
        return 0;
    }
    sort(a+1,a+n+1);
    int sum=0;
    for (int i=1;i<n;i++)
    {
        sum += a[i];
    }
    if (sum<=a[n])
    {
        cout << 0;
        return 0;
    }
    int cnt=0;
    for (int i=1;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            for (int k=j+1;k<=n;k++)
            {
                if (a[i]+a[j]>a[k])
                {
                    cnt++;
                }
            }
        }
    }
    cout << (cnt*3)%998244353;
    return 0;
}
