#include<bits/stdc++.h>
#define N 10005
#define M 1000005
#define K 11
using namespace std;
using ll=long long;
struct EDGE{
    int u,v,w;
    EDGE(int U,int V,int W){
        u=U,v=V,w=W;
    }
    bool operator< (EDGE ee) const{
        return w<ee.w;
    }
};
vector<EDGE> edge,edge_modi;
int n,m,k;
bool included[N+20];
int urbaniseCost[K];
int pathCost[K][N+20];
ll kruskal(int cnt){
    for(int i=0;i<=cnt;i++) included[i]=false;
    edge_modi=edge;
    sort(edge_modi.begin(),edge_modi.end());

    //for(EDGE e:edge_modi)printf("%d %d %d\n",e.u,e.v,e.w);printf("========\n");

    int inserted=0;
    ll ret=0;
    for(EDGE &e:edge_modi){
        if((!included[e.u])||(!included[e.v])){
            ret+=e.w;
            inserted+=int(!included[e.u])+int(!included[e.v]);
            included[e.u]=true;
            included[e.v]=true;
        }
        if(inserted==cnt) break;
    }
    return ret;
}
ll ans=0x7f7f7f7f7f7f7f7f;
void solve(int id,ll cost,int new_N){

    if(id==k+1){
        ans=min(ans,cost+kruskal(new_N));


        return;


    }

    for(int i=1;i<=n;i++){
        edge.push_back(EDGE(n+id,i,pathCost[id][i]));//new id:n+id
    }
    solve(id+1,cost+urbaniseCost[id],new_N+1);

    edge.erase(edge.end()-n,edge.end());
    solve(id+1,cost,new_N);

}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge.push_back(EDGE(u,v,w));
        //edge.push_back(EDGE(v,u,w));
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&urbaniseCost[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&pathCost[i][j]);
        }
    }
    solve(1,0,n);
    printf("%lld",ans);
    return 0;
}
