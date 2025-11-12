#include<bits/stdc++.h>
using namespace std;
int n;
long long k, a[500005], qzyh[500005];
long long dp[500005], ma = 0;
void dfs(int d)
{
    if(dp[d] >= 0)
        return ;
    for(int i = d;i <= n;i ++)
    {
        int h = qzyh[i] ^ qzyh[d - 1];
        if(i == d)
        h = a[i];
        dp[d] = 0;
        if(h == k)
        {
            for(int j = i + 1;j <= n;j ++)
            {
                dfs(j);
                dp[d] = max(1 + dp[j], dp[d]);
            }
            ma = max(ma, dp[d]);
            break;
        }
    }
    if(d < n)
    dfs(d + 1);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        dp[i] = -1;
    }
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(i > 1)
        qzyh[i] = qzyh[i - 1] ^ a[i];
        else
        qzyh[i] = a[i];
    }
    dfs(1);
    cout << ma;
    return 0;
}
