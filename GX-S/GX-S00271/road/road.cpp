#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
using namespace std;
const int maxn=114514;
vector<pii>g[1005];
vector<int>path;
int n,m,k;
int u,v,w;
int a[maxn];
int c[11];
int ans=1145141919;
bool visited[maxn];
void bfs()
{
    queue<pii>q;
    set<int>path;
    q.push({1,0});
    while(!q.empty())
    {


    }
}
void solution1()
{
    bfs());
    cout << ans;
}
void solution2()
{
    cout << 0;
    //qwq
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i = 1;i <= k;i++)
    {
        cin >> c[i];
        ans=min(c[i],ans);
        for(int i = 1;i <= m;i++)
        {
            cin >> a[i];
        }
    }
    cout <<ans;
    //solution1();
    //qwq
    return 0;
}
