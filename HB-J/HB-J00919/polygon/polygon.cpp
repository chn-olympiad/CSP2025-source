#include<bits/stdc++.h>
using namespace std;

short n;

short a[5];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    short maxl=0,sum=0;
    for(short i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>maxl)
            maxl=a[i];
        sum+=a[i];
    }
    if(n==3)
    {
        if(sum>2*maxl)
            cout<<1;
        else
            cout<<0;
    }
    else
    {
        if(n>sum)
            cout<<n;
        else
            cout<<0;
    }
    return 0;
}
