#include<bits/stdc++.h>
using namespace std;
const int N=1e4+17,K=13,M=1e6+7,bit[11]={1,2,4,8,16,32,64,128,256,512,1024};
int n,m,k,u,v,w,c[K],fa[N],sz[N];
long long res=2e18;
struct G{
    int u,v,w;
}g1[M],g2[K][N],tmp[M+N*K],all[M+N*K];
bool cmp(G a,G b){
    return a.w<b.w;
}
int get(int x){
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    x=get(x),y=get(y);
    if(x==y)return ;
    if(sz[x]>sz[y])swap(x,y);
    fa[x]=y;
    sz[y]+=sz[x];
}
long long kruskal(int tot){
    long long res=0;
    for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=0;
    for(int i=1;i<=tot;i++){
        if(get(all[i].u)!=get(all[i].v)){
            merge(all[i].u,all[i].v);
            res+=all[i].w;
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        g1[i]=(G){u,v,w};
    }
    sort(g1+1,g1+m+1,cmp);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>g2[i][j].w;
            g2[i][j].u=n+i,g2[i][j].v=j;
        }
        sort(g2[i]+1,g2[i]+n+1,cmp);
    }
    int tot;long long sum;
    for(int i=0;i<bit[k];i++){
        tot=sum=0;
        for(int j=1;j<=m;j++)tmp[++tot]=g1[j];
        for(int j=0;j<k;j++){
            if(i&bit[j]){
                int id=j+1,ct=1,cg=1,ca=0;
                sum+=c[id];
                while(ct<=tot&&cg<=n){
                    if(cmp(tmp[ct],g2[id][cg]))all[++ca]=tmp[ct++];
                    else all[++ca]=g2[id][cg++];
                }
                for(;ct<=tot;ct++)all[++ca]=tmp[ct];
                for(;cg<=n;cg++)all[++ca]=g2[id][cg];
                tot=ca;
                for(int e=1;e<=tot;e++)tmp[e]=all[e];
            }
        }
        for(int j=1;j<=tot;j++)all[j]=tmp[j];
        res=min(res,kruskal(tot)+sum);
    }
    cout<<res;
    return 0;
}