#include<bits/stdc++.h>
using namespace std;
//                      shi fou jian guo
int f[10015], sz[10015], kf[15], vis[10015];
int fa( int x )
{
    if( f[x] == x )
        return x;
    return f[x] = fa(f[x]);
}
void unio( int x, int y )
{
    int fx = fa(x), fy = fa(y);
    if( fx == fy )
        return;
    if( sz[fx] > sz[fy] )
    {
        sz[fx] += sz[fy];
        f[fy] = fx;
    }
    else
    {
        sz[fy] += sz[fx];
        f[fx] = fy;
    }
    return;
}
struct node
{
    int u, v, w;
};
bool cmp( node a, node b )
{
    return a.w < b.w;
}
node edge[1000020];
vector<int> kc[15];
int main()
{
    freopen( "road.in", "r", stdin );
    freopen( "road.out", "w", stdout );

    int n, m, k, i, j, v, w, u, t;
    cin >> n >> m >> k;
    for( i = 1; i <= n; i++ )
        f[i] = i, sz[i] = 1;
    for( i = 1; i <= m; i++ )
    {
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }
    t = m;
    for( i = 1; i <= k; i++ )
    {
        for( j = 0; j <= n; j++ )
        {
            cin >> w;
            if( j )
                edge[++t] = {n+i, j, w};
        }
    }
    if(k == 0)
    {
        int cnt = 0;
        long long sum =0;
        sort( edge+1, edge+m+1, cmp );
/*        for( i = 1; i <= t; i++ )
        {
            cout << edge[i].u << " " << edge[i].v << " " << edge[i].w <<endl;
        }
        cout << endl;
*/        for( i = 1; i <= t; i++ )
        {
            u = edge[i].u, v = edge[i].v, w = edge[i].w;
            if( fa(u) == fa(v) )
                continue;
            sum += w;
            unio(u, v);
//            if( (u <= n && !vis[u]) || (v <= n && !vis[v]) )
            cnt ++;//= 2-(vis[u]+vis[v]), vis[u] = vis[v] = 1;
            if( cnt == n-1 )
            {
                cout << sum << endl;
                return 0;
            }
        }
    }
//    else
//    {

 //   }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
