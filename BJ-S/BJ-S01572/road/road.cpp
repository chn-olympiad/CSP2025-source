#include <bits/stdc++.h>
using namespace std;
#define LL long long

inline int I(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x;
}

#define N 10017
#define M 1100007

int n,m,k;

struct qwq{int u,v,w;}edge[M];
int id[M];
inline bool cmp(int i,int j){return edge[i].w<edge[j].w;}

int c[12];

LL Ans=3e18;

int fa[N];
inline int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
bool Use[12];

inline void solve(int mask){
    LL res=0;
    int n_=n;
    for(int i=0;i<k;i++){
        Use[i+1]=(mask>>i)&1;
        res+=Use[i+1]*c[i+1];
        n_+=Use[i+1];
    }
    
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=edge[id[i]].u,v=edge[id[i]].v;
        if(v>n&&!Use[v-n]) continue;
        u=getfa(u),v=getfa(v);
        if(u==v) continue;
        fa[u]=v,res+=edge[id[i]].w,n_--;
        if(n_==1) break;
    }
    Ans=min(Ans,res);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n=I(),m=I(),k=I();
    for(int i=1;i<=m;i++) id[i]=i,edge[i].u=I(),edge[i].v=I(),edge[i].w=I();
    for(int i=1;i<=k;i++){
        c[i]=I();
        for(int j=1;j<=n;j++){
            m++;
            id[m]=m;
            edge[m].u=j,edge[m].v=n+i;
            edge[m].w=I();
        }
    }
    sort(id+1,id+m+1,cmp);

    for(int i=0;i<(1<<k);i++) solve(i);
    printf("%lld\n",Ans);

    return 0;
}
/*
g++ -Wall road.cpp -o road
./road
*/