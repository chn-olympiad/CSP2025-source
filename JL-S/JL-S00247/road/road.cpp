#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k,f[N];
struct Edge{
    int u,v,w;
}e[N];
long long ans;
int find(int a){
    return f[a]==a?a:f[a]=find(f[a]);
}
inline bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
void Kruscal(){
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        f[fv]=fu,ans+=w;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    if(k){printf("0\n");return 0;}
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i].u=u,e[i].v=v,e[i].w=w;
    }
    for(int i=1;i<=n;i++) f[i]=i;
    sort(e+1,e+m+1,cmp);
    Kruscal();
    printf("%lld\n",ans);
}
