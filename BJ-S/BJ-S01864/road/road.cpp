#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to, len;
};
bool operator<(const edge x, const edge y)
{
    return x.len > y.len;
}
bool fl[15];
vector<edge> v[10005];
int n, k, m, c[15], a[15][10005];
priority_queue<edge> q;
long long ans = 1e18;
bool f[10005];
void addd(int x)
{
    if(x > n)
    {
        for(int i = 1;i <= n;i++) q.push({i, a[x - n][i]});
        return ;
    }
    for(int i = 0;i < v[x].size();i++)
    {
        q.push(v[x][i]);
    }
    for(int i = 1;i <= k;i++)
    {
        if(fl[i]) q.push({n + i, a[i][x]});
    }
}
long long zxscs(int x)
{
    while(!q.empty())
    {
        q.pop();
    }
    addd(1);
    f[1] = true;
    int cnt = 1;
    long long tmp = 0;
    while(!q.empty())
    {
        edge t = q.top();
        q.pop();
        if(f[t.to]) continue;
        f[t.to] = true;
        tmp += t.len;
        cnt++;
        addd(t.to);
        if(cnt >= x) break;
    }
    return tmp;
}
void dfs(int t)
{
    if(t > k)
    {
        int cnt = 0, amt = 0;
        for(int i = 1;i <= k;i++)
        {
            cnt += fl[i] * c[i];
            amt += fl[i];
        }
        memset(f, false, sizeof(f));
        ans = min(ans, cnt + zxscs(amt + n));
        return ;
    }
    fl[t] = true;
    dfs(t + 1);
    fl[t] = false;
    dfs(t + 1);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int u, v1, w;
        scanf("%d%d%d", &u, &v1, &w);
        v[u].push_back({v1, w});
        v[v1].push_back({u, w});
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        for(int j = 1;j <= n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}
