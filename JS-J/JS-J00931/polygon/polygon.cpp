#include<bits/stdc++.h>
using namespace std;
const int N = 5010 , mod = 998244353;
long long a[N] , ans[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n , cnt = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt += a[i];
    }
    vector<long long> dp(cnt+5);
    sort(a+1,a+n+1);
    cnt = a[1] + a[2];
    dp[0]++;dp[a[1]]++;dp[a[2]]++;dp[cnt]++;
    for (int i = 3;i <= n;i++)
    {
        for (int j = a[i] + 1;j <= cnt;j++)
        {
            ans[i] += dp[j];
            ans[i] %= mod;
        }
        for (int j = cnt;j >= 0;j--)
        {
            if (dp[j] >= 1)
            {
                dp[j+a[i]] += dp[j];
                dp[j+a[i]] %= mod;
            }
        }
        cnt += a[i];
    }
    long long ret = 0;
    for (int i = 1;i <= n;i++)
    {
        ret += ans[i];
        ret %= mod;
    }
    cout << ret;
    return 0;
}
