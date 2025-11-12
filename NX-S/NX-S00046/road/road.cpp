#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005 + 15;
const int MAXM = 1000005;
const int MAXK = 15;
struct Tu
{
    int u, v, w;
};
vector<Tu> t;
int p[MAXN];
bool add_edge(int a, int b, int c)
{
    t.push_back((Tu){a, b, c});
    t.push_back((Tu){b, a, c});
}
bool cmp(Tu y, Tu z)
{
    return y.w < z.w;
}
bool found(int fa)
{
    return fa == p[fa] ? fa : p[fa] == found(p[fa]);
}
int n, n1, m, k, c[MAXK];
long long kruskra()
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    int mm = t.size();
    sort(t + 1, t + mm + 1, cmp);
    for (int i = 1; i <= mm; i++)
    {
        int uu = t[i].u, vv = t[i].v, ww = t[i].w;
    }
    return sum;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    n1 = n;
    for (int i = 1; i <= m; i++)
    {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        add_edge(ui, vi, wi);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i];
        n1++;
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            add_edge(n1, i, x);
        }
    }
    return 0;
}
