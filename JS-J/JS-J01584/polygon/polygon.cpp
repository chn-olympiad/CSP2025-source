#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mod=998244353;
ll n;
ll a[N];
ll pos[N];
ll ans;
inline void dfs(ll num,ll sum,ll last)
{
    if(num==1)
    {
        if(sum>a[n])
        {
            ans=(ans+n-last)%mod;
        }
        else
        {
            ll it=pos[*lower_bound(a+last,a+n,sum)]-1;
            ans=(ans+it-last)%mod;
        }
        return ;
    }
    for(register int i=last+1; i<=n-1; ++i)
    {
        dfs(num-1,sum+a[i],i);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(register int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(register int i=1; i<=n; ++i)
    {
        if(!pos[a[i]])
        {
            pos[a[i]]=i;
        }
    }
    for(register int i=3; i<=n; ++i)
    {
        dfs(i,0,0);
    }
    cout<<ans;
    return 0;
}
