// B
// expect pts = 16
// expect diff = black

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
typedef long long LL;

int n, m, k;
struct Edge{
    LL a, b, w;
}edges[maxn];
int fa[maxn], idx;

int find(int x)
{
    if(x != fa[x])
        return fa[x] = find(fa[x]);
    return fa[x];
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i ++)
        fa[i] = i;

    for(int i = 1 ; i <= m ; i ++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    sort(edges+1, edges+1+m, cmp);

    //for(int i = 1 ; i <= idx ; i ++)
        //cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w << endl;

    LL cnt = n, res = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a != b)
        {
            fa[a] = b;
            //if(a <= n || b <= n)
            cnt --;
            if(cnt == 0)
                break;
            res += w;
        }
    }
    cout << res << endl;

}

