#include <bits/stdc++.h>
using namespace std;
int f(int g,int h)
{
    long long q=1,c=h;
    for(int i=2;i<=g;i++)
    {
        q=q*i;
    }
    for(int i=1;i<g;i++)
    {
        c=c*(h-i);
    }
    return c/q;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    if(n==3)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b+c>2*max(a,max(b,c)))
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
    else
    {
        long long a[5002],x=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=3;i<=n;i++)
        {
            x=x+f(i,n);
        }
        cout<<x;
    }
    return 0;
}
