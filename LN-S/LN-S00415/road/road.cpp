#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define bit(n, i) (((n) >> (i)) & 1)
#define bit1(n, i) ((n) | (1 << (i)))
#define bit0(n, i) ((n) & ~(1 << (i)))
using namespace std;
typedef long long LL;

int n, m, k;
int c[12];
vector<pair<int, pair<int, int>>> g, a[12];
vector<pair<int, pair<int, int>>> e[1102];

int s[10014];
void clr() { for (int i = 1; i <= n + k; i++) s[i] = i; }
int prnt(int u) { return (s[u] == u) ? u : (s[u] = prnt(s[u])); }
void cnct(int u, int v) { s[prnt(u)] = prnt(v); }
bool srch(int u, int v) { return prnt(u) == prnt(v); }

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({ w, { u, v } });
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            a[i].push_back({ w, { i + n, j } });
        }
        sort(a[i].begin(), a[i].end());
        a[i].push_back({ inf, { 1, 1 } });
    }
    sort(g.begin(), g.end());
    clr();
    LL ans = 0;
    for (auto i : g)
        if (!srch(i.second.first, i.second.second))
        {
            cnct(i.second.first, i.second.second);
            e[0].push_back(i), ans += i.first;
        }
    e[0].push_back({ inf, { 1, 1 } });
    for (int i = 1; i < (1 << k); i++)
    {
        int x = 0;
        LL nans = 0;
        for (int j = 0; j < k; j++)
            if (bit(i, j)) x = j, nans += c[j + 1];
        vector<pair<int, pair<int, int>>> ng;
        int y = bit0(i, x), p = 0, q = 0;
        while (p + 1 < e[y].size() || q + 1 < a[x + 1].size())
        {
            if (e[y][p].first < a[x + 1][q].first) ng.push_back(e[y][p]), p++;
            else ng.push_back(a[x + 1][q]), q++;
        }
        clr();
        for (auto j : ng)
            if (!srch(j.second.first, j.second.second))
            {
                cnct(j.second.first, j.second.second);
                e[i].push_back(j), nans += j.first;
            }
        e[i].push_back({ inf, { 1, 1 } });
        ans = min(ans, nans);
    }
    cout << ans;
    return 0;
}
