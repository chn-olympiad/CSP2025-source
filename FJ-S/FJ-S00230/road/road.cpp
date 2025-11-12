#include<bits/stdc++.h>
using namespace std;

int n,m,T,t,N,c[20],fa[1020]; long long ans=1e18;
struct Edge{
    int u,v,w;
    inline bool operator<(const Edge&o)const{return w<o.w;}
};
vector<Edge>e[20];

int Find(int o){return o==fa[o]?o:fa[o]=Find(fa[o]);}
inline long long Tree(vector<Edge>E,int cnt){ //return 0;
    long long res=0;
    for(int i=1;i<=n+T;++i)fa[i]=i;
    for(int i=0,j=0;i<E.size()&&j<n+cnt-1;++i){
        int u=E[i].u,v=E[i].v,w=E[i].w;
        if(Find(u)!=Find(v))fa[Find(u)]=Find(v),++j,res+=w;//,printf("choose %d %d %d\n",u,v,w);
    }
    return res;
}
void dfs(int k,vector<Edge>E,long long sum,int cnt){
    if(k>t){ 
        /*if(sum==1){
            puts("I love you");
            for(int i=0;i<E.size();++i)printf("%d %d %d\n",E[i].u,E[i].v,E[i].w);
        }*/
        long long res=sum+Tree(E,cnt); //printf("%lld %lld\n",sum,res);
        ans=min(ans,res); return; 
    }
    dfs(k+1,E,sum,cnt);
    vector<Edge>EE; int pos=0;
    for(int i=0;i<E.size();++i){
        while(pos<e[k].size()&&e[k][pos]<E[i])EE.push_back(e[k][pos++]);
        EE.push_back(E[i]);
    }
    while(pos<e[k].size())EE.push_back(e[k][pos++]);
    dfs(k+1,EE,sum+c[k],cnt+1);
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&T),N=n;
    vector<Edge>E;
    for(int i=1;i<=m;++i){
        int u,v,w; scanf("%d%d%d",&u,&v,&w),E.push_back(Edge{u,v,w});
    }
    for(int i=1;i<=T;++i){
        int C; scanf("%d",&C);
        if(C==0){
            ++N;
            for(int j=1;j<=n;++j){
                int w; scanf("%d",&w),E.push_back(Edge{n+i,j,w});
            }
            continue;
        }
        c[++t]=C;
        for(int j=1;j<=n;++j){
            int w; scanf("%d",&w),e[t].push_back(Edge{n+i,j,w});
        }
        sort(e[t].begin(),e[t].end());
    }
    sort(E.begin(),E.end()),dfs(1,E,0,N),printf("%lld",ans);
}