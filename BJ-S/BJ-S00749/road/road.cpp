#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const int MAXK = 12;
int n, m, k, fa[MAXN], tot = 0, tot2 = 0, C[MAXK]; long long ans = 0;
struct Edge
{
    int u, v, w;
} E1[MAXN], E[MAXN], E2[MAXN], E3[MAXN], E4[MAXN];
struct Node
{
    int v, w;
} A[MAXK][MAXN];
bool Cmp(Edge x, Edge y) { return x.w < y.w; }
bool Cmp2(Node x, Node y) { return x.w < y.w; }
int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++) cin >> E1[i].u >> E1[i].v >> E1[i].w;
    sort(E1 + 1, E1 + m + 1, Cmp);
    for(int i = 1; i <= n; i ++) fa[i] = i;
    for(int i = 1; i <= m; i ++)
    {
        int u = E1[i].u, v = E1[i].v, w = E1[i].w; int fu = find(u), fv = find(v);
        if(fu == fv) continue;
        fa[fu] = fv; ans += w; E[++ tot] = Edge{u, v, w};
    }
    if(k == 0) { cout << ans << '\n'; return 0; }
    for(int i = 0; i < k; i ++)
    {
        cin >> C[i];
        for(int j = 1; j <= n; j ++)
        {
            cin >> A[i][j].w;
            A[i][j].v = j;
        }
        sort(A[i] + 1, A[i] + n + 1, Cmp2);
    }
    for(int i = 1; i < (1 << k); i ++)
    {
        tot2 = 0; long long nowans = 0;
        for(int j = 1; j <= tot; j ++) E2[++ tot2] = E[j];
        for(int j = 0; j < k; j ++)
        {
            if(!(i & (1 << j))) continue;
            nowans += C[j]; int tot3 = 0, tot4 = 0;
            for(int l = 1; l <= n; l ++) E3[++ tot3] = Edge{n + j + 1, A[j][l].v, A[j][l].w};
            int pos1 = 1, pos2 = 1;
            while(pos1 <= tot2 && pos2 <= tot3)
            {
                if(E2[pos1].w <= E3[pos2].w) { E4[++ tot4] = E2[pos1]; pos1 ++; }
                else { E4[++ tot4] = E3[pos2]; pos2 ++; }
            }
            while(pos1 <= tot2) { E4[++ tot4] = E2[pos1]; pos1 ++; }
            while(pos2 <= tot3) { E4[++ tot4] = E3[pos2]; pos2 ++; }
            for(int l = 1; l <= tot4; l ++) E2[l] = E4[l];
            tot2 = tot4;
        }
        // sort(E2 + 1, E2 + tot2 + 1, Cmp);
        for(int j = 1; j <= n + k; j ++) fa[j] = j;
        for(int j = 1; j <= tot2; j ++)
        {
            int u = E2[j].u, v = E2[j].v, w = E2[j].w; int fu = find(u), fv = find(v);
            if(fu == fv) continue;
            fa[fu] = fv; nowans += w;
        }
        ans = min(ans, nowans);
    }
    cout << ans << '\n';
    return 0;
}
