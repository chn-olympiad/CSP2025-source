#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int f[N],q[N],nr[N],mp[N],dp[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
    {
        cin >> f[i];
        q[i] = (q[i-1]^f[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        int t = (q[i]^k);
        if(!t)
            nr[i] = mp[0]+1;
        else if(mp[t])
            nr[i] = mp[t]+1;
        mp[q[i]] = i;
    }
    for(int i = 1;i<=n;i++)
    {
        dp[i] = dp[i-1];
        if(nr[i])
            dp[i] = max(dp[i],dp[nr[i]-1]+1);
    }
    cout << dp[n] <<"\n";
    return 0;
}