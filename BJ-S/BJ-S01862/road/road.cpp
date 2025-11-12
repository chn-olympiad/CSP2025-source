#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = l, i##KON = r; i <= i##KON; ++i)
using namespace std;
using ll = long long;
constexpr int N{10005}, M{1000005}, K{10};
int n, m, k, fa[N << 1], ec, id[N], tt;
ll c[K + 5], a[K + 5][N], ans = LLONG_MAX;
struct edge
{
    int u, v;
    ll w;
    edge(int U = 0, int V = 0, ll W = 0) : u{U}, v{V}, w{W}{}
    bool operator<(const edge& o) const
    {
        return w < o.w;
    }
} es[M];
vector<edge> et[1 << K], tmp[K + 5];
inline int f(int x)
{
    return x == fa[x] ? x : fa[x] = f(fa[x]);
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;//cout<<n<<' '<<k<<endl;
    rep(i, 1, m)
        cin >> es[i].u >> es[i].v >> es[i].w;
    rep(i, 1, k)
    {
        cin >> c[i];
        rep(j, 1, n)
        {
            cin >> a[i][j];
            tmp[i].emplace_back(i + n, j, a[i][j]);
        }
        sort(tmp[i].begin(), tmp[i].end());
    }
    sort(es + 1, es + m + 1);
    rep(i, 1, n)
        fa[i] = i;
    rep(i, 1, m)
    {
        int u = es[i].u, v = es[i].v;
        ll w = es[i].w;
        int fx = f(u), fy = f(v);
        if(fx != fy)
        {
            fa[fx] = fy;
            id[++ec] = i;
        }
        if(ec == n - 1)
            break;
    }//return 0;
    rep(S, 0, (1 << k) - 1)
    {
        ll sum = 0;
        int cnt = 0, tt = ec = 0;
        int x = k;
        rep(j, 1, k) if((S >> (j - 1)) & 1)
        {
            sum += c[j];
            ++cnt;
            x = min(x, j);
        }
        if(!S) rep(i, 1, n - 1)
            et[S].emplace_back(es[id[i]]);
        else
        {
            int y = S ^ (1 << (x - 1));
            et[S].resize(n * cnt + n - 1);//assert(et[y].size()+tmp[x].size()==et[S].size());
            merge(et[y].begin(), et[y].end(), tmp[x].begin(), tmp[x].end(), et[S].begin());
        }
        rep(i, 1, n + k)
            fa[i] = i;
        rep(i, 0, et[S].size() - 1)
        {
            int u = et[S][i].u, v = et[S][i].v;
            ll w = et[S][i].w;
            int fx = f(u), fy = f(v);
            if(fx != fy)
            {
                fa[fx] = fy;
                ++ec;
                sum += w;
            }
            if(ec == n + cnt - 1)
                break;
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}
//freopen
