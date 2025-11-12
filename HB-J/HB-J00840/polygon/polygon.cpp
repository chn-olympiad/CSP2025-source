#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n==3)
    {
        if ((a[1]+a[2]+a[3]>a[1]*2) && (a[1]+a[2]+a[3]>a[2]*2) && (a[1]+a[2]+a[3]>a[3]*2))
        {
            cout<<1;
            return 0;
        }
    }
    if (n==4)
    {
        int sum=0;
        if ((a[1]+a[2]+a[3]>a[1]*2) && (a[1]+a[2]+a[3]>a[2]*2) && (a[1]+a[2]+a[3]>a[3]*2))
        {
            sum++;
        }
        if ((a[1]+a[2]+a[4]>a[1]*2) && (a[1]+a[2]+a[4]>a[2]*2) && (a[1]+a[2]+a[4]>a[4]*2))
        {
            sum++;
        }
        if ((a[1]+a[4]+a[3]>a[1]*2) && (a[1]+a[4]+a[3]>a[3]*2) && (a[1]+a[4]+a[3]>a[4]*2))
        {
            sum++;
        }
        if ((a[4]+a[2]+a[3]>a[4]*2) && (a[4]+a[2]+a[3]>a[2]*2) && (a[4]+a[2]+a[3]>a[3]*2))
        {
            sum++;
        }
        if ((a[1]+a[2]+a[3]>a[4]) && (a[1]+a[4]+a[3]>a[2]) && (a[1]+a[2]+a[4]>a[3]) && (a[2]+a[3]+a[4]>a[1]))
        {
            sum++;
        }
        cout<<sum;
        return 0;
    }

    return 0;
}
