#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005];
int jc(int x)
{
    if (x==1||x==0) return 1;
    return x*jc(x-1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int maxn = -1;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    if (n<3)
    {
        cout << 0;
        return 0;
    }
    else if (n==3)
    {
        int sum = a[1]+a[2]+a[3];
        int maxn = max(max(a[1],a[2]),a[3]);
        if (sum > 2*maxn)
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]>maxn) maxn = a[i];
    }
    long long sum = 0;
    if (n>3&&maxn==1)
    {
        for (int i=3;i<=n;i++)
        {
            sum += jc(n)/(jc(i)*jc(n-i));
        }
        sum = sum%998244353;
        cout << sum;
        return 0;
    }
    return 0;
}
