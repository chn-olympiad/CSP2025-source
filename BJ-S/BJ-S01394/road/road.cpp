#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct edge
{
    int u, v;
    int w;
};
bool operator< (edge x, edge y)
{
    return x.w > y.w;
}
priority_queue<edge> q;
int fa[N];
int find(int x)
{
    if (fa[x] == x) return x;
    else return (fa[x] = find(fa[x]));
}
int c[N];
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        q.push({u, v, w});
    }
    for (int i = 1; i <= k; i ++)
    {
        int x;
        cin >> x;
        int pos;
        for (int j = 1; j <= n; j ++)
        {
            cin >> c[j];
            if (c[j] == 0) pos = j;
        }
        for (int j = 1; j <= n; j ++)
            if (j != pos)
                q.push({j, pos, c[j]});
    }
    for (int i = 1; i <= n; i ++) fa[i] = i;
    int ans = 0;
    while (!q.empty())
    {
        int u = q.top().u, v = q.top().v, w = q.top().w;
        q.pop();
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ans += w;
        }
    }
    cout << ans;

    return 0;
}