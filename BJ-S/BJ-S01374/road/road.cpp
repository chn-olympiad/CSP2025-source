#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int fa[10005];
int find(int x)
{
    if(x == fa[x])
    {
        return x;
    }
    else
    {
        return fa[x] = find(fa[x]);
    }
}
struct node
{
    int u, v;
    long long w;
};
struct cmp
{
    bool operator()(node a, node b)
    {
        return a.w > b.w;
    }
};
long long ans;
priority_queue<node, vector<node>, cmp> p;
void uni(int u, int v)
{
    int _u = find(u);
    int _v = find(v);
    if(_u != _v)
    {
        fa[_u] = _v;
    }
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= m; i ++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        node c;
        c.u = u;
        c.v = v;
        c.w = w;
        p.push(c);
    }
    for(int i = 1; i < n; i ++)
    {
        while(find(p.top().u) == find(p.top().v));
        uni(p.top().u, p.top().v);
        ans += p.top().w;
        p.pop();
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}