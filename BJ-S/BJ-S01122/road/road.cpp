#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int N=1e4+15,K=15;
int n,m,k,a[K][N],c[K];
bool vis[N];
vector<int>g[N],e[N];
long long ans=1e18;

struct NODE{int pos,dis;};
bool operator>(NODE x,NODE y){return x.dis>y.dis;}

long long prim(){
    memset(vis,0,sizeof(vis));
    long long ret=0;
    priority_queue<NODE,vector<NODE>, greater<NODE> >q;
    q.push({1,0});
    while(!q.empty()){
        int u=q.top().pos,curw=q.top().dis;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        ret+=curw;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i],w=e[u][i];
            if(!vis[v])q.push({v,w});
        }
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back(v);
        e[u].push_back(w);
        g[v].push_back(u);
        e[v].push_back(w);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int stat=0;stat<(1<<k);stat++){
        int cntcity=0;
        long long curcos=0;
        for(int i=1;i<=k;i++){
            if((stat>>(i-1))&1){
                cntcity++;
                curcos+=c[i];
                for(int j=1;j<=n;j++){
                    g[j].push_back(n+i);
                    e[j].push_back(a[i][j]);
                    g[n+i].push_back(j);
                    e[n+i].push_back(a[i][j]);
                }
            }
        }
        curcos+=prim();
        ans=min(ans,curcos);
        for(int i=1;i<=k;i++){
            g[n+i].clear();
            e[n+i].clear();
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=cntcity;j++){
                g[i].pop_back();
                e[i].pop_back();
            }
        printf("%d\n",stat);
    }
    printf("%lld\n",ans);
    return 0;
}