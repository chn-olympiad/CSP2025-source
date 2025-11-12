#include<bits/stdc++.h>
using namespace std;
int a[5005],k[5005],n;
int d;
void dg(int l,int t,int v)
{
    if(t==n||l==n) return ;
    if(t>1)
    {
        if(v>5000) d=(d+n-l)%998244353;
        else d=(d+k[v]-l)%998244353;
    }
    for(int i=l+1;i<=n;i++)
        dg(i,t+1,v+a[i]);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]==1)
    {
        int t=1;
        for(int i=1;i<=n;i++)
            t=(t<<1)%998244353;
        t-=1+n+n*(n+1)/2;
        cout<<t;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=5000;j++)
            {
                if(a[i]<j)
                    k[j]++;
            }
        }
        dg(0,0,0);
        cout<<d;
    }
    return 0;
}
