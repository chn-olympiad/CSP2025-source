#include <bits/stdc++.h>
using namespace std;
string ss[200005], tt[200005];
int ssposb[200005], ttposb[200005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> ss[i] >> tt[i];
    }
    while (q--)
    {
        string s, t;
        cin >> s >> t;
        if (s.length() != t.length())
        {
            cout << 0 << endl;
            continue;
        }
        int l, r;
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (flag && s[i] != t[i])
            {
                l = i;
                flag = false;
            }
            if (s[i] != t[i])
            {
                r = i;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ss[i].length() <= r - l || ss[i].length() > s.length())
            {
                continue;
            }
            for (int j = max(int(r - ss[i].length()) + 1, 0); j <= l; j++)
            {
                if (s.substr(j, ss[i].length()) == ss[i] && t.substr(j, tt[i].length()) == tt[i])
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
