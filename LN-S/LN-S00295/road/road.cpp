#include<iostream>
#include<cstring>
#include<climits>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge{
    int u,v,w;
}ed[N*N];
int ecnt;
int n,m,k;
int vis[N][N];
int fa[N];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(vis,0x3f3f3f3f,sizeof(vis));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        if(u>v)swap(u,v);
        vis[u][v]=min(vis[u][v],w);
    }
    while(k--){
        int zhegebianliangshenmeyongyemeiyou;
        scanf("%d",&zhegebianliangshenmeyongyemeiyou);
        vector<int>a;
        for(int i=1;i<=n;i++){
            int val;
            scanf("%d",&val);
            for(int j=0;j<i-1;j++){
                vis[j+1][i]=min(vis[j+1][i],val+a[j]);
            }
            a.push_back(val);
        }
    }
    for(int u=1;u<=n;u++){
        for(int v=u+1;v<=n;v++){
            ecnt++;
            ed[ecnt].u=u;
            ed[ecnt].v=v;
            ed[ecnt].w=vis[u][v];
        }
    }
    init();
    sort(ed+1,ed+1+ecnt,cmp);
    int sum=0;
    ll ans=0;
    for(int i=1;i<=m;i++){
        int u=ed[i].u;
        int v=ed[i].v;
        int w=ed[i].w;
        if(find(u)!=find(v)){
            sum++;
            ans+=w;
            fa[find(u)]=find(v);
            if(sum==n-1)break;
        }
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
