#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],n,use[5005],tot,ans,maxx=0;
int C(int m)
{
    int sum=0,t=1;
    for(int i=n-m+1;i>=1;i--)
    {
        sum=(sum+i*t%998244353)%998244353;
        t++;
    }
    return sum;
}
void dfs(int s)
{
    if(s>=n)
    {
        if(tot>maxx*2)
        {
            ans=(ans+1)%998244353;
        }
        return;
    }
    for(int i=s+1;i<=n;i++)
    {
        if(use[i])
        {
            use[i]=0;
            tot+=a[i];
            maxx=a[i];
            dfs(i);
            use[i]=1;
            maxx=a[s];
            tot-=a[i];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f==1)
    {
        for(int i=3;i<=n;i++) ans=(ans+C(i))%998244353;
        cout<<ans<<'\n';
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) use[i]=1;
    dfs(0);
    cout<<ans<<'\n';
    return 0;
}