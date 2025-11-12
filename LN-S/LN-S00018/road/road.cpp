#include<bits/stdc++.h>
namespace fzx{
    const int N=1e4+10,M=1e6+10;
    int fa[N];
    struct edge{
        int u,v,w;
    }g[M];
    bool cmp(edge x,edge y){
        return x.w<y.w;
    }
    int get(int x){
        if(fa[x]==x)return x;
        return fa[x]=get(fa[x]);
    }
    void merge(int x,int y){
        fa[get(x)]=get(y);
    }
    void main(){
        int n,m,k,res=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            g[i]={u,v,w};
        }
        std::sort(g+1,g+1+m,cmp);
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=m;i++)
            if(get(g[i].u)!=get(g[i].v))
                merge(g[i].u,g[i].v),res+=g[i].w;
        printf("%d\n",res);
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    fzx::main();
    return 0;
}