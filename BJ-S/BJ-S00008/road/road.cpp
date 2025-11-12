#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, fa[10010], ans = 1e18;
bool flag[20];
struct node{
    int u, v, w;
}adj[1000100], adj1[1000100];
struct cs{
    int c, w[1000010];
}b[20];
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    fa[find(y)] = find(x);
}
bool cmp(node x, node y)
{
    return x.w < y.w;
}
int kk(int n, int m)
{
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++)
    {
        if(find(adj[i].u) != find(adj[i].v))
        {
            cnt++;
            merge(adj[i].u, adj[i].v);
            ans += adj[i].w;
        }
        if(cnt == n - 1) return ans;
    }
    return -1;
}
void dfs(int step, int sum, int c)
{
    if(step > k)
    {
        int cnt = n;
        for(int i = 1; i <= n + k; i++) adj[i] = adj1[i];
        for(int i = 1; i <= k; i++)
            if(flag[i])
                for(int j = 1; j <= n; j++)
                {
                    adj[++cnt].u = n + i;
                    adj[cnt].v = j;
                    adj[cnt].w = b[i].w[j];
                }
        //cout << ans << endl;
        sort(adj + 1, adj + cnt + 1, cmp);
        //for(int i = 1; i <= cnt; i++) cout << adj[i].u << " " << adj[i].v << " " << adj[i].w << endl;
        ans = min(ans, kk(c + n, cnt) + sum);
        //cout << kk(c + n, cnt) << endl;
        return;
    }
    flag[step] = true;
    dfs(step + 1, sum + b[step].c, c + 1);
    flag[step] = false;
    dfs(step + 1, sum, c);
}
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> adj[i].u >> adj[i].v >> adj[i].w, adj1[i] = adj[i];
    sort(adj + 1, adj + n + 1, cmp);
    for(int i = 1; i <= k; i++)
    {
        cin >> b[i].c;
        for(int j = 1; j <= n; j++) cin >> b[i].w[j];
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
