#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mid ((l+r)>>1)
#define ls (p<<1)
#define rs (ls^1)
#define int long long

using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, K = 15, INF = 1e18;
int n, m, k, l, c[K], a[K][N], res, ans, fa[N], t[N<<2];
bool b[K], cnt[N];
struct edge{
    int u, v, w;
}p[M];
struct node{
    int id, val;
};
vector <node> e[N];

inline bool cmp_w(edge x, edge y){return x.w < y.w;}

inline int query_id(int p, int l, int r)
{
    if(l == r)  return l;
    return (t[ls] < t[rs]) ? query_id(ls, l, mid) : query_id(rs, mid+1, r);
}

void update(int p, int l, int r, int x, int val)
{
    if(l == r)
    {
        t[p] = min(t[p], val);
        return ;
    }
    if(x <= mid)    update(ls, l, mid, x, val);
    else    update(rs, mid+1, r, x, val);
    t[p] = min(t[ls], t[rs]);
}

void dele(int p, int l, int r, int x, int val)
{
    if(l == r)
    {
        t[p] = val;
        return ;
    }
    if(x <= mid)    dele(ls, l, mid, x, val);
    else    dele(rs, mid+1, r, x, val);
    t[p] = min(t[ls], t[rs]);
}

void build(int p, int l, int r)
{
    t[p] = INF;
    if(l == r)  return ;
    build(ls, l, mid), build(rs, mid+1, r);
}

void solve(int s)
{
    //printf("solve(%lld)\n", s);
    res = l = 0;
    for(register int i = 1;i <= k;i++)   b[i] = false;
    for(register int i = 1;i <= k;i++)
        if(s & (1 << (i-1)))
            res += c[i], b[i] = true, l++;
    if(res >= ans)  return ;
    for(register int i = 1;i <= n+k;i++)   cnt[i] = false;
    build(1, 1, n+k), cnt[1] = true;
    for(register int i = 0;i < e[1].size();i++)
        update(1, 1, n+k, e[1][i].id, e[1][i].val);
    for(register int i = 1;i <= k;i++)
        if(b[i])
            update(1, 1, n+k, i+n, a[i][1]);
    //printf("begin:%lld\n", res);
    for(register int i = 2;i <= n+l;i++)
    {
        register int x = query_id(1, 1, n+k);
        res += t[1], cnt[x] = true;
        if(res >= ans)   return ;
        //printf("%lld \n", t[1]);
        dele(1, 1, n+k, x, INF);
        //printf("%lld %lld\n", x, res);
        if(x <= n)
        {
            for(register int j = 0;j < e[x].size();j++)
                if(!cnt[e[x][j].id])
                    update(1, 1, n+k, e[x][j].id, e[x][j].val);
            for(register int j = 1;j <= k;j++)
                if(b[j] && !cnt[n+j])
                    update(1, 1, n+k, j+n, a[j][x]);
        }
        else
        {
            for(register int j = 1;j <= n;j++)
                if(!cnt[j])
                    update(1, 1, n+k, j, a[x-n][j]);
        }
    }
    //printf("%lld %lld\n", s, res);
    ans = res;
}

inline int query(int x){return fa[x] == x ? x : fa[x] = query(fa[x]);}

void tree()
{
    sort(p + 1, p + m + 1, cmp_w);
    for(register int i = 1;i <= n;i++)   fa[i] = i;
    for(register int i = 1;i <= m;i++)
    {
        register int fau = query(p[i].u), fav = query(p[i].v);
        if(fau == fav)  continue;
        //printf("tree:%lld %lld\n", p[i].u, p[i].v);
        ans += p[i].w, fa[fau] = fav;
        e[p[i].u].push_back({p[i].v, p[i].w});
        e[p[i].v].push_back({p[i].u, p[i].w});
    }
    //printf("%lld\n", ans);
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld %lld %lld", &n, &m, &k);
    for(register int i = 1;i <= m;i++)
        scanf("%lld %lld %lld", &p[i].u, &p[i].v, &p[i].w);
    tree();
    for(register int i = 1;i <= k;i++)
    {
        scanf("%lld", &c[i]);
        //printf("%lld ", c[i]);
        for(register int j = 1;j <= n;j++)
            scanf("%lld", &a[i][j]);
        //for(int j = 1;j <= n;j++)
        //    printf("%lld ", a[i][j]);
        //puts("");
    }
    for(register int i = 1;i < (1 << k);i++)
        solve(i);
    printf("%lld\n", ans);
    return 0;
}
