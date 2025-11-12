#include<iostream>
#include<vector>
using namespace std;
typedef struct p{
    int v,w;
} p;
vector<p> a[10000];
int c[11];
int te[11][10001];
bool cmp(p a,p b){return a.w<b.w;}
int ans;
int n,m,k;
int u,v,w;
int dist[10001];
int cost[10001];
bool us[10001];
bool vis[10001];
void prim(){
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dist[i]=100000;
    }
    bool use[k];for(int i=0;i<k;i++)use[i]=false;
    int t=1;
    dist[t]=0;
    for(int j=0;j<n;j++){
        vis[t]=false;
        for(int i=0;i<a[t].size();i++){
            if(vis[a[t][i].v]&&dist[t]+a[t][i].w<dist[a[t][i].v]){
                dist[a[t][i].v]=dist[t]+a[t][i].w;
                cost[a[t][i].v]=a[t][i].w;
            }
        }
        for(int i=1;i<=k;i++){
            for(int o=1;o<=n;o++){
                if(vis[o]&&dist[t]+te[i][t]+te[i][o]+(use[i]?0:c[i])<dist[o]){
                    dist[o]=dist[t]+te[i][t]+te[i][o]+(use[i]?0:c[i]);
                    cost[o]=te[i][t]+te[i][o]+(use[i]?0:c[i]);
                    us[o]=k;
                }
            }
        }
        int nt=0,d=1000000;
        for(int i=1;i<=n;i++){
            if(vis[i]&&dist[i]<d){
                d=dist[i];
                nt=i;
            }
        }
        if(us[nt])use[us[nt]]=1;
        ans+=cost[nt];
        t=nt;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>u>>v>>w;
        a[u].push_back(p{v,w});
        a[v].push_back(p{u,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>te[i][j];
        }
    }
    prim();
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}