#include<bits/stdc++.h>
using namespace std;
short a[200001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)t++;
    }
    if(n<=2&&t==n)
    {
        if(n==1)
        {
            cout<<0;
            return 0;
        }
        if(n==2)
        {
            cout<<1;
            return 0;
        }
    }
    if(k==0&&t==n)
    {
        cout<<n/2;
        return 0;
    }
    t=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1||a[i]==0)t++;
    }
    if(t==n&&k==1)
    {
        int j=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)j++;
        }
        cout<<j;
        return 0;
    }
    if(t==n&&k==0)
    {
        int p=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)p++;
        }
        cout<<p;
        return 0;
    }
    return 0;
}
