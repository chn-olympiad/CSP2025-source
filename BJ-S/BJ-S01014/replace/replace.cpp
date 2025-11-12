#include <bits/stdc++.h>
using namespace std;
pair<string, string> s[200010], t[200010];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i].first >> s[i].second;
    }
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            string t3 = t1;
            int nn = t1.size();
            int nnn = s[i].first.size();
            for (int j = 0; j < nn; ++j)
            {
                bool flag = true;
                for (int k = 0; k < nnn; ++k)
                {
                    if (!flag) continue;
                    if (j + k >= nn)continue;
                    if (s[i].first[k] != t1[j + k]) 
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    for (int k = 0; k < nnn; ++k)
                    {
                        t3[j + k] = s[i].second[k];
                    }
                    if (t3 == t2) ++ans;
                }
                t3 = t1;
            }
            
        }
        cout << ans << "\n";
    }
    return 0;
}
