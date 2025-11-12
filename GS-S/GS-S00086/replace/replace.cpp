#include <bits/stdc++.h>
#define int long long
using namespace std;

string rep[200010][2];
int n, q;

inline void solve(string a, string b)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < a.size() - rep[i][0].size() + 1; j++){
            if (j + rep[i][0].size() > a.size()){
                continue;
            }
            if (a.substr(j, rep[i][0].size()) == rep[i][0])
            {
                string tempa = a;
                tempa.replace(j, rep[i][0].size(), rep[i][1]);
                if (tempa == b) ans++;
            }
        }
    }
    cout << ans << "\n";
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> rep[i][0] >> rep[i][1];
    }
    while (q--)
    {
        string a, b;
        cin >> a >> b;
        solve(a, b);
    }
    return 0;
}
