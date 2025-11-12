#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAXN = 2005;
const ull base = 131;
map<pair<ull, ull>, int> mp;
ull ha[MAXN], hb[MAXN], pw[MAXN];
int n, q;
ull hsh1(int l, int r)
{
    return ha[r] - ha[l - 1] * pw[r - l + 1];
}
ull hsh2(int l, int r)
{
    return hb[r] - hb[l - 1] * pw[r - l + 1];
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        ull h1 = 0, h2 = 0;
        cin >> s1 >> s2;
        int sz1 = s1.size(), sz2 = s2.size();
        for (int j = 0; j < sz1; j++)
        {
            h1 *= base;
            h1 += s1[j] - 'a' + 1;
        }
        for (int j = 0; j < sz2; j++)
        {
            h2 *= base;
            h2 += s2[j] - 'a' + 1;
        }
        mp[{h1, h2}]++;
    }
    pw[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pw[i] = pw[i - 1] * base;
    while (q--)
    {
        string t1, t2;
        cin >> t1 >> t2;
        int sz1 = t1.size(), sz2 = t2.size();
        if (sz1 != sz2)
        {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i <= sz1; i++)
            ha[i] = (ha[i - 1] * base) + (t1[i - 1] - 'a' + 1);
        for (int i = 1; i <= sz2; i++)
            hb[i] = (hb[i - 1] * base) + (t2[i - 1] - 'a' + 1);
        long long ans = 0;
        for (int l = 1; l <= sz1; l++)
            for (int r = l; r <= sz1; r++)
                if ((l == 1 || hsh1(1, l - 1) == hsh2(1, l - 1)) && (r == sz1 || hsh1(r + 1, sz1) == hsh2(r + 1, sz1)))
                ans += mp[{hsh1(l, r), hsh2(l, r)}];
        cout << ans << '\n';
    }
    return 0;
}
