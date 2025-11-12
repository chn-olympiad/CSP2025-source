#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int MAXN = 2e5 + 1000;
const int BASE = 131;
#define int long long

int n, q;

int p[(const int)6e6];

vector<int> ss[MAXN];
vector<int> st[MAXN];

string s, t;

int ans = 0;

void solve()
{
    if (s.size() != t.size())
    {
        ans = 0;
        return;
    }

    vector<int> hs, ht;
    hs.resize(s.size());
    ht.resize(t.size());

    hs[0] = s[0];
    ht[0] = t[0];
    for (int i = 1; i < s.size(); i++)
        hs[i] = hs[i - 1] * BASE + s[i];
    for (int i = 1; i < t.size(); i++)
        ht[i] = ht[i - 1] * BASE + t[i];
    // 在这个里面找配对
    int l = 1e9, r = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != t[i])
        {
            l = min(l, i);
            r = max(r, i);
        }
    //[l,r]要整段换
    int hass = 0;
    for (int i = l; i <= r; i++)
        hass = hass * BASE + s[i];
    int hast = 0;
    for (int i = l; i <= r; i++)
        hast = hast * BASE + t[i];

    int len = r - l + 1;

    // 暴力枚举匹配
    ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j + len - 1 < ss[i].size(); j++)
        {
            int has = ss[i][j + len - 1];
            if (j != 0)
                has -= ss[i][j - 1] * p[len];
            int has2 = st[i][j + len - 1];
            if (j != 0)
                has2 -= st[i][j - 1] * p[len];
            if (has == hass && has2 == hast)
            {
                // 找到一处匹配的
                // 跟整个匹配一下
                // s[l-j,l-j+ss[i].size()] & ss[i]
                // t[l-j,l-j+st[i].size()] & st[i]
                if (l - j < 0 || l - j + ss[i].size() > s.size())
                    continue;

                int h1 = hs[l - j + ss[i].size() - 1];
                if (l - j != 0)
                    h1 -= hs[l - j - 1] * p[ss[i].size()];
                if (h1 != ss[i][ss[i].size() - 1])
                    continue;

                int h2 = ht[l - j + st[i].size() - 1];
                if (l - j != 0)
                    h2 -= ht[l - j - 1] * p[st[i].size()];
                if (h2 != st[i][st[i].size() - 1])
                    continue;

                ans++;
            }
        }
}

signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    p[0] = 1;
    for (int i = 1; i <= 5e6 + 100; i++)
        p[i] = p[i - 1] * BASE;

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s, t;
        cin >> s >> t;
        // 转为hash
        ss[i].resize(s.size());
        st[i].resize(t.size());
        ss[i][0] = s[0];
        for (int j = 1; j < s.size(); j++)
            ss[i][j] = ss[i][j - 1] * BASE + s[j];
        st[i][0] = t[0];
        for (int j = 1; j < t.size(); j++)
            st[i][j] = st[i][j - 1] * BASE + t[j];
    }
    while (q--)
    {
        cin >> s >> t;
        ans = 0;
        solve();
        cout << ans << "\n";
    }
}