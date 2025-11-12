#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string s[200005][3];
string t1, t2;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    for (int i = 1; i <= q; i ++)
    {
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << "0\n"; continue;
        }
        for (int x = 0; x < t1.size(); x ++)
        {
            for (int y = 1; y <= t1.size() - x; y ++)
            {
                for (int j = 1; j <= n; j ++)
                {
                    if (s[j][1].size() != y) continue;
                    if (t1.substr(x, y) == s[j][1])
                    {
                        if (t1.substr(0, x) + s[j][2] + t1.substr(x + y, t1.size() - x - y) == t2) ans ++;
                    }
                }
            }
        }
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}
