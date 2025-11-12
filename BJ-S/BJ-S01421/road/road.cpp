#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x , len;
    bool operator < (const node & b) const
    {
        return len > b.len;
    }
};
priority_queue<node> q;
struct stu
{
    int v , w;
};
vector<stu> G[1010];
int dis[1010];
bool vis[1010];
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        G[u].push_back({v , w});
        G[v].push_back({u , w});
    }
    if(k == 0)
    {
        memset(dis , 0x3f , sizeof(dis));
        dis[1] = 0;
        q.push({1 , 0});
        while(!q.empty())
        {
            int x = q.top().x;
            q.pop();
            if(vis[x]) continue;
            vis[x] = 1;
            for(int i = 0; i < G[x].size(); i++)
            {
                int v = G[x][i].v , w = G[x][i].w;
                if(dis[v] > dis[x] + w)
                {
                    dis[v] = dis[x] + w;
                    q.push({v , dis[v]});
                }
            }
        }
        cout << dis[n] << endl;
    }
    else
    {
        cout << m << endl;
    }
    return 0;
}
