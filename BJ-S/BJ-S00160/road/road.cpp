#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct side{
     ll u,v,w;
};
side sp[1000505];
int n,m,k,c[15],a[15][100005];
ll sum;
int fa[1000005];
int find(int x){
    if(x==fa[x])return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void join(int a,int b){
    a=find(a),b=find(b);
    fa[a]=b;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&sp[i].u,&sp[i].v,&sp[i].w);
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=sp[i].u,v=sp[i].v,w=sp[i].w;
        if(find(u)!=find(v)){
            join(u,v);
            sum+=w;
        }
    }
    printf("%d",sum);
    return 0;
}
