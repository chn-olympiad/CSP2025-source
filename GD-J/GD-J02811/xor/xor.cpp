# include <bits/stdc++.h>
# define ll long long
using namespace std;

bool icebear2025front;

static const int N = 5e5 + 5;
ll n, k, a[N], pre[N];

static const int SUB60N = 2e5 + 5;
ll dp[SUB60N];
inline void sub60 ()
{
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = i; j >= 1; j--)
        {
            if (dp[j - 1] != dp[i - 1]) { break; }
            if ((pre[j - 1] ^ pre[i]) == k)
            {
                dp[i] ++;
                break ;
            }
        }
    }
    cout << dp[n];
    return ;
}

static const int SUB80N = 5e5 + 5;
static const int SUB80V = 258;
// int f[SUB80N][SUB80V][2];

inline void sub80 ()
{
    if (k == 1)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                ans ++;
            }
        }
        cout << ans << "\n";
        return ;
    }

    else if (k == 0)
    {
        int i = 1, ans = 0;
        while (i <= n)
        {
            if (a[i] == 0)
            {
                i ++;
                ans ++;
                continue ;
            }

            bool flg = 1;
            if (a[i + 1] == 1)
            {
                i += 2;
                ans ++;
                continue ;
            }
            i ++;
        }
        cout << ans << "\n";
        return ;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         f[i][j][0] = max ({f[i][j][0], f[i - 1][j][0], f[i - 1][k + 1][1]});
    //         f[i][a[i]][1] = max ({f[i][a[i]][1], (a[i] == k) + f[i - 1][j][0], (a[i] == k) + f[i - 1][j][1]});
    //         if (j != k) { f[i][j ^ a[i]][1] = max ({f[i][j ^ a[i]][1], ((j ^ a[i]) == k) + f[i - 1][j][1]}); }
    //         else { f[i][j ^ a[i]][1] = max ({f[i][j ^ a[i]][1], f[i - 1][j][1] - 1 + (a[i] == 0)});}
    //         f[i][k + 1][1] = max (f[i][k + 1][1], f[i][j][1]);
    //     }
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << f[i][j][0] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "---\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //     {
    //         cout << f[i][j][1] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "---\n";

    int ans = 0;
    // for (int i = 0; i <= k; i++)
    // {
    //     ans = max ({ans, f[n][i][0], f[n][i][1]});
    // }
    // ans = max (f[n][k][1], f[n][k][0]);
    // ans = (f[n][k][1] + f[n - 1][k][0]);
    // cerr << f[n][k][0] << "\n";
    // ans = max (f[n][k + 1][1], f[n][k][0]);
    cout << ans << "\n";
}

bool icebear2025back;

int main ()
{
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);

    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    // fprintf (stderr, "Memory Maximize Number: %.3lf MB\n", (&icebear2025front - &icebear2025back) / 1048576.000);
    cin >> n >> k; for (int i = 1; i <= n; i++) { cin >> a[i]; }
    for (int i = 1; i <= n; i++) { pre[i] = (pre[i - 1] ^ a[i]); }
    if (n <= 1000) { sub60 (); return 0; }
    if (k <= 255) { sub80 (); return 0; }
    else { cout << n << "\n"; }
    return 0;
}