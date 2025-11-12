#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (isdigit(c))
        x *= 10, x += c - '0', c = getchar();
    return x * f;
}

void write(long long x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int n, q;
string a[200005][2];
unordered_map<string, set<int>> mp;

void kmp(string s, int* nxt)
{
    s = ' ' + s;
    nxt[1] = 0;
    for (int i = 2; i < s.size(); i++)
    {
        int j = i - 1;
        while (j and s[i] != s[nxt[j] + 1])
            j = nxt[j];
        if (j)
            nxt[i] = nxt[j] + 1;
        else
            nxt[i] = 0;
    }
    for (int i = 1; i < s.size(); i++)
        cout << nxt[i] << " ";
    cout << "\n";
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        mp[a[i][0]].insert(i);
        mp[a[i][1]].insert(-i);
    }
    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int m = s1.size(), l = 0, r = 114514191;
        for (int i = 1; i <= m; i++)
        {
            if (s1[i - 1] != s2[i - 1])
            {
                l = i;
                break;
            }
        }
        for (int i = m; i >= 1; i--)
        {
            if (s1[i - 1] != s2[i - 1])
            {
                r = i;
                break;
            }
        }
        // cout << l << " " << r << "\n";
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int sz = a[i][0].size();
            for (int j = 1; j + sz - 1 <= m; j++)
            {
                if (!l or (j <= l and r <= j + sz - 1))
                {
                    auto mp1 = mp.find(s1.substr(j - 1, sz));
                    auto mp2 = mp.find(s2.substr(j - 1, sz));
                    if (mp1 != mp.end() and mp2 != mp.end() and (mp1->second.find(i)) != (mp1->second.end()) and (mp2->second.find(-i)) != (mp2->second.end()))
                        res++;
                }
            }
        }
        cout << res << "\n";
    }
}