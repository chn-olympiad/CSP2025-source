#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[5011];
bool used[5011];
ll dfs(ll l,ll maxn,ll num,ll now)
{
    ll ans=0;
    for(int i=now+1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=true;
            ans+=dfs(l+a[i],max(maxn,a[i]),num+1,i);
            ans%=998244353;
            used[i]=false;
        }
    }
    if(num>=3&&l>maxn*2)
    {
        return (ans+1)%998244353;
    }
    else{
        return ans;
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
    }
    ll ans=0;
    for(int i=1;i<=n-2;i++)
    {
        used[i]=true;
        ans+=dfs(a[i],a[i],1,i);
        ans%=998244353;
        used[i]=false;
    }
    cout<<ans;
    return 0;
}
