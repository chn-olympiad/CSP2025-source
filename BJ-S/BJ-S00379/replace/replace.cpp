#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, q, ans, tot, a[MAXN];
string s1, s2, s[MAXN][2];
signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
    while (q--)
    {
        cin >> s1 >> s2;
        if (s1.size() != s2.size()) {cout << 0 << endl; continue;}
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            string temp = s1.substr(0, s[i][0].size());
            int idx = 0;
            tot = 0;
            while (idx + s[i][0].size() - 1 < s1.size())
            {
                if (temp == s[i][0]) a[tot++] = idx;
                temp = temp.substr(1) + s1[idx + s[i][0].size()];
                idx++;
            }
            for (int j = 0; j < tot; j++)
                if (s2 == s1.substr(0, a[j]) + s[i][1] + s1.substr(a[j] + s[i][0].size())) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}