#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int mod=998244353;
int a[N],sum,b[N],idx;
int n,ans;
void dfs(int dep,int sum,int maxn)
{
    if(dep>n&&sum>2*maxn)
    {
        ans++;
        ans%=mod;
        return;
    }
    else if(dep>n) return;
    dfs(dep+1,sum+a[dep],max(maxn,a[dep]));
    dfs(dep+1,sum,maxn);
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    dfs(1,0,0);
    cout<<ans%mod<<'\n';
    return 0;
}
/*
5
2 2 3 8 10
*/