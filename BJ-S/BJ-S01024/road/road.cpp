#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int u,v,w;
}e[10050];
bool cmp(node x,node y){
    return x.w<y.w;
}
int fee[15];
int c_fee[15][10050];
int fa[10050];
int bcj(int k){
    if(fa[k]==k) return k;
    return fa[k]=bcj(fa[k]);
}
bool merge(int u,int v){
    int fu=bcj(u),fv=bcj(v);
    if(fu!=fv) fa[fu]=fv,return 1;
    return 0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        cin>>fee[i];
        for(int j=1;j<=n;j++) cin>>c_fee[i][j];
    } 
    if(!k){
        for(int i=1;i<=n;i++) fa[i]=i;
        int tot=0;
        sort(e+1,e+m+1,cmp);
        ll F=0;
        for(int i=1;i<=m;i++){
            if(merge(e[i].u,e[i].v)){
                tot++;
                F+=e[i].w;
                if(tot==n-1) break;
            }
        }
        cout<<F;
        return 0;
    }
    return 0;
}