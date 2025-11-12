#include <bits/stdc++.h>
using namespace std;
struct r
{
    int v;
    long w;
    bool operator< (r b)
    {
        return w > b.w;
    }
};
long n, m, k, u0, v0, w0, ans;
bool g[(long)(1e6+2)];
long place;
r h[(long)(1e6+2)];
vector <r> u[(int)(1e4+2)];
int main()
{
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    cin >> n >> m >> k;
    for (long i = 0; i < m; i++)
    {
        cin >> u0 >> v0 >> w0;
        r t;
        t.v = v0;
        t.w = w0;
        u[u0].push_back(t);
        t.v = u0;
        u[v0].push_back(t);
    }
    for (long i = 0; i < u[1].size(); i++)
    {
        h[place++] = u[1][i];
        sort(h, h+place);
    }
    g[1] = 1;
    while (place != -1)
    {
        r t = h[--place];
        if (!g[t.v])
        {
            ans += t.w;
            g[t.v] = 1;
            for (long i = 0; i < u[t.v].size(); i++)
            {
                h[place++] = u[t.v][i];
                sort(h, h+place);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
