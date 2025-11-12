#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k;
int u, v, w;

struct Node
{
    int x, y, z;
    bool operator<(const Node& qwq)const
    {
        return z < qwq.z;
    }
} e[6000005];

int c[15];
int d[10005];    
int ans;

int fa[6000005];

int find(int x)
{
    return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> e[i].x >> e[i].y >> e[i].z;
    int num = m;
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++) cin >> d[j];
        for(int j = 1; j <= n; j++)
            for(int k = j + 1; k <= n; k++)
                e[++num] = {j, k, d[j] + d[k] + c[i]};
    }
    //cout << num;
    //exit(0);
    for(int i = 1; i <= num; i++) fa[i] = i;
    //exit(0);
    sort(e + 1, e + num + 1);
    for(int i = 1; i <= num; i++)
        if(find(e[i].x) != find(e[i].y))
            ans += e[i].z, merge(e[i].x, e[i].y);
    cout << ans;
    

    return 0;
}