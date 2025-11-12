#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans,vis[5005];
void dfs(int now,int dep)
{
    if(dep>=3)
    {
        int sum=0;
        bool ok=1;
        for(int i=1;i<=n;i++)sum+=vis[i]*a[i];
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(a[i]*2>=sum)
                {
                    ok=0;
                    break;
                }
            }
        }
        if(ok){ans=(ans+1)%998244353;};
    }
    if(now==n)
    {
        vis[n]=1;
        int sum=0;bool ok=1;
        for(int i=1;i<=n;i++)sum+=vis[i]*a[i];
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(a[i]*2>=sum)
                {
                    ok=0;
                    break;
                }
            }
        }
        if(ok){ans=(ans+1)%998244353;}
        vis[n]=0;
        return;
    }
    for(int i=now;i<=n;i++)
    {
        vis[i]=1;
        dfs(i+1,dep+1);
        vis[i]=0;
    }
}
int C(int n,int m)
{
    int ad=1;
    for(int i=n+1;i<=m;i++)
    {
        ad=ad*i%998244353;
    }
    for(int i=1;i<=m-n;i++)
        ad/=i;
    return ad;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stable_sort(a+1,a+1+n);
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1<<endl;
        }
        else cout<<0<<endl;
        return 0;
    }
    if(n<=20)
        dfs(1,0);
    if(n>20)
    {
        int sum1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)sum1++;
        }
        for(int i=3;i<=n;i++)
            ans=(ans+C(i,n))%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
