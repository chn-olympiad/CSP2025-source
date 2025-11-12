# include <bits/stdc++.h>

using namespace std;

static const int N = 2e5 + 5;
string s[N][3];
int n, q;

inline void sub10 ()
{
    set <pair <string, string>> st;
    string t1, t2;
    for (int i = 1; i <= q; i++)
    {
        cin >> t1 >> t2;
        t1 = " " + t1; t2 = " " + t2;
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            ans ++;
        }
        cout << ans << "\n";
    }
}

int main ()
{
    freopen ("replace.in", "r", stdin);
    freopen ("replace.out", "w", stdout);
    ios_base :: sync_with_stdio (0);
    cin.tie (nullptr), cout.tie (nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) { cin >> s[i][1] >> s[i][2]; s[i][1] = " " + s[i][1]; s[i][2] = " " + s[i][2]; }
    if (n <= 100 && q <= 100) { sub10 (); return 0; }
    return 0;
}