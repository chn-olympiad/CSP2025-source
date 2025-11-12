//GZ-S00372 遵义市第四中学 翁铭卓
#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e4 + 10, M = 1e6 + 10;

int n, m, k, idx = 0;
int fa[N], sz[N];
struct Edge
{

    int a, b, w;

    bool operator <(const Edge& t)const
    {
        return w < t.w;
    }
}e[M];

int fd(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = fd(fa[x]);
}

void mg(int a, int b)
{
    a = fd(a), b = fd(b);
    if (sz[a] > sz[b])
        swap(a, b);

    fa[b] = a;
    sz[a] += sz[b];

    return;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1, a, b, w; i <= m; i ++ )
        scanf("%d%d%d", &a, &b, &w), e[ ++ idx] = {a, b, w};

    for (int i = 1; i <= n; i ++ )
        fa[i] = i, sz[i] = 1;

    sort(e + 1, e + 1 + m);

    ll sum = 0;
    for (int i = 1, a, b, w; i <= m; i ++ )
    {
        a = e[i].a, b = e[i].b, w = e[i].w;
        if (fd(a) != fd(b))
        {
            sum += w;
            mg(a, b);
        }
    }

    printf("%lld", sum);

    return 0;
}
