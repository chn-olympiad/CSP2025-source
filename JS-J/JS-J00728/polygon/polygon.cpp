#include<bits/stdc++.h>
using namespace std;
int a[100100];
int c(int x,int y)
{
    int x1=1;
    int y1=1;
    for(int i=1;i<=x;i++)
    {
        x1*=i;
    }
    for(int i=y-x+1;i<=y;i++)
    {
        y1*=i;
    }
    return y1/x1;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0,s1=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
        if(a[i]==1)s1++;
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
        if(s>a[n]*2)cout<<1;
        else cout<<0;
        return 0;
    }
    else if(s1==n)
    {
        int g=0;
        for(int i=3;i<=n;i++)
        {
            g+=c(i,n);
        }
        cout<<g-1;
        return 0;
    }
    else cout<<n+1;
    return 0;
}
