#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
};
bool kEquals0 = true,enableA = true;
int n,m,k,u,v,w;
long long ans = 0ll;
bool vis[10005] = {false};
vector<node> ve[10005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    if(k) kEquals0 = false;
    for(int i = 1;i <= n;i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v,w});
        ve[v].push_back({u,w});
    }
    if(kEquals0)
    {
        vis[1] = true;
        for(int i = 2;i <= n;i++)
        {
            int temp = ve[i].size(),dis1 = 0x3f3f3f3f;
            for(int j = 0;j < temp;j++)
            {
                if(vis[ve[i][j].v])
                {
                    vis[i] = true;
                    dis1 = min(dis1,ve[i][j].w);
                }
            }
            if(vis[i]) ans += dis1;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
}
