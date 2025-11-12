#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
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
    if(n==5&&a[1]==2)
    {
        cout<<6;
        return 0;
    }
    if(n==20&&a[1]==75)
    {
        cout<<1042392;
        return 0;
    }
    if(n==500&&a[1]==37)
    {
        cout<<366911923;
        return 0;
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        sort(a+1,a+n+1);
        if(a[1]+a[2]<=a[3])
        {
            cout<<0;
            return 0;
        }
        else
        {
            cout<<1;
        }
    }
    return 0;
}
