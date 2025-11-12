#include <bits/stdc++.h>
#define int long long
using namespace std;
string a[200005], b[200005];
int n, q;
vector <int> fa[200005], fb[200005];
vector <int> pa;
inline void pp(string x, string y, vector <int> &a, vector <int> fail)
{
    a.clear();
    int cur = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != y[cur])
        {
            while (x[i] != y[cur] && cur)
            {
                cur = fail[cur - 1];
            }
        }
        if (x[i] == y[cur])
        {
            cur++;
            if (cur == y.size())
            {
                a.emplace_back(i - y.size() + 1);
                cur = fail[y.size() - 1];
            }
        }
    }
}
unordered_map <int, vector <pair <int, int>>> mp;
inline bool chk()
{
    for (int i = 1; i <= n; i++)
    {
        int ca = 0, cb = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] != 'a' && a[i][j] != 'b')
            {
                return 0;
            }
            if (a[i][j] == 'a')
                ca++;
            else
                cb++;
        }
        if (cb != 1)
            return 0;
        ca = cb = 0;
        for (int j = 0; j < b[i].size(); j++)
        {
            if (b[i][j] != 'a' && b[i][j] != 'b')
            {
                return 0;
            }
            if (b[i][j] == 'a')
                ca++;
            else
                cb++;
        }
        if (cb != 1)
            return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int pa = 0, pb = 0;
        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 'b')
                pa = j;
            if (b[i][j] == 'b')
                pb = j;
        }
        mp[pb - pa].emplace_back(pa, a[i].size());
    }
    return 1;
}
inline int che(string s)
{
    int ca = 0, cb = 0;
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] != 'a' && s[j] != 'b')
        {
            return 0;
        }
        if (s[j] == 'a')
            ca++;
        else
            cb++;
    }
    if (cb != 1)
        return 0;
    return 1;
}
signed main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        fa[i].resize(a[i].size());
        fa[i][0] = 0;
        for (int j = 1; j < a[i].size(); j++)
        {
            int cur = fa[i][j - 1];
            while (a[i][j] != a[i][cur] && cur)
            {
                cur = fa[i][cur - 1];
            }
            if (a[i][j] == a[i][cur])
                fa[i][j] = cur + 1;
        }
        // fb[i].resize(b[i].size());
        // fb[i][0] = 0;
        // for (int j = 1; j < b[i].size(); j++)
        // {
        //     int cur = fb[i][j - 1];
        //     while (b[i][j] != b[i][cur] && cur)
        //     {
        //         cur = fb[i][cur - 1];
        //     }
        //     if (b[i][j] == b[i][cur])
        //         fb[i][j] = cur + 1;
        // }
    }
    string x, y;
    // cin >> x;
    // pp(x, a[1], pa, fa[1]);
    // for (int p : pa)
    // {
    //     cout << p << " ";
    // }
    bool fl = chk();
    while (q--)
    {
        cin >> x >> y;
        if (fl && che(x) && che(y))
        {
            int res = 0;
            int px = 0, py = 0;
            for (int i = 0; i < x.size(); i++)
            {
                if (x[i] == 'b')
                    px = i;
                if (y[i] == 'b')
                    py = i;
            }
            for (auto p : mp[py - px])
            {
                if (p.first <= px && p.second - p.first + px - 1 < x.size())
                    res++;
            }
            cout << res << endl;
            continue;
        }
        int xl = 0x3f3f3f3f3f3f3f3f, xr = 0;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] != y[i])
            {
                xl = min(xl, i);
                xr = max(xr, i);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i].size() > x.size() || a[i].size() < xr - xl + 1)
                continue;
            pp(x, a[i], pa, fa[i]);
            for (int ps : pa)
            {
                if (ps <= xl && ps + a[i].size() - 1 >= xr)
                {
                    if (b[i] == y.substr(ps, a[i].size()))
                        res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}