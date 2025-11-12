#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,mod=998244353;
int n,a[maxn],ans,dp[];
void dfs(int k,int sum,int maxx,int cnt)
{
    if(k==n+1)
    {
        if(sum>2*maxx&&cnt>=3) ans=(ans+1)%mod;
        return;
    }
    dfs(k+1,sum+a[k],max(maxx,a[k]),cnt+1);
    dfs(k+1,sum,maxx,cnt);
}
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=1) return false;
    }
    return true;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20)
    {
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    else if(check())
    {
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*2%mod;
        ans=ans-1-n-(n*(n-1)/2);
        ans=(ans%mod+mod)%mod;
        cout<<ans<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
