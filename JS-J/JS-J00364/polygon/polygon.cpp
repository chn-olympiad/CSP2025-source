#include<bits/stdc++.h>
using namespace std;
long long a[5005],n,maxx,sum,ans,mod=998244353;
void dfs(long long now,long long ma,long long su)
{
    //no
    if(now<n)
    {
        dfs(now+1,ma,su);
    }
    //yes
    ma=max(ma,a[now]);
    su+=a[now];
    if(su>2*ma)
    {
        ans++;
    }
    if(now<n)
    {
        dfs(now+1,ma,su);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        maxx=max(a[i],maxx);
    }
    if(n<3)
    {
        cout<<0;
    }
    else if(n==3)
    {
        if(sum>2*maxx)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(maxx==1)
    {
        for(int i=3;i<=n;i++)
        {
            long long p=1;
            for(int j=0;j<i;j++)
            {
                p*=(n-j);
                p%=mod;
            }
            for(int j=2;j<=i;j++)
            {
                p/=j;
            }
            ans+=p;
            ans%=mod;
        }
        cout<<ans;
    }
    else
    {
        dfs(1,0,0);
        cout<<ans;
    }
    return 0;
}
