#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5,K=12;
struct Edge{int u,v,w;};
int n,m,k,c[K],a[K][N];
ll ans=0;
Edge edge[M];
vector<Edge> e;
int p[M*2];
int find_set(int x){
    if(p[x]==x) return x;
    p[x]=find_set(p[x]);
    return p[x];
}
bool union_set(int x,int y){
    x=find_set(x),y=find_set(y);
    if(x!=y){
        p[x]=y;
        return 1;
    }
    return 0;
}
inline bool cmp(const Edge &x,const Edge &y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1,u,v,w;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edge[i]={u,v,w};
    }
    bool is_A=1;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0) is_A=0;
        for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    }
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(k==0) e.push_back({u,v,w});
        else{
            for(int j=1;j<=n;j++)
                for(int l=j+1;l<=n;l++){
                    int minw=0x3f3f3f3f;
                    for(int x=1;x<=k;x++){
                        minw=min(minw,a[x][j]+a[x][l]+c[j]);
                    }
                    e.push_back({u,v,minw});
                }
        }
    }
    sort(e.begin(),e.end(),cmp);
    for(int i=0;i<e.size();i++){
        if(union_set(e[i].u,e[i].v)==1) ans+=e[i].w;
    }
    printf("%lld\n",ans);
    return 0;
}
