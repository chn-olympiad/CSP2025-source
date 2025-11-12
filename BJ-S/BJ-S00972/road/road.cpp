#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15];
struct edge{
    int u,v,w;
}e[2000005];
int fa[20005];//并查集
int find(int x){
    if(!fa[x])return x;
    return fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b){return a.w<b.w;}
int size[20005];//并查集
int te[15];//此点是否有用，浪费的w
int kruskal(){
    int ans=0;
    for(int i=1;size[find(1)]<n&&i<=m;++i){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v)){
            if(size[u]>size[v])swap(u,v);
            fa[find(u)]=find(v);size[v]+=size[u];
            // if(u>n){
            //     if(te[u])
            // }
            ans+=w;
        }
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)size[i]=1;//乡村无实际意义
    for(int i=1;i<=m;++i){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i=1;i<=k;++i){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;++j){
            scanf("%lld",&e[m+i].w);
        }
    }
    sort(e+1,e+m+1,cmp);
    cout<<kruskal()<<endl;
    return 0;
}