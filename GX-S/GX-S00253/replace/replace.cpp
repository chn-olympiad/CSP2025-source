#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, q;
string s1[N], s2[N];

bool cmp(string a, string b)
{
    int len = a.size();
    for (int i = 0; i < len; i ++ )
        if (a[i] != b[i])
            return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
    for (int i = 1; i <= q; i ++ )
    {
        string t1, t2;
        cin >> t1 >> t2;
        int c1 = t1.size(), c2 = t2.size();
        if (c1 != c2)
        {
            cout << 0 << '\n';
            continue;
        }
        int res = 0;
        for (int j = 1; j <= n; j ++ )
        {
            int len1 = s1[j].size();
            for (int k = 0; k < c1; k ++ )
            {
                string cp = t1.substr(k, len1);
                if (cmp(cp,s1[j]))
                {
                    string newt1 = "";
                    for (int x = 0; x < max(c1, len1); x ++ )
                        if (x < k + len1) newt1 += s2[j][x];
                        else newt1 += t1[x];
                    if (cmp(newt1, t2)) res ++;
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}
