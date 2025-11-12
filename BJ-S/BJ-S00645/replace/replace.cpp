#include <bits/stdc++.h>
using namespace std;

#define EOL '\n'
#define int long long

string s[200010], t[200010];
int kmps[200010], kmpt[200010];

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i] >> t[i];
    }
    while (q--)
    {
        string S, T;
        cin >> S >> T;
        if (S.size() != T.size())
        {
            cout << 0 << EOL;
            continue;
        }
        int l = -1, r = -1;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] != T[i])
            {
                if (l == -1)
                {
                    l = i;
                }
                r = i;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            string sS = s[i] + S, tT = t[i] + T;
            kmps[0] = kmpt[0] = 0;
            for (int j = 1; j < sS.size(); ++j)
            {
                int len = kmps[j - 1];
                while (len && sS[len] != sS[j])
                {
                    len = kmps[len - 1];
                }
                kmps[j] = (sS[len] == sS[j]) * (len + 1);
                len = kmpt[j - 1];
                while (len && tT[len] != tT[j])
                {
                    len = kmpt[len - 1];
                }
                kmpt[j] = (tT[len] == tT[j]) * (len + 1);
            }
            for (int j = s[i].size(); j < sS.size(); ++j)
            {
                if (kmps[j] == s[i].size() && kmpt[j] == t[i].size())
                {
                    int p = j - s[i].size();
                    if (p - s[i].size() + 1 <= l && r <= p)
                    {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << EOL;
    }
    return 0;
}
