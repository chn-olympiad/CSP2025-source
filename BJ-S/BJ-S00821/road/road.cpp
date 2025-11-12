#include <bits/stdc++.h>
using namespace std;


struct st
{
    int u , v , w;
};
vector<st> edge;
int fa[1005] , n , m , k , a[15][1005];
int mp[1005][1005];
int Find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = Find(fa[x]);
}
void Merge(int x , int y)
{
    int fx = Find(x);
    int fy = Find(y);
    fa[fx] = fy;
}
bool cmp(st x , st y)
{
    return x.w < y.w;
}
int kruskal()
{
    int cost = 0;
    sort(edge.begin() , edge.end() , cmp);
    for(int i = 0; i < edge.size(); i++)
    {
        st x = edge[i];
        if(Find(x.u) != Find(x.v))
        {
            Merge(x.u , x.v);
            cost += x.w;
        }
    }
    return cost;
}
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i <= 10000; i++) fa[i] = i;
    memset(mp , 0x3f , sizeof mp);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int x , y , z;
        cin >> x >> y >> z;
        edge.push_back({x , y , z});
        mp[x][y] = z;
        mp[y][x] = z;
    }
    for(int i = 1; i <= k; i++)
    {
        int x;cin >> x;
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                mp[j][k] = min(mp[j][k] , a[i][j] + a[i][k]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(mp[i][j] != 0x3f3f3f3f)
            {
                edge.push_back({i , j , mp[i][j]});
            }
        }
    cout << kruskal() << endl;
    return 0;
}
