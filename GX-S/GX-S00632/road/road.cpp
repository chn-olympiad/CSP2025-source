#include<bits/stdc++.h>
#define Inf (1ll<<60)
#define inf 0x3f3f3f3f
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define eps 1e-9
typedef long long ll;
typedef unsigned long long ull;
inline int max(int x,int y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmn(int &x,int y){x=min(x,y);}
inline void ckmx(int &x,int y){x=max(x,y);}
inline void ckmn(ll &x,ll y){x=min(x,y);}
inline void ckmx(ll &x,ll y){x=max(x,y);}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || '9'<c) f=(c=='-' ? -1 : 1),c=getchar();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f;
}
using namespace std;
const int N=1e4+100,K=15,M=1e6+5000;
int n,m,k,f[N],a[K][N],sz[K];
struct Edge{
    int u,v,w;
    Edge(int _u=0,int _v=0,int _w=0){
        u=_u,v=_v,w=_w;
    }
}e[M],p[K][N],g[K][N];
bool cmp(Edge x,Edge y){return x.w<y.w;}
int num;
int find(int x){return f[x]=(f[x]==x ? x : find(f[x]));}
ll ans;
void Kr(){
    For(i,1,n) f[i]=i;
    sort(e+1,e+m+1,cmp);
    For(i,1,m){
        int u=e[i].u,v=e[i].v,fu=find(u),fv=find(v);
        if(fu==fv) continue;
        f[fu]=fv;
        p[1][++num]=e[i];
        ans+=e[i].w;
        if(num==n-1) break;
    }
    // printf("ans=%lld\n",ans);
}
void dfs(int dep,ll pre,ll nw){
    if(dep==k+1){
        // printf("%lld %lld\n",pre,nw);
        ckmn(ans,nw+pre);
        return;
    }

    memcpy(p[dep+1],p[dep],sizeof(p[dep+1]));
    sz[dep+1]=sz[dep];
    dfs(dep+1,pre,nw);

    pre+=a[dep][0];
    int ct=0,c1,c2;
    For(i,1,n+k) f[i]=i;
    c1=c2=1,nw=0;
    Edge cur;
    For(i,1,sz[dep]+n-1){
        if(c1==sz[dep]) 
            cur=g[dep][c2],++c2;
        else if(c2==n+1) 
            cur=p[dep][c1],++c1;
        else if(cmp(g[dep][c2],p[dep][c1]))
            cur=g[dep][c2],++c2;
        else
            cur=p[dep][c1],++c1;
        int u=cur.u,v=cur.v,fu=find(u),fv=find(v);
        if(fu==fv) continue;
        f[fu]=fv;
        p[dep+1][++ct]=cur;
        nw+=cur.w;
        if(ct==sz[dep]) break;
    }
    if(ct!=sz[dep]) return;
    ++sz[dep];
    sz[dep+1]=sz[dep];
    dfs(dep+1,pre,nw);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // double t1=1.0*clock()/CLOCKS_PER_SEC;
    n=read(),m=read(),k=read();
    int u,v,w;
    For(i,1,m) u=read(),v=read(),w=read(),e[i]=Edge(u,v,w);
    Kr();
    For(i,1,k){
        For(j,0,n)
            a[i][j]=read();
        For(j,1,n) g[i][j]=Edge(n+i,j,a[i][j]);
        sort(g[i]+1,g[i]+n+1,cmp);
    }
    sz[1]=n;
    dfs(1,0,ans);
    printf("%lld",ans);
    // double t2=1.0*clock()/CLOCKS_PER_SEC;
    // cout<<endl<<t2-t1;
    return 0;
}
