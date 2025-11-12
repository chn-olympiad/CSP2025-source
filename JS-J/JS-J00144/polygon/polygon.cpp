#include <bits/stdc++.h>
using namespace std;
int a[100005],ans=0,n;
void dg(int dep,int Max,int s,int t)
{
    if(dep>n)
    {
        if(t>=3)
            if(s>Max*2)
            {
                ans++;
                ans%=998244353;
            }
    }
    else
    {
        dg(dep+1,Max,s,t);
        dg(dep+1,max(Max,a[dep]),s+a[dep],t+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            f=1;
        }
    }
    if(n<3)
    {
        cout<<0;
    }
    else if(n==3)
    {
        int d=a[1],b=a[2],c=a[3];
        if(d+b>c&&d+c>b&&b+c>d)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(f==0)
    {
        long long x=pow(2,n)-n-n*(n-1)/2-1;
        cout<<x%998244353;
    }
    else
    {
        dg(1,0,0,0);
        cout<<ans;
    }
    return 0;
}
