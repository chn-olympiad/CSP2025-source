#include <iostream>
#include <algorithm>

using namespace std;

constexpr int maxn = 500, mod = 998244353;
int a[maxn + 5], c[maxn + 5], dp[maxn + 5][maxn + 5];

namespace subtask1
{
    constexpr int maxn = 18;
    int dp[(1 << maxn) + 5][maxn + 5];

    void solve(int n, int m)
    {
        dp[0][0] = 1;
        for (int s = 0; s < (1 << n) - 1; s++)
        {
            int popc = __builtin_popcount(s);
            for (int i = 0; i <= popc; i++)
                for (int j = 1; j <= n; j++)
                    if (0 == (s >> (j - 1) & 1))
                    {
                        if (1 == a[popc + 1] && popc - i < c[j])
                            dp[s | (1 << (j - 1))][i + 1] = (dp[s | (1 << (j - 1))][i + 1] + dp[s][i]) % mod;
                        else
                            dp[s | (1 << (j - 1))][i] = (dp[s | (1 << (j - 1))][i] + dp[s][i]) % mod;
                    }
        }
        
        int ans = 0;
        for (int i = m; i <= n; i++)
            ans = (ans + dp[(1 << n) - 1][i]) % mod;
        cout << ans << endl;
    }
}

namespace subtask2
{
    void solve(int n, int m)
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
            if (0 == a[i])
            { flag = false; break; }
        for (int i = 1; i <= n; i++)
            if (0 == c[i])
            { flag = false; break; }
        if (flag)
        {
            int ans = 1;
            for (int i = 2; i <= n; i++)
                ans = 1ll * ans * i % mod;
            cout << ans << endl;
        }
        else
            cout << 0 << endl;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        char ch; cin >> ch;
        a[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    if (n <= 18)
        subtask1::solve(n, m);
    else if (n == m)
        subtask2::solve(n, m);

    return 0;
}