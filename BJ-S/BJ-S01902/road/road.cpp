#include <bits/stdc++.h>
using namespace std;

long long n, m, k, x2, y2, z2, cnt, ans, c[10005];

struct D
{
    long long fa[20005];
    D (long long n)
    {
        for (long long i = 0; i <= 2 * n; i++)
        {
            fa[i] = i;
        }
    }
    long long f(long long x)
    {
        if (fa[x] == x)
        return x;
        return f(fa[x]);
    }
    void me(long long x, long long y)
    {
        fa[f(x)] = f(y);
    }
};

struct A
{
    long long x, y, z;
};

vector<A> v;

bool cmp(A x, A y)
{
    return x.z < y.z;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for (long long i = 1; i <= m; i++)
    {
        cin >> x2 >> y2 >> z2;
        v.push_back({x2, y2, z2});
    }
    cnt = m;
    for (long long i = 1; i <= k; i++)
    {
        cin >> x2;
        for (long long j = 1; j <= n; j++)
        {
            cin >> c[j];
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (k == j)
                continue;
                v.push_back({j, k, c[j] + c[k]});
            }
        }
    }
    sort (v.begin(), v.end(), cmp);
    D b(n);
    for (long long i = 0; i < cnt; i++)
    {
        if (b.f(v[i].x) != b.f(v[i].y))
        {
            b.me(v[i].x, v[i].y);
            ans += v[i].z;
        }
    }
    cout << ans;
    return 0;
}