#include <bits/stdc++.h>
using namespace std;
int n, q;
struct dbpr
{
    string a, b;
}s[200005];
string t1, t2;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].a >> s[i].b;
    }
    while (q--)
    {
        int ans = 0;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        bool flag = true;
        for (int k = 0; k < t1.size(); k++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (t1[k] == s[i].a[0] && t2[k] == s[i].b[0])
                {
                    flag = true;
                    for (int u = k; u <= k + s[i].a.size() - 1; u++)
                    {
                        if (t1[u] != s[i].a[u-k] || t2[u] != s[i].b[u-k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false)
                    {
                        continue;
                    }
                    for (int u = k + s[i].a.size(); u <= t1.size(); u++)
                    {
                        if (t1[u] != t2[u])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == false)
                    {
                        continue;
                    }
                    for (int u = k - 1; u >= 0; u--)
                    {
                        if (t1[u] != t2[u])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag == true)
                    {
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
