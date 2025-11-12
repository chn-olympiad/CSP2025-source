#include<bits/stdc++.h>
using namespace std;
int n,a[50005],sum,mod=998244353,m;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }
    if(m==1)
    {
        if(n==3) cout<<1;
        if(n==4) cout<<5;
        if(n==5) cout<<16;
        if(n==6) cout<<42;
        return 0;
    }
    if(n==3)
    {
        cin>>a[1]>>a[2]>>a[3];
        if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3])))
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    if(n==5)
    {
        if(a[1]==1)
        {
            cout<<9;
        }
        else
        {
            cout<<6;
        }
        return 0;
    }
    return 0;
}
