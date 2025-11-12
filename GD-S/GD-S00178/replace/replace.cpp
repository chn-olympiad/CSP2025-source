#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define MAXN 2500006

using Edges = map<short, int>;
using psi = pair<short, int>;
using ll = long long;

struct Tree
{
    int v;
    Edges s;
    int fail;
} t[MAXN];
int rt = 0, idx = 0;

int n, m;

string a, b;
short c[MAXN];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (n--)
    {
        cin >> a >> b;
        int p = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            short c = short((a[i] - 'a') * 26 + (b[i] - 'a'));
            if (!t[p].s.count(c))
            {
                t[p].s[c] = ++idx;
            }
            p = t[p].s[c];
            // cout << p << ' ';
        }
        // cout << '\n';
        t[p].v++;
    }
    queue<int> q;
    for (psi v : t[0].s)
    {
        q.push(v.second);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        t[u].v += t[t[u].fail].v;
        // cout << u << ' ' << t[u].v << ' ' << t[u].fail << '\n';
        for (psi v : t[u].s)
        {
            int p = t[u].fail;
            while (p && !t[p].s.count(v.first))
            {
                p = t[p].fail;
            }
            if (t[p].s.count(v.first))
            {
                t[v.second].fail = t[p].s[v.first];
            }
            q.push(v.second);
        }
    }
    while (m--)
    {
        cin >> a >> b;
        if (a.size() != b.size())
        {
            cout << "0\n";
            continue;
        }
        int fi = 0, la = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            c[i] = short((a[i] - 'a') * 26 + (b[i] - 'a'));
            // cout << c[i] << ' ';
            if (!fi && a[i] != b[i])
            {
                fi = i + 1;
            }
            if (a[i] != b[i])
            {
                la = i;
            }
        }
        // cout << '\n';
        ll res = 0;
        int p = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            while (p && !t[p].s.count(c[i]))
            {
                p = t[p].fail;
            }
            if (t[p].s.count(c[i]))
            {
                p = t[p].s[c[i]];
            }
            if (i >= la)
            {
                res += t[p].v;
            }
            // cout << p << ' ' << t[p].v << '\n';
        }
        p = 0;
        for (int i = fi; i < (int)a.size(); i++)
        {
            while (p && !t[p].s.count(c[i]))
            {
                p = t[p].fail;
            }
            if (t[p].s.count(c[i]))
            {
                p = t[p].s[c[i]];
            }
            if (i >= la)
            {
                res -= t[p].v;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
