#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1010],c[15]/*,cnc[1010][1010],ogn[1010][1010]*/;
long long ans,e[1010][1010];
bool vis[1010];
struct node{
    int u,v;
};
bool operator<(node x,node y){
    return e[x.u][x.v]>e[y.u][y.v];
}
priority_queue<node> pq;
int solve(){
    for(int i=1;i<n;i++){
        int x=pq.top().u,y=pq.top().v;
        pq.pop();
        while(vis[x] && vis[y]){
            x=pq.top().u;
            y=pq.top().v;
            pq.pop();
        }
        vis[x]=1;
        vis[y]=1;
        ans+=e[x][y];
        for(int j=1;j<=n;j++){
            /*for(int vlg=1;vlg<=k;vlg++){
                if(vis)
                e[u][v]=min(e[u][v])
            }*/
            if(!vis[j]){
                pq.push({x,j});
                pq.push({y,j});
            }
        }
    }
    return ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            e[i][j]=1e18;
            e[j][i]=1e18;
            /*ogn[i][j]=1e18;*/
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u][v]=min(e[u][v],1ll*w);
        e[v][u]=e[u][v];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        for(int u=1;u<n;u++){
            for(int v=u+1;v<=n;v++){
                /*if(e[u][v]>a[u]+a[v]){
                    e[u][v]=a[u]+a[v];
                    cnc[u][v]=i;
                }*/
                e[u][v]=min(e[u][v],1ll*c[i]+a[u]+a[v]);
                e[v][u]=e[u][v];
            }
        }
    }
    int x=0,y=0;
    e[0][0]=1e18;
    for(int u=1;u<n;u++){
        for(int v=u+1;v<=n;v++){
            //cout<<e[u][v]<<" ";
            if(e[x][y]>e[u][v]){
                x=u;
                y=v;
            }
        }
        //cout<<'\n';
    }
    pq.push({x,y});
    cout<<solve();
    return 0;
}
//g++ road.cpp -o b -O2 -std=c++14 -static -Wall -Wextra