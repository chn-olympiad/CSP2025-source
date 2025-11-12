#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e4+10;
const int maxk=1e1+10;
const ll inf=1e12;
bool teshua,jianshe[maxk],liantong[maxk][maxn],tuozhan[maxn][maxn];
int n,m,k,c[maxn],a[maxk][maxn];
ll ans,dis[maxn];
struct Node{
    int v,w;
};
queue<int> que;
vector<Node> e[maxn];
vector<int> g[maxn];
ll bfs(int st,int ed){
    for (int i=1;i<=n;i++)
        dis[i]=inf;
    que.push(st);dis[st]=0;
    while (que.size()){
        int u=que.front();que.pop();
        for (int i=0;i<e[u].size();i++){
            int v=e[u][i].v,w=((tuozhan[u][v]||tuozhan[v][u])?0:e[u][i].w);
            if (dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                que.push(v);
            }
        }
    }
    return dis[ed];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;teshua=true;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    for (int i=1;i<=k;i++){
        cin>>c[i];
        if (c[i]!=0) teshua=false;
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (a[i][j]!=0) teshua=false;
        }
    }
    if (teshua){
        cout << 0 << '\n';
        return 0;
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++){
            if (check(i,j)) continue;
            int minpos=0;
            ll xiangcun=inf;
            for (int mask=1;mask<=k;mask++){
                if (xiangcun>(jianshe[mask]?0:c[mask])+(liantong[mask][i]?0:a[mask][i])+(liantong[mask][j]?0:a[mask][j])){
                    xiangcun=(jianshe[mask]?0:c[mask])+(liantong[mask][i]?0:a[mask][i])+(liantong[mask][j]?0:a[mask][j]);
                    minpos=mask;
                }
            }
            ll tmpans=bfs(i,j);
            if (xiangcun<tmpans){
                jianshe[minpos]=liantong[minpos][i]=liantong[minpos][j]=true;
                ans.push_back(i,j,xiangcun);
            }
            else ans.push_back(i,j,tmpans);
        }
    cout << ans << '\n';
    return 0;
}