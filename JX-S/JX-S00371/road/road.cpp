#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using pi = pair<int, int>;
const int N = 10005, M = 1000005, NK = 100005, K = 11;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k, ew[M], c[N];
int b[2 * M], bn;
int getrk(int x)
{
    return (lower_bound(b + 1, b + bn + 1, x) - b);
}
struct Edge{
    int u, v, w;
    bool operator < (const Edge & t) const{
        return (w < t.w);
    }
}e[M];
struct LQ{
    Edge ex;
    int ne;
}lq[NK];
int h[M][K], idx;
void add(int uid, int id, Edge x)
{
    lq[++idx] = {x, h[uid][id]};
    h[uid][id] = idx;
}
pi ax[K][N];

struct DSU{
    int fa[N];
    void init()
    {
        for(int i = 1; i <= n + k; i++) fa[i] = i;
    }
    int findf(int x)
    {
        if(fa[x] != x) fa[x] = findf(fa[x]);
        return fa[x];
    }
    void combine(int x, int y)
    {
        int fx = findf(x), fy = findf(y);
        fa[fx] = fy;
    }
}dsu1;
ll ans = inf, res;
Edge MST_e[M];
bitset<N> gt;

void solve(int st)
{
    //cerr << "========" << st << "========" << endl;
    res = 0;
    gt[0] = 1;
    int popc = 0;
    for(int i = 0; i < k; i++)
    {
        gt[i + 1] = ((st >> i) & 1);
        if(gt[i + 1]) res += c[i + 1], popc++;
    }
    //cerr << "sumc = " << res << endl;
    dsu1.init();
    int nowm = n + popc;
    for(int i = 1; i <= bn; i++)
    {
        for(int vrt = 0; vrt <= k; vrt++)
        {
            if(gt[vrt] == 0) continue;
            for(int j = h[i][vrt]; j ; j = lq[j].ne)
            {
                Edge eg = lq[j].ex;
                int u = eg.u, v = eg.v, w = eg.w;
                if(dsu1.findf(u) == dsu1.findf(v)) continue;
                dsu1.combine(u, v);
                //cerr << "Add Edge " << u << " <-> " << v << ", w = " << b[i] << ", eid = " << vrt << endl;
                res += b[i];
                nowm--;
                if(nowm == 1) break;
            }
            if(nowm == 1) break;
        }
        if(nowm == 1) break;
    }
    ans = min(ans, res);
    // cerr << st << ": " << res << endl;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // in
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    // MST1
    sort(e + 1, e + m + 1);
    dsu1.init();
    int nowm = 0;
    res = 0;
    for(int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(dsu1.findf(u) == dsu1.findf(v)) continue;
        dsu1.combine(u, v);
        res += w;
        b[++bn] = w;
        MST_e[++nowm] = e[i];
    }
    ans = min(ans, res);
    // cerr << "ori: " << res << endl;
    m = 0;
    for(int i = 1; i <= nowm; i++)
    {
        e[i] = MST_e[i];
    }
    m = nowm;
    for(int i = 1; i <= m; i++) ew[i] = e[i].w;
    ew[m + 1] = 0x3f3f3f3f;
    // Get Ks
    for(int i = 1; i <= k; i++)
    {
        cin >> c[i];
        for(int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            b[++bn] = w;
            ax[i][j] = {w, j};
        }
    }
    // lsh
    sort(b + 1, b + bn + 1);
    bn = unique(b + 1, b + bn + 1) - b - 1;
    // insert
    for(int i = 1; i <= m; i++)
    {
        int nid = getrk(e[i].w);
        add(nid, 0, e[i]);
    }
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int w = ax[i][j].fi;
            int nid = getrk(w);
            add(nid, i, {i + n, ax[i][j].se, w});
        }
    }
    for(int i = 1; i < (1 << k); i++)
    {
        solve(i);
    }
    cout << ans;
    return 0;
}