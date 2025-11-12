#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int maxm = 100005;
const int maxk = 10;
struct Edge {
    int to,nxt,w;
    bool isurbane = true;
}edge[maxn];
struct Edge2 {
    int to,nxt,w;
    bool isurbane = false;
}edge2[maxn];
int head[maxn << 1],head2[maxn << 1],dist[maxm][maxm] = {0};
void addEdge(int u,int v,int w) {
    int cnt = 0;
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
void addEdge2(int u,int v,int w) {
    int cnt = 0;
    edge2[cnt].to = v;
    edge2[cnt].nxt = head2[u];
    head2[u] = cnt++;
}
int main()  {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,c;
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)    {
        int u,v,w;
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int i = 1; i <= k; i++)    {
        cin>>c;
        int a[n];
        for (int j = 1; j <= n; j++)    {
            int w;
            cin>>w;
            addEdge(i,j,w);
            addEdge(j,i,w);
            dist[i][j] = w;
            dist[j][i] = w;
        }
    }
    for (int i = 1; i <= n; i++)    {
        for (int j = 1; j <= n && j != i; j++)  {
            for (int k = 1; k <= n && k != i && k != j; k++)    {
                if (dist[i][k] + dist[k][j] < dist[i][j])   {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
        for (int i = 1; i <= n; i++)    {
        for (int j = 1; j <= n && j != i; j++)  {
            for (int k = 1; k <= n && k != i && k != j; k++)    {
                if (dist[i][k] + dist[k][j] + c < dist[i][j])   {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    //cout<<dist[1][n]<<endl;
    cout<<0<<endl;
    return 0;
}
