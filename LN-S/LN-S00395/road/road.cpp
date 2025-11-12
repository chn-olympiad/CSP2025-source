#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v,w;
    bool operator<(const edge& ed)const{
        return w>ed.w;
    }
};
struct dot{
    int id;
    vector<edge> vec;
}dt[10015];
bool vis[10015];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dt[u].vec.push_back({v,w});
        dt[v].vec.push_back({u,w});
    }
    int c[k+1],a[k+1][n+1];
    long long ans=0,cnt=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        ans+=c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            dt[n+i].vec.push_back({j,a[i][j]});
            dt[j].vec.push_back({n+i,a[i][j]});
        }
    }
    priority_queue<edge> pq;
    for(int i=0;i<int(dt[1].vec.size());i++){
        pq.push(dt[1].vec[i]);
    }
    vis[1]=true;
    while(!pq.empty()){
        edge cur=pq.top();
        pq.pop();
        if(vis[cur.v]) continue;
        if(cnt==n+k-1) break;
        vis[cur.v]=true;
        cnt++;
        ans+=cur.w;
        for(int i=0;i<int(dt[cur.v].vec.size());i++){
            pq.push(dt[cur.v].vec[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
