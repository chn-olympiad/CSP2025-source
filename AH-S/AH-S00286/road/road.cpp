#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define N 10005
#define K 15
using namespace std;
int n,m,k,ans;
int a[1005];
int f[1005][1005];
struct node{
    int next,w;
};
vector<node> g[N];
int dis[N];
bool vis[N];
void dft_prim(int st){
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(1){
        int u=-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&(u==-1||dis[u]>dis[i])) u=i;
        }
        if(u==-1) break;
        vis[u]=1;
        ans+=dis[u];
        for(int i=0;i<g[u].size();i++){
            node e=g[u][i];
            dis[e.next]=min(dis[e.next],e.w);
        }
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0||n>1000){
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dft_prim(1);
    }else{
        for(int i=1,u,v,w;i<=m;i++){
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i=1,t,w;i<=k;i++){
            cin>>t;
            for(int y=1;y<=n;y++){
                cin>>a[y];
                //g[t].push_back({y,w});
                //g[y].push_back({t,w});
            }
            for(int o=1;o<=n;o++){
                for(int p=1;p<=n;p++){
                    w=a[o]+a[p]+t;
                    bool f=0;
                    for(int j=0;j<g[o].size();j++){
                        if(g[o][i].next==p){
                            g[o][i].w=min(g[p][i].w,w);
                            g[p][i].w=min(g[o][i].w,w);
                            f=1;
                        }
                    }
                    if(f==0){
                        g[o].push_back({p,w});
                        g[p].push_back({o,w});
                    }
                }
            }
        }
        dft_prim(1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
