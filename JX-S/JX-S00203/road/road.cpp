#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define Mod 998244353
#define FILE1(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define FILE2(x) freopen(x".in","r",stdin),freopen(x".ans","w",stdout)
#define FILE3(x) freopen(x".in","r",stdin)
#define N 10055
#define M 1000005
using namespace std;
int read(){
    int x=0,f=1,ch=getchar();
    for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    return x*f;
}
int n,m,k,tot,cnt,c[15];
ll ans=LLINF;
bool flg=true;
struct DSU{
    int fa[N];
    void init(){for(int i=1;i<=n+k;++i) fa[i]=i;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    bool same(int x,int y){return find(x)==find(y);}
    void merge(int x,int y){fa[find(x)]=find(y);}
}dsu;
struct edge{
    int x,y,w;
    friend bool operator < (const edge &a,const edge &b){
        return a.w<b.w;
    }
}E[M],e[N],f[15][N],tmp[M];
bool check(int x,int base){return x>>base&1;}
ll Kruskal(){
    dsu.init();ll res=0;
    for(int i=1;i<=tot;++i){
        int x=E[i].x,y=E[i].y,w=E[i].w;
        if(dsu.same(x,y)) continue;
        res+=w,dsu.merge(x,y);
        if(flg) e[++cnt]=E[i];
    }
    return res;
}
int main(){
    FILE1("road");
    n=read(),m=read(),k=read(),dsu.init();
    for(int i=1;i<=m;++i){
        int x=read(),y=read(),w=read();
        E[++tot]=(edge){x,y,w};
    }
    sort(E+1,E+tot+1),ans=Kruskal(),flg=false;
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j){
            int w=read();
            f[i][j]=(edge){n+i,j,w};
        }
        sort(f[i]+1,f[i]+n+1);
    }
    for(int s=1;s<(1<<k);++s){
        tot=0;ll res=0;
        for(int i=1;i<=cnt;++i) E[++tot]=e[i];
        for(int i=1;i<=k;++i){
            if(!check(s,i-1)) continue;
            int l=1,r=1,cc=0;res+=c[i];
            while(l<=tot && r<=n){
                if(E[l].w<=f[i][r].w) tmp[++cc]=E[l],++l;
                else tmp[++cc]=f[i][r],++r;
            }
            while(l<=tot) tmp[++cc]=E[l],++l;
            while(r<=n) tmp[++cc]=f[i][r],++r;
            for(int j=1;j<=cc;++j) E[j]=tmp[j];
            tot=cc;
        }
        ans=min(ans,res+Kruskal());
    }
    printf("%lld",ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/