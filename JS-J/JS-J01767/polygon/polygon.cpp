#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int mod = 998244353;
long long n,a[maxn],ans,jc[maxn],ny[maxn];
void dfs(long long i,long long c,long long sum,long long maxa)
{
    if(i > n)
    {
        if(c >= 3 && sum > 2*maxa) ans = (ans+1)%mod;
        return;
    }
    dfs(i+1,c+1,sum+a[i],max(maxa,a[i]));
    dfs(i+1,c,sum,maxa);
    return;
}
long long ksm(long long a,long long b)
{
    long long ret = 1,x = a;
    while(b)
    {
        if(b&1) ret = ret*x%mod;
        x = x*x%mod;
        b >>= 1;
    }
    return ret%mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    bool fa = 1;
    for(long long i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] != 1) fa = 0;
    }
    if(fa)
    {
        jc[0] = 1;
        for(long long i = 1;i <= n;i++)
        {
            jc[i] = jc[i-1]*i%mod;
        }
        for(long long i = 0;i <= n;i++)
        {
            ny[i] = ksm(jc[i],mod-2);
        }
        for(long long i = 3;i <= n;i++)
        {
            ans = (ans + jc[n]*ny[n-i]%mod*ny[i]%mod)%mod;
        }
        cout << ans;
        return 0;
    }
    dfs(1,0,0,0);
    cout << ans;
    return 0;
}
