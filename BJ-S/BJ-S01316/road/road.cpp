#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
struct edge{
    int v,w;
};
struct ds{
    int v;
    int dis;
    int fr;
    int frw;
};
bool operator <(ds a,ds b){
    return a.frw>b.frw;
}
vector<edge> e[N];
priority_queue<ds> q;
int dis[N];
int a[20][N];
bool vis[N];
int vs[20];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});

    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++) cin>>a[i][j];
        for(int j=1;j<=n;j++){
            e[j].push_back({n+i,a[i][j]+a[i][0]});
            e[n+i].push_back({j,a[i][j]});
        }
    }
//    for(int i=1;i<=n+k;i++){
//        sort(e[i].begin(),e[i].end(),[](edge a,edge b){
//            return a.w<b.w;
//        });
//    }
    int cnt=0;
    int ans=0;
    q.push({1,0,0,0});
    while(cnt<n){
        ds p=q.top();
        q.pop();
        if(vis[p.v]) continue;
        if(dis[p.v]<p.dis) continue;
        dis[p.v]=p.dis;
        ans+=p.frw;
        if(p.v<=n) cnt++;
        vis[p.v]=1;
        if(p.v>n && p.fr<=n){
            vs[p.v-n]=p.fr;
        }
        if(p.fr>n){
            vs[p.fr-n]=0;
        }
        for(edge i:e[p.v]){
            if(dis[i.v]>dis[p.v]+i.w){
                q.push({i.v,dis[p.v]+i.w,p.v,i.w});
            }
        }
    }
    for(int i=1;i<=k;i++){
        if(vs[i]) ans-=a[i][vs[i]]+a[i][0];
    }
    cout<<ans;
    return 0;
}
