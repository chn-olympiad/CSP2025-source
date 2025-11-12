#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ss[5005],x[5005],sum=0,s=0,i,y,maxx=-1;
long long dp[5005]={1};
const int mod=998244353;
void dfs(int deep,int len,int cnt,int pre)
{
    if(cnt>y)
        return;
    if(deep>=1)
    {
        if(cnt<=y)
            s=(s+1)%mod;
    }
    for(int j=pre+1;j<=i-1;j++)
    {
        if(x[j]==1)
            continue;
        x[j]=1;
        dfs(deep+1,len,cnt+a[j],j);
        x[j]=0;
    }
}
long long fun(int l,int r)
{
    long long x=1;
    for(int i=l;i<=r;i++)
        x=x*i%mod;
    return x;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],maxx=max(maxx,a[i]);
    if(maxx==1)
    {
        for(int i=3;i<=n;i++)
            s=s+(fun(n-i,n)/fun(1,i)%mod)%mod;
        cout<<s;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        ss[i]=ss[i-1]+a[i];
    for(i=3;i<=n;i++)
    {
        y=ss[i-1]-a[i]-1;
        if(ss[i-1]>a[i])
            s=(s+1)%mod;
        if(y<=0)
            continue;
        dfs(0,i-3,0,0);
    }
    cout<<s;
    return 0;
}
