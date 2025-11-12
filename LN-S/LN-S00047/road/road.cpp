//Kruscal
//wish to get 16pts
#include<bits/stdc++.h>
using namespace std;
const int mxN=1e4+25,mxM=1e6+25;
int n,m,k,fa[mxN],a[mxN][mxN],cnt;
struct edge{
    int u,v,w;
}edg[mxM];
int look(int x){
    if(fa[x]==x) return x;
    else return fa[x]=look(fa[x]);
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edg[i].u,&edg[i].v,&edg[i].w);
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    sort(edg+1,edg+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fu=look(fa[edg[i].u]),fv=look(fa[edg[i].v]);
        if(fu!=fv){
            fa[fu]=fa[fv];
            cnt+=edg[i].w;
        }
    }
    cout<<cnt;
    return 0;
}
//I want to go d/i/e
//try to AC it
//but it's easy to see I can't
//OI is so difficult
//who can k/i/l/l me immediately
//Say bye to Information.Say Hello to biology.QVQ QAQ QOQ O^O Q^Q QAQ
//I wanna d/i/e!!
