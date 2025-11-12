#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 50, M = 1.5e6 + 5, K = 10, inf = 1e18;
struct node
{
    int x, y, w;
    bool operator<(const node &tmp) const{return w < tmp.w;}
}edg[2][M], etown[K][N], ecity[N];
int n, m, k, c = 0, cnt[2], fa[N], w[N];
int find(int x) {return fa[x] == x?x:fa[x] = find(fa[x]);}
int kruskal()
{
    for(int i = 1; i <= n + k; i++) fa[i] = i;
    int res = 0;
    for(int i = 1; i <= cnt[c]; i++)
    {
        if(find(edg[c][i].x) == find(edg[c][i].y)) continue;
        fa[find(edg[c][i].x)] = find(edg[c][i].y), res += edg[c][i].w;
    }
    return res;
}
void insert(int tid)
{
    c ^= 1;
    int t1 = 1, t2 = 1, tot = 0;
    while(t1 <= cnt[c ^ 1] || t2 <= n)
    {
        if(t2 <= n && (t1 > cnt[c ^ 1] || edg[c ^ 1][t1].w > etown[tid][t2].w)) edg[c][++tot] = etown[tid][t2], t2++;
        else edg[c][++tot] = edg[c ^ 1][t1], t1++;
    }
    cnt[c] = tot;
}
signed main()
{
    freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) cin >> edg[c][i].x >> edg[c][i].y >> edg[c][i].w;
    for(int i = 0; i < k; i++)
    {
        cin >> w[i];
        for(int j = 1; j <= n; j++)
            cin >> etown[i][j].w, etown[i][j].x = n + i + 1, etown[i][j].y = j;
        sort(etown[i] + 1, etown[i] + n + 1);
    }
    sort(edg[c] + 1, edg[c] + m + 1);
    for(int i = 1,j = 0; i <= m; i++)
    {
        if(find(edg[c][i].x) == find(edg[c][i].y)) continue;
        fa[find(edg[c][i].x)] = find(edg[c][i].y), ecity[++j] = edg[c][i];
    }
    int res = inf;
    for(int i = 0; i < (1 << k); i++)
    {
        for(int j = 1; j < n; j++) edg[c][j] = ecity[j];
        cnt[c] = n - 1;
        int tmp = 0;
        for(int j = 0; j < k; j++)
            if((i >> j) & 1) tmp += w[j], insert(j);
        res = min(res, tmp + kruskal());
    }
    cout << res;
    return 0;
}