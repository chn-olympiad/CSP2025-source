#include<bits/stdc++.h>

using namespace std;
const int N=1E5;
int n,m,k,cnt,ans;
int head[N],dis[N];
struct Node{
    int v,w;
    bool operator < (const Node &x) const{
        return w>x.w;
    }
};
struct E{
    int next,to,w;
}e[10000005];
void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
bool vis[N];
void djs(int s){
    memset(dis,0x3f,sizeof dis);
    priority_queue<Node> pq;
    pq.push(Node{s,0});
    dis[s]=0;
    while(!pq.empty()){
        Node temp=pq.top();
        pq.pop();
        vis[temp.v]=true;
        for(int i=head[temp.v];i;i=e[i].next){
            if(!vis[e[i].to]&&dis[temp.v]+e[i].w<dis[e[i].to])
            pq.push(Node{e[i].to,dis[e[i].to]=dis[temp.v]+e[i].w});
        }
    }

}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;

        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1,c;i<=k;i++){
        cin>>c;
        for(int j=1,w;j<=n;j++){
            cin>>w;
            add(n+i,j,w+c);
            add(j,n+i,w+c);
        }
    }

    djs(1);
    memset(vis,0,sizeof(vis));
    priority_queue<Node> pq;
    pq.push(Node{1,0});
    dis[1]=0;
    while(!pq.empty()){
        Node temp=pq.top();
        pq.pop();
        vis[temp.v]=true;
        for(int i=head[temp.v];i;i=e[i].next){
            if(dis[temp.v]+e[i].w==dis[e[i].to]){
                ans+=e[i].w;
            }

        }
    }
    cout<<ans;

}
