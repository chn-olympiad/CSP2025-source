#include <bits/stdc++.h>
using namespace std;

int n, q, ans = 0;

string s[200010][3];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    while (q--)
    {
        ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        for (int i = 1; i <= n; i++)
        {
            if (t1.size() < s[i][1].size()) continue;
            for (int j = 0; j <= t1.size() - s[i][1].size(); j++)
            {
                if (t1.substr(j, s[i][1].size()) == s[i][1] && t2.substr(j, s[i][2].size()) == s[i][2])
                {
                    if (t1.substr(0, j) == t2.substr(0, j) && t1.substr(j + s[i][1].size(), t1.size() - (j + s[i][1].size())) == t2.substr(j + s[i][1].size(), t1.size() - (j + s[i][1].size()))) ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
