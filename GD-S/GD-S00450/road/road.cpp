#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define int long long

const int MAXN = 2e5;

int n, m, k;

struct Node
{
    int u, v, dis;
};

struct cmp
{
    bool operator()(Node &a, Node &b)
    {
        return a.dis > b.dis;
    }
};

int fa[MAXN];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

vector<Node> edges;

int vis[100];

vector<int> a[11];
int c[11];

int ans = 1e18;

int solve(vector<int> &vec)
{
    priority_queue<Node, vector<Node>, cmp> que;

    for (auto &i : edges)
        que.push(i); // 原图

    for (auto &i : vec)
    {
        for (int j = 1; j <= n; j++)
            que.push({i + n, j, a[i][j]});
    }

    for (int i = 1; i <= n + k; i++)
        fa[i] = i;

    int cnt = 0;
    int res = 0;

    while (!que.empty() && cnt < n + k)
    {
        Node now = que.top();
        que.pop();
        int u = now.u, v = now.v, w = now.dis;
        if (find(u) == find(v))
            continue;
        fa[find(u)] = find(v);
        cnt++;
        res += w;
        if (res > ans)
            return ans;
    }
    return res;
}

void dfs(int x)
{
    if (x > k)
    {
        int res = 0;
        vector<int> vec;
        for (int i = 1; i <= k; i++)
            if (vis[i])
                res += c[i], vec.push_back(i);

        res += solve(vec);

        ans = min(ans, res);

        return;
    }
    vis[x] = 1;
    dfs(x + 1);
    vis[x] = 0;
    dfs(x + 1);
}

int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    n = read();
    m = read();
    k = read();
    priority_queue<Node, vector<Node>, cmp> que;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), w = read();
        que.push({u, v, w});
    }

    for (int i = 1; i <= k; i++)
    {
        c[i] = read();
        a[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    }

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    int cnt = 0;

    while (!que.empty() && cnt < n)
    {
        Node now = que.top();
        que.pop();
        int u = now.u, v = now.v, w = now.dis;
        if (find(u) == find(v))
            continue;
        fa[find(u)] = find(v);
        edges.push_back(now);
        cnt++;
    }

    dfs(1);

    cout << ans << endl;
}