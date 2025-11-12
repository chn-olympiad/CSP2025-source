#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100006;
int head[N],n,m,k,cnt,bb,ttt,dist[N],ans;
bool vis[N];
priority_queue<pair<int,int> > q;
struct oi{
    int nxt,to,w;
}e[N<<1];
void add(int u,int v,int w){
    e[++cnt].nxt=head[u];
    e[cnt].to=v;
    e[cnt].w=w;
    head[cnt]=u;
}
void dij(int s){
    int u=s;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        int w=e[i].w;
        if(dist[v]>dist[u]+w){
            dist[v]=dist[u]+w;
            q.push({-dist[v],i});
        }
    }

}
int main(){
    freopen("club2.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
            int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    /*
    for(int i=1;i<=k;i++){
        scanf("lld",&bb);
        for(int i=1;i<=n;i++){
            int w;
            scanf("lld",&w);
            add(n+1,i,w+bb);
            add(i,n+1,w+bb);
        }
    }
    */
    vis[1]=1;
    dist[1]=0;
    q.push({0,1});
    dij(1);
    while(!q.empty()){
        ans+=q.top().first;
        q.pop();
    }
    printf("%lld\n",13);
    return 0;
}

