#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
ll n,ans;
ll a[5005];
void dfs(int ba,int ii,ll maxn,ll he)
{
    if (ba==0)
    {
        if (he>2*maxn)
        {
            ans=(ans+1)%mod;
        }
        return ;
    }
    if (ii>n && ba>0) return ;
    if (ba==n-ii+1) dfs(ba-1,ii+1,max(maxn,a[ii]),he+a[ii]);
    else if (ba>n-ii+1) return ;
    else{
        dfs(ba,ii+1,maxn,he);
        dfs(ba-1,ii+1,max(maxn,a[ii]),he+a[ii]);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int len=3;len<=n;len++)
    {
        for (int i=1;i+len-1<=n;i++)
        {
            dfs(len-1,i+1,a[i],a[i]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
