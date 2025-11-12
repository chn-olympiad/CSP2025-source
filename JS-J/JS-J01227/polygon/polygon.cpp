#include<bits/stdc++.h>
using namespace std;
int n,a[5005],num,zd;
void dfs(int s,int sl,int zd,int xb,int last)
{
    int f=last;
    if(s>zd*2&&sl>=3&&last==0)
    {
        num=(num+1)%998244353;
        f=1;
    }
    if(xb==n+1)
    {
        return;
    }
    else
    {
        dfs(s+a[xb],sl+1,max(zd,a[xb]),xb+1,0);
        dfs(s,sl,zd,xb+1,f);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        zd=max(a[i],zd);
    }
    if(n==3)
    {
        int sum=a[1]+a[2]+a[3];
        if(sum>zd*2)
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
    if(zd==1)
    {
        long long ans=1,t=4;
        for(int i=4;i<=n;i++)
        {
            ans=(ans+t)%998244353;
            t=(t*2+i-1)%998244353;
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0,0,1,0);
    cout<<num;
    return 0;
}
