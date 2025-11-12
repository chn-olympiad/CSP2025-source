#include <bits/stdc++.h>
using namespace std;

struct node
{
    string s, t;
    int len;
    friend bool operator<(node a, node b)
    {
        if (a.s.back() != b.s.back())
            return a.s.back() < b.s.back();
        return a.t.back() < b.t.back();
    }
} c[200005];
int n, q, len, dp[5000005];
bool vis[200005];
string s, t;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> s >> t, c[i] = {s, t, (int)s.size()};
    sort(c + 1, c + n + 1);
    dp[0] = 1;
    while (q--)
    {
        cin >> s >> t;
        if (s.size() != t.size())
            cout << 0 << '\n';
        else
        {
            len = s.size();
            fill(dp + 1, dp + len + 1, 0);
            for (int i = 1; i <= len; i++)
            {
                if (s[i - 1] == t[i - 1])
                    dp[i] = dp[i - 1];
                node nn = {s.substr(0, i), t.substr(0, i), i};
                int l = lower_bound(c + 1, c + n + 1, nn) - c, r = upper_bound(c + 1, c + n + 1, nn) - c;
                for (int j = l; j <= n; j++)
                    if (i >= c[j].len && s.substr(i - c[j].len, c[j].len) == c[j].s && t.substr(i - c[j].len, c[j].len) == c[j].t)
                        dp[i] += dp[i - c[j].len];
            }
            cout << dp[len] << '\n';
        }
    }
    return 0;
}
