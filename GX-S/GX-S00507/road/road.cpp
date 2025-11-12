#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,k,a[N][N],c[N],ans=INT_MAX,d[N],v[N];
vector<pair<int,int> >g[N];
int bfs(int s){
    priority_queue<pair<int,int> >q;
    q.push({0,s});
    for(int i=1;i<=n;i++) d[i]=INT_MAX;
    d[1]=0;
    memset(v,0,sizeof(v));
    while(!q.empty()){
        pair<int,int>t=q.top();
        q.pop();
        int u=t.second;
        if(v[u]==1) continue;
        v[u]=1;
        for(int i=0;i<g[u].size();i++){
            int w=g[u][i].first,vv=g[u][i].second;
            if(d[u]+vv<d[w]){
                d[w]=d[u]+vv;
                q.push({-d[w],w});
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=d[i];
    }
    return sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        g[x].push_back({y,v});
        g[y].push_back({x,v});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<bfs(1);
    return 0;
}
