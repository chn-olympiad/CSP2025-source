#include<bits/stdc++.h>
using namespace std;
const int N = 3000010;
int n, m, k;
struct Edge
{
    int a, b, w;
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edge[N];
int tt = m;
int p[N];
int X[N][20];
int sel[20];
int c[20];
long long int ans;
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
bool state[20];
void kruscal(int O)
{
    int cnt = 0;
    sort(edge + 1, edge + 1 + tt);
    for(int i = 1; i <= tt; i ++ )
    {
        int _a = edge[i].a, _b = edge[i].b, _w = edge[i].w;
        int pa = find(_a), pb = find(_b);
        if(cnt == O - 1) break;
        if(pa != pb)
        {
            if(_a > m && sel[_a - m] == _b) state[_a - m] = true;
            p[pa] = pb;
            ans += _w;
            cnt ++ ;
        }
    }
}
int _a[N], _b[N], _w[N];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= 3000000; i ++) p[i] = i;
    for(int i = 1; i <= m; i ++)
    {
        cin >> _a[i] >> _b[i] >> _w[i];
        edge[i].a = _a[i];
        edge[i].b = _b[i];
        edge[i].w = _w[i];
    }
    tt = m;
    for(int i = 1; i <= k; i ++ )
    {
        cin >> c[i];
        for(int j = 1; j <= n; j ++) cin >> X[j][i];
        long long int minn = X[1][i], id = 1;
        for(int j = 1; j <= n; j ++ )
        {
            if(X[j][i] < minn)
            {
                minn = X[j][i];
                id = j;
            }
        }
        sel[i] = id;
        X[id][i] += c[i];
        for(int j = 1; j <= n; j ++)
        {
            tt ++ ;
            edge[tt].a = m + i;
            edge[tt].b = j;
            edge[tt].w = X[j][i];
        }
    }
    kruscal(n + k);
    memset(edge, 0, sizeof edge);
    for(int i = 1; i <= m; i ++) 
    {
        edge[i].a = _a[i];
        edge[i].b = _b[i];
        edge[i].w = _w[i];
    }
    ans = 0;
    tt = m;
    for(int i = 1; i <= 3000000; i ++ ) p[i] = i;
    int P0 = 0;
    for(int i = 1; i <= k; i ++) 
        if(state[i] == true)
        {
            P0 ++ ;
            ans += c[i];
            X[sel[i]][i] -= c[i];
            for(int j = 1; j <= n; j ++)
            {
                tt ++ ;
                edge[tt].a = m + i;
                edge[tt].b = j;
                edge[tt].w = X[j][i];
            }
        }
    kruscal(n + P0);
    cout << ans << endl;
    return 0;
}