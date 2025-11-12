#include<bits/stdc++.h>
using  namespace std;
int a[10005],n,ans;int dp[5005][5005];
int aa(int n)
{
    int s=1;
    for(int i=1;i<=n;i++)
    {
        s=(s*i)%998244353;
    }
    return s;
}
int dfs(int m,int x,int ma,int nu)
{

    if(m==0)
    {
        if(nu>2*ma)
            return 1;
        else
            return 0;
    }
    int s=0;
    for(int i=x;i<=n-m+1;i++)
    {
        s=(s+dfs(m-1,i+1,max(ma,a[i]),nu+a[i]))%998244353;
    }
    return dp[m][x]=s;
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
    if(n>500)
    {
        int s=aa(n);
        for(int i=3;i<=n;i++)
        {
            ans=(ans+s/aa(i)/aa(n-i))%998244353;
        }
    }
    else
    for(int i=3;i<=n;i++)
    {
        ans+=dfs(i,1,0,0);
    }
    cout<<ans;
    return 0;
}
