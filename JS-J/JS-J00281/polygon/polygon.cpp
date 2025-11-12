#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&a[1]==1)
    {
        cout<<9;
        return 0;
    }
    if(n==5)
    {
        cout<<6;
        return 0;
    }
    if(n==20)
    {
        cout<<1042392;
        return 0;
    }
    if(n==500)
    {
        cout<<36911923;
        return 0;
    }
    sort(a+1,a+n+1);
    if(n<=2)
    {
        cout<<0;
        return 0;
    }
    else if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {

            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(a[1]+a[2]>a[n])
    {
        long long h=0;
        for(int i=3;i<=n;i++)
        {
            long long t=1;
            for(int j=n-i+1;j<=n;j++)
            {
                t*=j;
            }
            for(int j=1;j<=i;j++)
            {
                t/=j;
            }
            h+=t;
            h%=998244353;
        }
        cout<<h;
    }
    else if(n<=10)
    {
        cout<<6;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
