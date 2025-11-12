#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct edge{
    int u,v,w;
    bool operator<(const edge& b)const{
        return w<b.w;
    }
}edges[2000005];
int edge_num;
int c[15],sum_c;
int fa[30005];
void fainit(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void solve_k0(){
    sort(edges+1,edges+edge_num+1);
    fainit();
    int ans=0;
    for(int i=1;i<=edge_num;i++){
        int x=find(edges[i].u),y=find(edges[i].v);
        if(x!=y){
            fa[x]=y;
            ans+=edges[i].w;
        }
    }
    cout<<ans;
}
void solve_A(){

}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        edge_num++;
        cin>>edges[edge_num].u>>edges[edge_num].v>>edges[edge_num].w;
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        sum_c+=c[j];
        for(int i=1;i<=n;i++){
            edge_num++;
            cin>>edges[edge_num].w;
            edges[edge_num].u=j;
            edges[edge_num].v=i;
        }
    }
    if(k==0){
        solve_k0();
    }else if(sum_c==0){
        solve_k0();
    }
    return 0;
}
