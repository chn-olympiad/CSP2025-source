#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    cin>>n>>k;
    int a[n+1];
    int b=0;
    int c=1;
    long long d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b=max(b,a[i]);
        c=min(c,a[i]);
        d+=a[i];
    }
    if(b==c)
    {
        if(b==1)
        {
            if(k==1)cout<<n;
            else cout<<0;
        }
        if(b==0)
        {
            if(k==0)cout<<n;
            else cout<<0;
        }
    }
    else
    {
        if(k==0)cout<<n-d;
        else cout<<d;
    }
    return 0;
}
