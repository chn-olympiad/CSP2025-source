#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
} a[1000005];
struct nowe
{
    int to, num;
};
int s[100005];
bool vis[1000005];
int n, m, k;
vector<nowe> g[100005];
int getfa(int x)
{
    if(x != s[x]) s[x] = getfa(s[x]);
    return s[x];
}
bool cmp(node x, node y)
{
    return x.w < y.w;
}
int cal()
{
    sort(a + 1, a + m + 1, cmp);
    for(int i = 1; i <= n;i++) s[i] = i;
    int ans = 0, cnt = 0;
    for(int i = 1; i <= m;i++)
    {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        int rootu = getfa(u), rootv = getfa(v);
        if(rootu != rootv)
        {
            ans += w;
            s[rootu] = rootv;
            vis[i] = 1;
            cnt++;
        }
        if(cnt == n - 1) break;
    }
    return ans;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= m;i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        g[a[i].u].push_back({a[i].v, a[i].w});
        g[a[i].w].push_back({a[i].u, a[i].w});
    }
    int nox = cal();//最小生成树判断无乡镇
    cout << nox << endl;
   // for()
    return 0;
}
