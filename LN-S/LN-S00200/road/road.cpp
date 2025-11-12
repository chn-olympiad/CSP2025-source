#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3fll;
class Sets
{
    int n;
    std::vector<int> root;
    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
public:
    Sets(int n) : n(n), root(n)
        { std::iota(root.begin(), root.end(), 0); }
    bool same(int x, int y)
        { return find(x) == find(y); }
    void merge(int x, int y)
    {
        if (same(x, y))
            return;
        if (root[x] > root[y])
            std::swap(x, y);
        root[root[y]] = root[x];
    }
};
struct Edge
{
    int u, v;
    long long w;
    int nxt;
};
long long MST(const std::vector<int> &head,
    const std::vector<Edge> &e)
{
    auto e_cpy = e;
    std::sort(e_cpy.begin(), e_cpy.end(), 
        [](const Edge &a, const Edge &b){ return a.w < b.w; });
    int cnt = 0;
    long long sum = 0;
    Sets con(head.size());
    for (auto &ed : e_cpy)
    {
        if (con.same(ed.u, ed.v))
            continue;
        ++cnt;
        sum += ed.w;
        con.merge(ed.u, ed.v);
        if (cnt == head.size()-1)
            break;
    }
    return sum;
}
void add(int id, int u, int v, long long w,
    std::vector<int> &head,
    std::vector<Edge> &e)
{
    e[id].u = u;
    e[id].v = v;
    e[id].w = w;
    e[id].nxt = head[u];
    head[u] = id;
}
int main()
{
    std::freopen("road.in", "r", stdin);
    std::freopen("road.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 1~4 & 5,6,9,10,13,14,17,18(A) & 7,8 (14*4'=56')
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> head(n+k, -1);
    std::vector<Edge> e(2*m+2*k*n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u; --v;
        add(2*i, u, v, w, head, e);
        add(2*i+1, v, u, w, head, e);
    }
    if (k == 0) // 1~4
    {
        std::cout << MST(head, e) << '\n';
        return 0;
    }
    // 5,6,9,10,13,14,17,18
    bool all0 = true;
    std::vector<int> c(n);
    std::vector<int> ca(k*n);
    for (int i = 0; i < k; ++i)
    {
        std::cin >> c[i];
        all0 &= c[i] == 0;
        bool exist0 = false;
        for (int j = 0; j < n; ++j)
        {
            int a;
            std::cin >> a;
            exist0 |= a == 0;
            ca[i*n+j] = a;
            add(2*m+2*i*n+2*j, n+i, j, a, head, e);
            add(2*m+2*i*n+2*j+1, j, n+i, a, head, e);
        }
        all0 &= exist0;
    }
    if (all0)
    {
        std::cout << MST(head, e) << '\n';
        return 0;
    }
    // 7,8
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < n; ++j)
            e[2*m+2*i*n+2*j].w = e[2*m+2*i*n+2*j+1].w 
                = (j != 0)*inf;
    long long ans = MST(head, e);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
            e[2*m+2*i*n+2*j].w = e[2*m+2*i*n+2*j+1].w 
                = ca[i*n+j];
        long long cst = MST(head, e) + c[i];
        if (cst > ans)
        {
            for (int j = 0; j < n; ++j)
                e[2*m+2*i*n+2*j].w = e[2*m+2*i*n+2*j+1].w 
                    = (j != 0)*inf;
        }
        else
            ans = cst;
    }
    std::cout << ans << '\n';
    return 0;
}