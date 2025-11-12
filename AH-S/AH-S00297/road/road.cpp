#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define pr pair<int,int>
#define fi first
#define se second
using namespace std;
template<typename T>void in(T &x){
    char c=getchar();int f=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-'){c=getchar();f=-1;}
    for(x=0;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
    x*=f;
}
template<typename T>T mn(T a,T b){return a<b?a:b;}
template<typename T>T mx(T a,T b){return b<a?a:b;}
const int N=1e4+5,M=1e6+5,K=11,inf=1e9+7;
int n,m,k;
struct h{int x,y,w;}e[M];
ll ans;
int fa[N],sz[N];
int w[K],st[K],cur[K],tp;
pr mi[K][N],tmp[2*N];
bool vis[N],used[M];
int fr(int u){return u==fa[u]?u:fa[u]=fr(fa[u]);}
bool join(int x,int y){
    x=fr(x),y=fr(y);
    if(x==y) return 0;
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y],fa[y]=x;
    return 1;
}
ll kru(int m){
    ll res=0;
    for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;++i){
        if(join(e[i].x,e[i].y)) res+=e[i].w,used[i]=1;
        else used[i]=0;
    }
    return res;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    in(n),in(m),in(k);
    for(int i=1;i<=m;++i) in(e[i].x),in(e[i].y),in(e[i].w);
    for(int i=0;i<k;++i){
        in(w[i]);
        for(int j=1;j<=n;++j) in(mi[i][j].fi),mi[i][j].se=j;
        sort(mi[i]+1,mi[i]+1+n);
    }
    sort(e+1,e+1+m,[](h a,h b){return a.w<b.w;});
    ans=kru(m);
    int m_=0;
    for(int i=1;i<=m;++i) if(used[i]) e[++m_]=e[i];
    m=m_;
    for(int s=1;s<(1<<k);++s){
        ll now=0;
        tp=0;
        for(int j=0;j<k;++j) if(s&(1<<j)) now+=w[j],st[++tp]=j;
        for(int i=1;i<=n+tp;++i) fa[i]=i,sz[i]=1;
        for(int i=1;i<=tp;++i) cur[i]=1;
        for(int i=1;i<=m+1;){
            int id=0,s=(i<=m?e[i].w:inf+1);
            for(int j=1;j<=tp;++j) if(cur[j]<=n&&mi[st[j]][cur[j]].fi<=s) s=mi[st[j]][cur[j]].fi,id=j;
            if(!id){if(join(e[i].x,e[i].y)) now+=s;i++;}
            else{
                if(join(n+id,mi[st[id]][cur[id]].se)) now+=s;
                cur[id]++;
            }
        }
//        printf("%d %lld\n",s,now);
        ans=mn(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}
