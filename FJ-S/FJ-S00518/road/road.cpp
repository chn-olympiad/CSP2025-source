#include <bits/stdc++.h>
using namespace std;
using tp=long long;
#define For(i,l,r) for(tp i(l),i##sc03(r);i<=i##sc03;++i)
#define FoR(i,r,l) for(tp i(r),i##sc03(l);i>=i##sc03;--i)
#define ALL(G) G.begin(),G.end()
#define SIZ(G) tp(G.size())
#define pb emplace_back
#define pf emplace_front
#define ep emplace
#define gp make_pair
#define fr first
#define sd second
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')ch=='-'?f=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();return x*f;
}inline bool write(tp x,char ch='\n'){return printf("%lld",x),putchar(ch),true;}
template<class T>inline T Max(T a,T b){return a>b?a:b;}
template<class T>inline T Min(T a,T b){return a<b?a:b;}
template<class T,class Q>inline bool Cmax(T&a,Q b){return a<b?a=b,true:false;}
template<class T,class Q>inline bool Cmin(T&a,Q b){return a>b?a=b,true:false;}
constexpr int K=13;
constexpr int N=1000010;
int n,m,k;int fa[N],c[K],a[K][10010];
struct Edge{int u,v,w;}E[N*10],B[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
namespace SpecialK{
int main(){
    tp ans=0;
    sort(E+1,E+m+1,[&](Edge a,Edge b){return a.w<b.w;});
    For(i,1,m){
        int x=E[i].u,y=E[i].v;
        x=find(x);y=find(y);fa[y]=x;
        x!=y?ans+=E[i].w:0;
    }return!write(ans);
}}
namespace Brute{
int cnt=0,nod=0;bool vis[11];
inline void add(int u,int v,int w){++cnt;E[cnt].u=u;E[cnt].v=v;E[cnt].w=w;return void();}
int main(){
    tp ans=1e18;
    For(i,1,m)B[i].u=E[i].u,B[i].v=E[i].v,B[i].w=E[i].w;
    For(s,0,(1<<k)-1){
        cnt=m;
        nod=n;
        tp res=0;
        For(i,0,k-1)vis[i]=0;
        For(i,1,m)E[i].u=B[i].u,E[i].v=B[i].v,E[i].w=B[i].w;
        For(i,0,k-1)vis[i]=(s>>i&1);
        // For(i,0,k-1)cerr<<vis[i]<<' ';cerr<<'\n';
        For(l,0,k-1)if(vis[l]){
            tp pos=l+1;res+=c[pos];++nod;
            For(i,1,n){
                add(nod,i,a[pos][i]);
            }
        }
        // cerr<<nod<<' '<<cnt<<'\n';
        For(i,1,nod)fa[i]=i;tp CNT=0;
        sort(E+1,E+cnt+1,[&](Edge a,Edge b){return a.w<b.w;});
        For(i,1,cnt){
            int x=E[i].u,y=E[i].v;
            // cerr<<x<<' '<<y<<' '<<E[i].w<<'\n';
            x=find(x);y=find(y);fa[y]=x;
            x!=y?res+=E[i].w,++CNT:0;
            if(CNT==nod-1)break;
        }
        // cerr<<res<<'\n';
        Cmin(ans,res);
        // cerr<<res<<'\n';
    }write(ans);
    return 0;
}}
namespace SpecialA{
int cnt=0,nod=0;bool vis[11];
inline void add(int u,int v,int w){++cnt;E[cnt].u=u;E[cnt].v=v;E[cnt].w=w;return void();}
int main(){
    tp ans=1e18;
    For(i,1,m)B[i].u=E[i].u,B[i].v=E[i].v,B[i].w=E[i].w;
    For(s,(1<<k)-1,(1<<k)-1){
        cnt=m;
        nod=n;
        tp res=0;
        For(i,0,k-1)vis[i]=0;
        For(i,1,m)E[i].u=B[i].u,E[i].v=B[i].v,E[i].w=B[i].w;
        For(i,0,k-1)vis[i]=(s>>i&1);
        // For(i,0,k-1)cerr<<vis[i]<<' ';cerr<<'\n';
        For(l,0,k-1)if(vis[l]){
            tp pos=l+1;res+=c[pos];++nod;
            For(i,1,n){
                add(nod,i,a[pos][i]);
            }
        }
        // cerr<<nod<<' '<<cnt<<'\n';
        For(i,1,nod)fa[i]=i;tp CNT=0;
        sort(E+1,E+cnt+1,[&](Edge a,Edge b){return a.w<b.w;});
        For(i,1,cnt){
            int x=E[i].u,y=E[i].v;
            // cerr<<x<<' '<<y<<' '<<E[i].w<<'\n';
            x=find(x);y=find(y);fa[y]=x;
            x!=y?res+=E[i].w,++CNT:0;
            if(CNT==nod-1)break;
        }
        // cerr<<res<<'\n';
        Cmin(ans,res);
        // cerr<<res<<'\n';
    }write(ans);
    return 0;
}}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    bool flg=true;
    For(i,1,n)fa[i]=i;
    For(i,1,m)E[i].u=read(),E[i].v=read(),E[i].w=read();
    For(j,1,k){c[j]=read();flg&=(c[j]==0);For(i,1,n)a[j][i]=read();}
    if(k==0)return SpecialK::main();
    if(flg)return SpecialA::main();
    Brute::main();
    return 0;
}