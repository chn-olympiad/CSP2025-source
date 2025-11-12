# include <bits/stdc++.h>

using namespace std;

static const int N = 1e5 + 5;
int n, cnt1, cnt2, cnt3;
struct node { int d1, d2, d3; } a[N];
static const int SUB55N = 2e2 + 5;
int dp[SUB55N][SUB55N][SUB55N];

inline void sub55 ()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                // if (i - j - k > n / 2) { continue ; }
                // if (j > 0) dp[j][k][i - j - k] = max ({dp[j][k][i - j - k], dp[j - 1][k][i - j - k] + a[i].d1});
                // if (k > 0) dp[j][k][i - j - k] = max ({dp[j][k][i - j - k], dp[j][k - 1][i - j - k] + a[i].d2});
                // if (i - j - k > 0) dp[j][k][i - j - k] = max ({dp[j][k][i - j - k], dp[j][k][i - j - k - 1] + a[i].d3});
                if (i - j - k < 0 || i - j - k > n / 2) { continue ; }
                if (j > 0) dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j - 1][k] + a[i].d1);
                if (k > 0) dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k - 1] + a[i].d2);
                if (i - j - k > 0) dp[i][j][k] = max (dp[i][j][k], dp[i - 1][j][k] + a[i].d3);
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= n / 2; j++)
    {
        for (int k = 0; k <= n / 2; k++)
        {
            if (n - j - k <= n / 2) ans = max (ans, dp[n][j][k]);
        }
    }
    
    cout << ans << "\n";

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    return ;
}

bool cmp60 (node x, node y) { return x.d1 >= y.d1; }
inline void sub60 ()
{
    sort (a + 1, a + n + 1, cmp60);
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) { ans += a[i].d1; }
    cout << ans << "\n";
    return ;
}

bool cmp (node x, node y) 
{ 
    return (1.000000 * max ({x.d1, x.d2, x.d3}) / (1.000000 * (x.d1 + x.d2 + x.d3))) > (1.000000 * max ({y.d1, y.d2, y.d3}) / (1.000000 * (y.d1 + y.d2 + y.d3))); 
}
inline void sub70 ()
{
    sort (a + 1, a + n + 1, cmp);
    cnt1 = 0, cnt2 = 0, cnt3 = 0; int ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}

        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}

        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d2) { cnt3 ++; ans += a[i].d3; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d3) { cnt2 ++; ans += a[i].d2; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d1) { cnt3 ++; ans += a[i].d3; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d3) { cnt1 ++; ans += a[i].d1; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d1) { cnt2 ++; ans += a[i].d2; continue;}
        else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d2) { cnt1 ++; ans += a[i].d1; continue;}
    }
    res = max (res, ans);

    for (int t = 1; t <= 4000000 / n; t++)
    {
        random_shuffle (a + 1, a + n + 1);
        ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}

            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d3 && cnt3 < n / 2) { cnt3 ++; ans += a[i].d3; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d1 && cnt1 < n / 2) { cnt1 ++; ans += a[i].d1; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d2 && cnt2 < n / 2) { cnt2 ++; ans += a[i].d2; continue;}

            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d2) { cnt3 ++; ans += a[i].d3; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d1 && max ({a[i].d2, a[i].d3}) == a[i].d3) { cnt2 ++; ans += a[i].d2; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d1) { cnt3 ++; ans += a[i].d3; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d2 && max ({a[i].d2, a[i].d3}) == a[i].d3) { cnt1 ++; ans += a[i].d1; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d1) { cnt2 ++; ans += a[i].d2; continue;}
            else if (max ({a[i].d1, a[i].d2, a[i].d3}) == a[i].d3 && max ({a[i].d2, a[i].d3}) == a[i].d2) { cnt1 ++; ans += a[i].d1; continue;}
        }
        res = max (res, ans);
    }
    cout << res << "\n";
    return ;
}

inline void solve ()
{
    cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i].d1 >> a[i].d2 >> a[i].d3; }
    if (n <= 200) { sub55 (); return ; }
    bool flg = 1; for (int i = 1; i <= n; i++) { if (a[i].d2 != 0 || a[i].d3 != 0) { flg = 0; break; }}
    if (flg) { sub60 (); return ; }
    sub70 (); return ;
}

int main ()
{
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);
    int T; cin >> T; while (T --) { solve (); }
    return 0;
}