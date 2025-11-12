#include<iostream>
#include<cstdio>
#include<queue>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

// 17.18 status:
// k=0, MST only, test=uk
// k<=5, cj===0,test-ex=y; complex= O(n^2) U O(m)

// 17.48 status:
// + testpoint4 ex TLE clearly
// + tum above means ex2
// + ex4 >30s
// ex1 pass
// well, ex4 isreal	1m19.579s
// user	1m17.391s
// sys	0m1.069s


#define IFD if(0)
int n,m,k;
bitset<114514> taken;
struct edge{
    int u,v,w;
    bool operator< (const edge &b) const{
        return w<b.w; // edge cost small to big
    }
} edges[2145141];
edge esp[2145141];
edge edgetmp[11][1145141];
int cnt; // of edges
int modcost[15];
int a[15][114514];
long long gans=0x7f7f7f7f7f7f7f7f;
// int head[114514],nexte[1145141];
const int maxn=1e4+5;
int nmp[maxn][maxn]; // ptr to edge[]
vector<int> G[maxn];
inline void add(int u,int v,int w){
    edges[++cnt]={u,v,w};
    /*
    nexte[cnt]=head[u];
    head[u]=cnt;
*/
    nmp[u][v]=nmp[v][u]=cnt;
    G[u].push_back(v);
    //edges[++cnt]={u,w};
    //nexte[cnt]=head[v];
    //head[v]=cnt;
}

int s[1145141];
inline void INIT(int mxid){
    for(int i=0;i<=mxid;++i)s[i]=i;
}
int FIND(int x){
    if(s[x]!=x)s[x]=FIND(s[x]);
    return s[x];
}
inline void MERG(int x,int y){
    x=FIND(x);
    y=FIND(y);
    if(x==y)return;
    s[x]=y;
}
// idk what its name is
long long MnST(){
    for(int i=1;i<=cnt;++i) esp[i]=edges[i];
    sort(esp+1,esp+cnt+1);
    long long ans=0;
    for(int i=1;i<=cnt;++i){
        edge ue=esp[i];
        
        if(FIND(ue.u)!=FIND(ue.v)){
            MERG(ue.u,ue.v);
            ans+=ue.w;
            //IFD printf("Edge %d-->%d w%d ",ue.u,ue.v,ue.w);
            //IFD printf("GET!");
            //IFD printf("\n");
        }
    }
    return ans;
    //printf("%lld\n",ans);
}
long long enable_cost=0;
void DFS(int j){
    if(j>k){ // Time to run MnST()
        INIT(n);
        gans=min(gans,enable_cost+MnST());
        return;
    }
    // IFD printf("DFSing %d city\n",j);
    // run anyway
    DFS(j+1);
    // Apply such nodes now:
    int ecntbeforemod=cnt;
    for(int i=1;i<=cnt;++i)edgetmp[j][i]=edges[i];
    enable_cost+=modcost[j];
    // ======= spA code =======
    INIT(n);
    queue<pair<int,int>> rb_nmp;
    //for(int j=1;j<=k;++j){
        for(int u=1;u<=n;++u){
            for(int v=u+1;v<=n;++v){
                long long w=a[j][u]+a[j][v];
                if(nmp[u][v]==0){
                    // too long/no edge
                    add(u,v,w); // decrease of cnt rollbacks this
                    rb_nmp.push({u,v});
                }else if(edges[nmp[u][v]].w>w){ // this is effective, need restore
                    edges[nmp[u][v]].w=w;
                }
            }
        }
    //}
    //printf("%lld\n",MnST());
    DFS(j+1);
    // ==== Revocer nodes ====
    cnt=ecntbeforemod;
    enable_cost-=modcost[j];
    while(!rb_nmp.empty()){
        auto tt=rb_nmp.front(); rb_nmp.pop();
        nmp[tt.first][tt.second]=nmp[tt.second][tt.first]=0;
    }
    for(int i=1;i<=cnt;++i)edges[i]=edgetmp[j][i];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    int u,v,w;
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        // add(v,u,w);
    }
    bool spA=1;
    for(int j=1;j<=k;++j){
        scanf("%d",modcost+j);
        if(modcost[j]!=0)spA=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[j][i]);
        }
    }
    if(k<=0){
        INIT(n);
        // Min Span Tree only
        printf("%lld\n",MnST());
        return 0;
    }
    if(spA){ // All citylization have no cost// e
             // just see them as regular node
        INIT(n);
        for(int j=1;j<=k;++j){
            for(int u=1;u<=n;++u){
                for(int v=u+1;v<=n;++v){
                    long long w=a[j][u]+a[j][v];
                    if(nmp[u][v]==0){
                        // too long/no edge
                        add(u,v,w);
                        // add(v,u,w);
                        // printf("Create %d<-->%d w %d\n",u,v,w);
                    }else if(edges[nmp[u][v]].w>w){
                        edges[nmp[u][v]].w=w;
                        // printf("Modify %d<-->%d = %d->%d\n",u,v,edges[nmp[v][u]].w,w);
                        // edges[nmp[v][u]].w=w;
                    }
                }
            }
        }
        printf("%lld\n",MnST());
        return 0;
    }
    // way: DFS for each decide enable city or not
    // constant: 32
    // complex ~= 32*O(spA)
    // with enable-recover code
    DFS(1);
    printf("%lld\n",gans);
}