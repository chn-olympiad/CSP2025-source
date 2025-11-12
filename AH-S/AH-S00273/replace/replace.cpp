#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, q, ans, b[N][4];
string s[N][4], t1, t2;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> s[i][1] >> s[i][2];
    for (int i = 1; i <= n; ++i)
    {
        int j, x, y;
        for (j = 0; s[i][1][j] == 'a' && j < s[i][1].size(); ++j); b[i][1] = j;
        for (j = 0; s[i][2][j] == 'a' && j < s[i][2].size(); ++j); b[i][2] = j;
    }
    while (q--)
    {
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << '\n';
            continue;
        }
        ans = 0;
        int i, b1, b2;
        for (i = 0; t1[i] == 'a' && i < t1.size(); ++i); b1 = i;
        for (i = 0; t2[i] == 'a' && i < t2.size(); ++i); b2 = i;
        for (int i = 1; i <= n; ++i)
        {
            int x = b[i][1], y = b[i][2];
            if (x - y == b1 - b2 && x <= b1 && y <= b2 && s[i][1].size() - x <= t1.size() - b1 && s[i][2].size() - y <= t2.size() - b2) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
