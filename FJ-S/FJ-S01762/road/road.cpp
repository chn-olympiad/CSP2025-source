#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
#define pb push_back
const int N = 1e4 + 15, M = 1e6 + 5;
int n, m, k, fa[N], a[N], c; ll ans, C[1<<10];
struct edge {int u, v, w;} o[M]; vector <edge> e[1<<10];
void init(int n) {for (int i = 1; i <= n; i++) fa[i] = i;}
int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
ll kruskal(int n, vector <edge>& e)
{
    ll ans = 0; init(n); sort(e.begin(), e.end(), [&](edge x, edge y){return x.w < y.w;});
    int cnt = 0, m = e.size(); ll ret = 0;
    for (int i = 0; i < m; i++)
    {
        if (cnt == n - 1) break; int ru = find(e[i].u), rv = find(e[i].v);
        if (ru == rv) continue; e[cnt++] = e[i]; fa[ru] = rv; ret += e[i].w;
    }
    e.resize(cnt); return ret;
}
int main()
{
    FILE("road");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) cin >> o[i].u >> o[i].v >> o[i].w;
    sort(o + 1, o + m + 1, [&](edge x, edge y){return x.w < y.w;}); init(n);
    for (int i = 1, cnt = 0; i <= m; i++)
    {
        if (cnt == n - 1) break; int ru = find(o[i].u), rv = find(o[i].v);
        if (ru == rv) continue; fa[ru] = rv; cnt++; e[0].pb(o[i]); ans += o[i].w;
    }
    int S = 1;
    for (int i = 1; i <= k; i++) 
    {
        cin >> c; for (int j = 1; j <= n; j++) cin >> a[j];
        for (int T = 0; T < S; T++)
        {
            e[T+S] = e[T]; C[T+S] = C[T] + c; int nn = (int)e[T].size() + 2;
            for (int j = 1; j <= n; j++) e[T+S].pb({nn, j, a[j]});
            ans = min(ans, C[T+S] + kruskal(nn, e[T+S]));
        }
        S <<= 1;
    }
    cout << ans << "\n";
    return 0;
}