#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define maxm 1000010
#define maxk 12
#define inf 4400000001
struct Edge{
    int u,v;
    long long w;
};
vector<Edge> edg[maxn];
int n,m,k;
int c[maxk];
long long a[maxk][maxn];
bool vis[maxn];
long long ans;
map<pair<int,int>,long long> dis;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void kruskal(){
    memset(vis,0,sizeof(vis));
    q.push(make_pair(0,1));
    vis[1] = true;
    while(!q.empty()){
        int u = q.top().second;
        long long w = q.top().first;
        q.pop();
        ans += w;
        //cout << 666 << endl;
        for(int i = 0;i < edg[u].size();i++){
            int v = edg[u][i].v;
            if(vis[v]){
                continue;
            }
            vis[v] = true;
            q.push(make_pair(edg[u][i].w,v));
        }
    }
}
int main(){
    //freopen("road2.in","r",stdin);
    //freopen("road2.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            dis[make_pair(i,j)] = inf;
        }
    }
    for(int i = 1;i <= m;i++){
        int x,y;
        long long val;
        cin >> x >> y >> val;
        if(x > y){
            swap(x,y);
        }
        dis[make_pair(x,y)] = min(dis[make_pair(x,y)],val);
    }
    for(int j = 1;j <= k;j++){
        cin >> c[j];
        for(int i = 1;i <= n;i++){
            cin >> a[j][i];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            long long w = inf;
            for(int s = 1;s <= k;s++){
                w = min(w,a[s][i] + a[s][j] + c[s]);
            }
            dis[make_pair(i,j)] = min(dis[make_pair(i,j)],w);
            edg[i].push_back((Edge){i,j,dis[make_pair(i,j)]});
            edg[j].push_back((Edge){j,i,dis[make_pair(i,j)]});
        }
    }
    kruskal();
    cout << ans << endl;
    return 0;
}
