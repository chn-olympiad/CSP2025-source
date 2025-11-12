#include<bits/stdc++.h>
using namespace std;
struct edge{
    int w;
    int u,v;
}e[1100000];
long long kw[13];
int f[11000];
long long md[11000][13];
int ud[13];
int mud[11000][13];
int n,m,k;
long long ans=0;
long long mico,minu;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int find(int x){
    if(f[x]<0) return x;
    return f[x]=find(f[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(f[x]<f[y]){
        f[x]+=f[y];
        f[y]=x;
        for(int i=1;i<=k;i++) md[x][i]=min(md[x][i],md[y][i]);
    }else{
        f[y]+=f[x];
        f[x]=y;
        for(int i=1;i<=k;i++) md[y][i]=min(md[x][i],md[y][i]);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) f[i]=-1;
    for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=k;i++){
        scanf("%lld",&kw[i]);
        ud[i]=1;
        for(int j=1;j<=n;j++){
            mud[j][i]=1;
            scanf("%lld",&md[j][i]);
        }
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        if(find(e[i].u)==find(e[i].v)) continue;
        mico=e[i].w;
        minu=0;
        for(int j=1;j<=k;j++){
            if(mico>=md[find(e[i].u)][j]*mud[find(e[i].u)][j]+md[find(e[i].v)][j]*mud[find(e[i].v)][j]+ud[j]*kw[j]){
                mico=md[find(e[i].u)][j]*mud[find(e[i].u)][j]+md[find(e[i].v)][j]*mud[find(e[i].v)][j]+ud[j]*kw[j];
                minu=j;
            }
        }
        ud[minu]=0;
        mud[find(e[i].u)][minu]=0;
        mud[find(e[i].v)][minu]=0;
        ans+=mico;
        unite(e[i].u,e[i].v);
    }
    printf("%lld",ans);
    return 0;
}
