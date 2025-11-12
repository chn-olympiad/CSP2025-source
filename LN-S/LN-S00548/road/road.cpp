#include <bits/stdc++.h>
using namespace std;
int n,m,k,num=0,id=0,fa[100002]={0},ans = 0;
struct node
{
    int u,v,w;
    bool operator < (const node s) const
    {
        return w > s.w;
    }
};
priority_queue<node> q;
int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) fa[i] = i;
    for (int i = 1;i <= m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        q.push({u,v,w});
    }
    for (int i = 1;i <= m;i++)
    {
        if (num == n-1) break;
        auto [u,v,w] = q.top(); q.pop();
        int x = getfa(u),y = getfa(v);
        if (u != v)
        {
            cout << u << ' ' << v << ' ' << w << '\n';
            fa[x] = y;
            ans += w;
            num++;
        }
    }
    cout << ans;
    return 0;
}
