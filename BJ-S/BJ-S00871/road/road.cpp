#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const long long inf = 1e9+10;
int n,m,k,fa[N];
long long g[N][N];
struct node{
    long long u,v,w;
};
vector<node> f;
bool cmp(node a,node b){
    return a.w < b.w;
}
int find1(int x){
    if(fa[x]==x)return x;
    return fa[x]=find1(fa[x]);
}
void update(int u,int v){
    u=find1(u);
    v=find1(v);
    fa[u]=v;
}
int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(g,inf,sizeof(g));
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        long long u,v,w;
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u][v]=min(g[u][v],w);
        g[v][u]=min(g[v][u],w);
    }
    for(int i=1;i<=k;i++){
        long long c;
        scanf("%lld",&c);
        vector<long long> p(n+1);
        for(int j=1;j<=n;j++){
            scanf("%d",&p[j]);
        }
        for(int j=1;j<=n;j++){
            for(int a=j+1;a<=n;a++){
                g[j][a]=min(g[j][a],p[j]+p[a]+c);
                g[a][j]=min(g[a][j],p[j]+p[a]+c);
            }
        }
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
        for(int j=i+1;j<=n;j++){
            if(i==j)continue;
            if(g[i][j]!=inf){
              f.push_back({i,j,g[i][j]});
            }
        }
    }
    sort(f.begin(),f.end(),cmp);
    long long ans=0;
    for(int i=0;i<f.size();i++){
        if(find1(f[i].u)==find1(f[i].v))continue;
        ans+=f[i].w;
        update(f[i].u,f[i].v);
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
