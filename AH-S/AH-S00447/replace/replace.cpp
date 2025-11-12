#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s[200005][2];
ll n, q;
void solve()
{
    cin >> n >> q;
    if (n >= 1e4)
    {
        while (q--)
        {
            cout << "0\n";
        }
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][0] >> s[i][1];
    }
    while (q--)
    {
        string a, b;
        cin >> a >> b;
        if (a.size() != b.size())
        {
            cout << "0\n";
            continue ;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bool f = 0;
            for (int j = 0; j + s[i][0].size() - 1 < a.size(); j++)
            {
                bool flg = 1;
                for (int k = 0; k < s[i][0].size(); k++)
                {
                    if (s[i][0][k] != a[j + k] || s[i][1][k] != b[j + k]) {flg = 0; break ;}
                }
                // if (q == 1 && i == 3) cout << "Corr1" << '\n';
                if (!flg) continue ;
                for (int k = 0; k < j; k++) if (a[k] != b[k]) {flg = 0; break ;}
                // if (q == 1 && i == 3) cout << "Corr2" << '\n';
                if (!flg) continue ;
                for (int k = j + s[i][0].size(); k < a.size(); k++) if (a[k] != b[k]) {flg = 0; break ;}
                // if (q == 1 && i == 3) cout << "Corr3" << '\n';
                if (flg)
                {
                    f = 1;
                    // cout << i << ' ';
                    break ;
                }
            }
            if (f) ans++;
        }
        cout << ans << '\n';
    }
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}