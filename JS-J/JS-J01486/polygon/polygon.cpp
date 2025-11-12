#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
bool flagA=1,flagB=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n!=3)
        flagA=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
            flagB=0;
    }
    if(flagA==1)
    {
        int mx=max(a[0],max(a[1],a[2]));
        if(mx*2<(a[0]+a[1]+a[2]))
            cout<<1;
        else
            cout<<0;
        return 0;
    }
    if(flagB==1)
    {
        long long x=1,y;
        for(int i=1;i<=n;i++)
        {
            x=x*i;
        }
        for(int i=3;i<=n;i++)
        {
            y=x;
            for(int j=1;j<=n-i;j++)
            {
                y=y/j;
            }
            for(int j=1;j<=i;j++)
            {
                y=y/j;
            }
            ans=ans+y;
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
