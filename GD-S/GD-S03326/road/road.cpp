#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int u, v;
    long long w;
    bool operator<(const Edge other) const
    {
        return w < other.w;
    }
};
int n, m, k, last_uncheck = 1;
int fa[10100];
Edge edge1[1000001];
vector<Edge> edge2[11];
long long c[100];
bool been_kill[100], end1, end2;
int find(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}
void merge(int a, int b)
{
    if (find(a) != find(b))
    {
        fa[fa[a]] = fa[b];
    }
}
void kill_node(int x)
{
    for (auto it = edge2[x].begin(); it != edge2[x].end(); it++)
    {
        it->w -= c[x];
    }
    been_kill[x] = true;
}
auto get_smallest_it()
{
    auto it = edge2[1].begin();
    for (int i = 2; i <= k; i++)
    {
        if (edge2[i].size() && edge2[i][0].w < it->w)
        {
            it = edge2[i].begin();
        }
    }
    if (it == edge2[1].end())
    {
        end2 = true;
    }
    return it;
}
template <class T>
inline void read(T &x)
{
    char c = getchar();
    int t = 1;
    x = 0;
    while (c < '0' || '9' < c)
    {
        if (c == '-')
        {
            t = -1;
        }
        c = getchar();
    }
    while ('0' <= c && c <= '9')
    {
        x *= 10;
        x += c - '0';
        c = getchar();
    }
    x *= t;
    return;
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n), read(m), read(k);
    for (int i = 1; i <= n + k; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        read(u), read(v), read(w);
        edge1[i] = {u, v, w};
    }
    for (int i = 1; i <= k; i++)
    {
        read(c[i]);
        for (int j = 1; j <= n; j++)
        {
            int u;
            read(u);
            edge2[i].push_back({j, i, u + c[i]});
        }
        sort(edge2[i].begin(), edge2[i].end());
    }
    sort(edge1 + 1, edge1 + 1 + n);
    int it1 = 1;
    auto it2 = get_smallest_it();
    long long cost = 0;
    while (true)
    {
        if (it1 <= m && edge1[it1].w <= it2->w)
        {
            if (find(edge1[it1].u) != find(edge1[it1].v))
            {
                cost += edge1[it1].w;
                merge(edge1[it1].u, edge1[it1].v);
            }
            while (it1 <= m && find(edge1[it1].u) == find(edge1[it1].v))
            {
                it1++;
            }
        }
        else
        {
            if (end2 == false)
            {
                if (find(it2->u) != find(it2->v + n + 1))
                {
                    cost += it2->w;
                    if (been_kill[it2->v] == false)
                    {
                        kill_node(it2->v);
                    }
                    merge(it2->v + n + 1, it2->u);
                }
                while (find(it2->u) == find(it2->v + n + 1))
                {
                    edge2[it2->v].erase(it2);
                    it2 = get_smallest_it();
                }
            }
        }
        bool flag = true;
        for (int i = last_uncheck; i <= n; i++)
        {
            if (find(i) != find(1))
            {
                flag = false;
                break;
            }
            else
            {
                last_uncheck = i;
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << cost;
}