#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a);i <= (b);++i)
#define REP(i,a,b) for(int i = (a);i >= (b);--i)
#define GO(x) for(int i = h[x],y = e[i];i;y = e[i=ne[i]])
#define ll long long
static char stkk[200];
template<typename T>inline void output(T x){
    if(!x)return putchar('0'),void();
    if(x<0)x = ~x+1,putchar('-');
    int top = 0;
    for(;x;stkk[++top]=x%10^48,x/=10);
    for(;top;putchar(stkk[top--]));
}
template<typename T>inline void readx(T& x){
    x = 0;int y = 1;char c = getchar();
    for(;c<48||c>58;c = getchar())if(c=='-')y = -1;
    for(;c>=48&&c<=58;c = getchar())x = (x<<1)+(x<<3)+(c^48);
    x *= y;
}
const int T = 2e4+2e6+10,N = 1e4+10,M = 1e6+10;
const ll lnf = 1e18+10;
static int ls[T],rs[T],fa[T],v[T],mx[T],p[T],px[T],py[T];
static bool re[T];
inline bool notrt(int x){return rs[fa[x]]==x||ls[fa[x]]==x;}
inline bool get(int x){return rs[fa[x]]==x;}
inline void add_re(int x){if(x)re[x]^=1,std::swap(ls[x],rs[x]);}
inline void pushdown(int x){if(re[x])add_re(ls[x]),add_re(rs[x]),re[x] = 0;}
void push(int x){
    if(notrt(x))push(fa[x]);
    pushdown(x);
}
inline void pushup(int x){
    mx[x] = std::max(v[x],std::max(mx[ls[x]],mx[rs[x]]));
    if(mx[x]==v[x])p[x] = x;
    else if(mx[x]==mx[ls[x]])p[x] = p[ls[x]];
    else p[x] = p[rs[x]];
}
inline void rot(int x){
    int f = fa[x],g = fa[f];bool sn = get(f);
    // printf("x:%d f:%d g:%d ls:%d rs:%d\n",x,f,g,ls[x],rs[x]);
    if(get(x)){
        rs[f] = ls[x];
        if(ls[x])fa[ls[x]] = f;
        ls[x] = f;
    }
    else{
        ls[f] = rs[x];
        if(rs[x])fa[rs[x]] = f;
        rs[x] = f;
    }
    if(notrt(f)){
        if(sn)rs[g] = x;
        else ls[g] = x;
    }
    fa[f] = x,fa[x] = g;
    pushup(f),pushup(x);
}
inline void spl(int x){
    // printf("spl::%d\n",x);
    push(x);
    for(int f = fa[x];notrt(x);f = fa[x]){
        if(notrt(f))rot(get(f)==get(x)?f:x);
        rot(x);
    }
    pushup(x);
    // printf("end::spl::\n");
}
inline void acs(int x){
    // printf("acs::x:%d\n",x);
    for(int y = 0;x;x = fa[y=x]){
        // printf("x:%d fa:%d y:%d\n",x,fa[x],y);
        spl(x);
        rs[x] = y;
        pushup(x);
    }
}
inline void mkrt(int x){acs(x),spl(x);add_re(x);}
inline void split(int x,int y){mkrt(x),acs(y),spl(y);}
inline void link_p(int x,int y){mkrt(x),fa[x] = y;}
static ll ans,fnl;
static int tp,vct,n,m,k;
// struct nd{int x,y,id;}A[N],B[N];
inline void get_new_p(int x,int y,int w){
    ++vct;
    px[vct] = x,py[vct] = y;
    v[vct] = mx[vct] = w;
    ls[vct] = rs[vct] = fa[vct] = re[vct] = 0;
    p[vct] = vct;
}
inline void link(int x,int y,int id){
    // ls[id] = rs[id] = fa[id] = 0;v[id] = mx[id] = w;
    link_p(x,id),link_p(id,y);
}
inline void cut_p(int x,int y){
    split(x,y);
    if(rs[y]||ls[y]^x)puts("cut_p_err"),exit(0);
    fa[x] = ls[y] = 0;pushup(y);
}
inline void cut(int x,int y,int id){cut_p(x,id),cut_p(id,y);}
inline void renew(int x,int y,int w){
    split(x,y);
    // printf("x:%d y:%d w:%d mx:%d\n",x,y,w,mx[y]);
    if(mx[y]>w){
        ans-=mx[y]-w;
        int i = p[y];
        if(i<=n)puts("?"),exit(0);
        if(!px[i]||!py[i])puts("?"),exit(0);
        // printf("i:%d px:%d py:%d\n",i,px[i],py[i]);
        // A[++tp] = (nd){px[i],py[i],i};
        cut(px[i],py[i],i);
        get_new_p(x,y,w);
        link(x,y,vct);
        // B[tp] = (nd){x,y,vct};
    }
}
inline bool check(int x,int y,int w){
    split(x,y);
    return mx[y]>w;
}
struct node{int x,y,w;bool operator<(const node& A)const {return w<A.w;};}ed[M];
static int e[N<<1],ne[N<<1],w[N<<1],h[N],tot;
static int a[11][N],c[11],stk[11][N],top[11];
inline void add(int x,int y,int ww){e[++tot] = y,ne[tot] = h[x],h[x] = tot;w[tot] = ww;}
static int f[N];
int find(int x){return f[x]^x?f[x]=find(f[x]):x;}
void dfs(int x,int fr){
    ls[x] = rs[x] = re[x] = mx[x] = p[x] = v[x] = re[x] = 0;
    GO(x)if(y^fr){
        get_new_p(x,y,w[i]);
        fa[y] = vct;fa[vct] = x;
        ans+=w[i];
        // printf("x:%d y:%d w:%d\n",x,y,w[i]);
        dfs(y,x);
    }
}
inline void bd(){
    std::sort(ed+1,ed+1+m);
    FOR(i,1,n)f[i] = i;
    FOR(i,1,m){
        int x = ed[i].x,y = ed[i].y,w = ed[i].w,a,b;
        if((a=find(x))==(b=find(y)))continue;
        f[a] = b;
        // printf("x:%d y:%d w:%d\n",x,y,w);
        add(x,y,w),add(y,x,w);
    }
    // puts("Yes");
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    readx(n),readx(m),readx(k);vct = n;
    FOR(i,1,m)readx(ed[i].x),readx(ed[i].y),readx(ed[i].w);
    FOR(i,1,k){
        readx(c[i]);
        FOR(j,1,n)readx(a[i][j]);//,a[i][j]+=c[i];
    }
    // bd();
    int mxn = (1<<k)-1;
    fnl = lnf;
    bd();
    vct = n;dfs(1,0);
    FOR(i,1,k)FOR(j,1,n){
        // assert(!a[i][j]);
        if(i==j)continue;
        if(check(i,j,a[i][j]))stk[i][++top[i]] = j;
    }
    // printf("ans:%lld\n",ans);
    // FOR(i,1,k)printf("top:%d\n",top[i]);
    // fnl = ans;
    
    FOR(sta,1,mxn){
        // puts("start");
        ans = 0;vct = n;
        fa[1] = 0;dfs(1,0);
        // FOR(i,n+1,vct){
        //     printf("i:%d px:%d py:%d v:%d\n",i,px[i],py[i],v[i]);
        // }
        fnl = std::min(fnl,ans);
        FOR(i,1,k)if(sta&(1<<i-1))
        {
            ans+=c[i];
            FOR(j,1,top[i])renew(i,stk[i][j],a[i][stk[i][j]]);
        }
        // printf("ans:%lld\n",ans);
        fnl = std::min(fnl,ans);
    }
    // int w,c;
    // FOR(i,1,k){
    //     tp = ans = 0;
    //     readx(c);
    //     FOR(j,1,n){
    //         readx(w);
    //         if(i==j)continue;
    //         renew(i,j,w);
    //     }
    //     if(ans<c){

    //         REP(i,1,tp){
    //             cut(B[i].x,B[i].y,B[i].id);
    //             link(A[i].x,A[i].y,A[i].id);
    //         }
    //     }
    //     else fnl-=ans-c;
    // }
    // puts("Yes");
    output(fnl),putchar(10);
    return 0;
}
