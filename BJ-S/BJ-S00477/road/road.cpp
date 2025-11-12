#include<bits/stdc++.h>
using namespace std;
struct node{
    int id;
    int dis;
};
bool operator < (const node& a,const node& b){
    return a.dis>b.dis;
}
int n,m,k;
int head[10005],nxt[2500005],to[2500005],wei[2500005],tot;
long long ans;
bool vis[10005];
void add_edge(int u,int v,int w){
    tot++;
    to[tot]=v;
    wei[tot]=w;
    nxt[tot]=head[u];
    head[u]=tot;
}
void prim(){
    priority_queue<node> q;
    q.push({1,0});
    while(!q.empty()){
        auto ato=q.top();
        q.pop();
        int u=ato.id;
        if(vis[u])continue;
        vis[u]=1;
        ans+=ato.dis;
        for(int i=head[u];i;i=nxt[i]){
            int v=to[i],w=wei[i];
            q.push({v,w});
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    for(int i=1;i<=k;i++){
        int cj;
        cin>>cj;
        int wj[10005],atc;
        for(int j=1;j<=n;j++){
            cin>>wj[j];
            if(wj[j]==0)atc=j;
        }
        for(int j=1;j<=n;j++){
            add_edge(atc,j,wj[j]);
            add_edge(j,atc,wj[j]);
        }
    }
    prim();
    cout<<ans;
}
