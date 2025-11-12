#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge{
    int u, v, cost;
}ed_old[1100010], ed[1100010];

int n, m, k;
int cun_cost[11];
int cun_fee[11][10010];
int fa[10100];

inline int read()
{
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x;
}

int query(int s){
    if (fa[s] == s){
        return s;
    }
    else{
        return fa[s] = query(fa[s]);
    }
}

void mge(int a, int b){
    fa[a] = b;
}

void solve_LST()
{
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    sort(ed + 1, ed + 1 + m, [](const edge& a, const edge& b){
         return a.cost < b.cost;
    });
    int ans = 0;
    for (int i = 1; i <= m; i++){
        int qa = query(ed[i].u);
        int qb = query(ed[i].v);
        if (qa != qb){
            ans += ed[i].cost;
            mge(qa, qb);
        }
    }
    printf("%lld\n", ans);
}

void solve_A()
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++){
            m++;
            ed[m].u = n + i;
            ed[m].v = j;
            ed[m].cost = cun_fee[i][j];
        }
    }
    n += k;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    sort(ed + 1, ed + 1 + m, [](const edge& a, const edge& b){
         return a.cost < b.cost;
    });
    int ans = 0;
    for (int i = 1; i <= m; i++){
        int qa = query(ed[i].u);
        int qb = query(ed[i].v);
        if (qa != qb){
            ans += ed[i].cost;
            mge(qa, qb);
        }
    }
    printf("%lld\n", ans);
}

int solve_(int p)
{
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if ((1 << (i - 1)) & p){
            cnt++;
            for (int j = 1; j <= n; j++){
                m++;
                ed[m].u = n + cnt;
                ed[m].v = j;
                ed[m].cost = cun_fee[i][j];
            }
            ans += cun_cost[i];
        }
    }
    n += cnt;
    for (int i = 1; i <= n; i++){
        fa[i] = i;
    }
    sort(ed + 1, ed + 1 + m, [](const edge& a, const edge& b){
         return a.cost < b.cost;
    });
    for (int i = 1; i <= m; i++){
        int qa = query(ed[i].u);
        int qb = query(ed[i].v);
        if (qa != qb){
            ans += ed[i].cost;
            mge(qa, qb);
        }
    }
    return ans;
}

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        ed_old[i].u = ed[i].u;
        ed_old[i].v = ed[i].v;
        ed_old[i].cost = ed[i].cost;
    }
    int n1 = n, m1 = m;
    int ans = 0;
    for (int i = 0; i < (1 << k); i++)
    {
        if (i == 0)
        {
            ans = solve_(i);
        }
        else
        {
            ans = min(ans, solve_(i));
        }
        n = n1, m = m1;
        for (int i = 1; i <= m; i++)
        {
            ed[i].u = ed_old[i].u;
            ed[i].v = ed_old[i].v;
            ed[i].cost = ed_old[i].cost;
        }
    }
    cout << ans;
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        ed[i].u = read(), ed[i].v = read(), ed[i].cost = read();
    }
    bool A_flag = true;
    for (int i = 1; i <= k; i++)
    {
        cun_cost[i] = read();
        for (int j = 1; j <= n; j++){
            cun_fee[i][j] = read();
        }
        if (cun_cost[i] != 0) {
            A_flag = false;
        }
    }
    if (k <= 0){
        solve_LST();
    }
    else if (A_flag == true){
        solve_A();
    }
    else {
        //神奇二进制枚举
        solve();
    }
    return 0;
}
