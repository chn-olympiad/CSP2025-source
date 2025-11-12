#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e4+15,inf=0x3f3f3f3f;
bool St;
long long ans;
int fa[N],n,m,k,a[11][N],val[11],vis[N];
struct node{
    int u,v,w;
    friend bool operator < (node x,node y){return x.w>y.w;}
}graph[N],c[15][N];
struct edge{
    int to,w;
};
queue<node>q;
priority_queue<node>pq,cit;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void build(int D,long long& sum){
    int tot=n-1,cnt=0;
    int tg=1,t[15];
    for(int i=1;i<=k;i++)t[i]=1;
    for(int i=1;i<=k;i++)if((1<<(i-1))&D)tot++;
    while(cnt<tot){
        node use=graph[tg];
        while(tg<n&&find(graph[tg].u)==find(graph[tg].v))tg++;
        int mn=inf,id=-1;
        if(tg<n)if(graph[tg].w<mn)mn=graph[tg].w,id=0;
        for(int i=1;i<=k;i++){
            if(!((1<<(i-1))&D))continue;
            while(t[i]<=n&&find(n+i)==find(c[i][t[i]].v))t[i]++;
            if(t[i]>n)continue;
            if(c[i][t[i]].w<mn)mn=c[i][t[i]].w,id=i;
        }
        if(!id){
            fa[find(graph[tg].u)]=find(graph[tg].v);
            sum+=graph[tg].w,tg++;
        }else{
            fa[find(c[id][t[id]].u)]=find(c[id][t[id]].v);
            sum+=c[id][t[id]].w,t[id]++;
        }
        cnt++;
    }
}
bool Ed;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int tmp1,tmp2,tmp3;
        scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
        pq.push({tmp1,tmp2,tmp3});
    }
    int tot=0;
    while(!pq.empty()){
        node t=pq.top();
        pq.pop();
        int uu=find(t.u),vv=find(t.v);
        if(uu==vv)continue;
        fa[uu]=vv;
        graph[++tot]={t.u,t.v,t.w};
        ans+=t.w;
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&val[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            cit.push({i+n,j,a[i][j]});
        }
        for(int j=1;j<=n;j++){
            node tmp=cit.top();
            cit.pop();
            c[i][j]={i+n,tmp.v,tmp.w};
        }
    }
    for(int i=0;i<(1<<k);i++){
        long long sum=0;
        for(int j=1;j<=n+k;j++)fa[j]=j;
        for(int j=1;j<=k;j++)if(i&(1<<(j-1)))sum+=val[j];
        build(i,sum);
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
}