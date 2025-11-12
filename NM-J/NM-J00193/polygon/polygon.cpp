#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[5010];
int cnt[5010];
int n;
int ret = 0;

void dfs(int u)
{
    if(u > n)
    {
        int sum = 0;
        int maxx = -1e9;
        for(int i = 1;i < u;i++)
        {
            if(cnt[i] == 1)
            {
                sum += a[i];
                maxx = max(maxx, a[i]);
            }
        }
        if(sum > maxx * 2)
        {
            ret++;
            ret %= 998244353;
        }
        return;
    }
    cnt[u] = 0;
    dfs(u + 1);
    cnt[u] = 1;
    dfs(u + 1);
}

signed main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    memset(cnt, 0, sizeof(cnt));
    dfs(1);

    cout << ret % 998244353 - 1 << endl;
    return 0;
}
