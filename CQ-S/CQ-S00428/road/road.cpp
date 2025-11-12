#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define repl(i,x,y) for(register int i=(x);i<(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define fir first
#define sec second
#define pub push_back
#define pob pop_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double flt;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define put(x) cout<<(x)<<"\n"
#define file(f) freopen(#f".in","r",stdin);freopen(#f".out","w",stdout);

const int N=1e4+15,M=1e6+5,K=15;

int n,m,k,mm;

struct edge{
    int a,b;
    ll c;
}es[M],ns[M];

ll c[K];
ll v[K][N];
bool use[M];
ll ans=1e18,sum=0;

int fa[N];
inline int find(int x){if(fa[x]!=x)fa[x]=find(fa[x]);return fa[x];}
inline void merge(int a,int b){fa[find(a)]=fa[b];}
inline bool same(int a,int b){return find(a)==find(b);}

// vector<pil> g[N],g2[N];

// int st[N],pre[N],l[N];
// ll f[N][2];
// void dfs(int x,int fa,int k){
//     f[i][0]=0;
//     f[i][1]=c[k]+v[k][i];
// }

inline void Main(){
    cin>>n>>m>>k;
    rep(i,1,n)fa[i]=i;
    rep(i,1,m){
        cin>>es[i].a>>es[i].b>>es[i].c;
    }
    repl(i,0,k){
        cin>>c[i];
        rep(j,1,n)cin>>v[i][j];
    }
    sort(es+1,es+1+m,[&](edge a,edge b){return a.c<b.c;});
    rep(i,1,m){
        if(same(es[i].a,es[i].b))continue;
        merge(es[i].a,es[i].b);
        use[i]=1;
    }
    mm=0;
    rep(i,1,m)if(use[i])ns[++mm]=es[i];//,g[es[i].a].pub({es[i].b,es[i].c}),g[es[i].b].pub({es[i].a,es[i].c});
    repl(s,0,1<<k){
        sum=0;
        repl(j,0,k)if(s>>j&1)sum+=c[j];
        m=mm;
        rep(i,1,mm)es[i]=ns[i];
        repl(j,0,k)if(s>>j&1){
            rep(i,1,n)es[++m]={n+j+1,i,v[j][i]};
        }
        sort(es+1,es+1+m,[&](edge a,edge b){return a.c<b.c;});
        rep(i,1,n+k+1)fa[i]=i;
        rep(i,1,m){
            if(same(es[i].a,es[i].b))continue;
            merge(es[i].a,es[i].b);
            sum+=es[i].c;
        }
        chmin(ans,sum);
    }
    put(ans);
    // dfs(1,0);
    // repl(i,0,k){
    //     dfs(1,0,i);
    //     if(f[1][1]<f[1][0]){

    //     }
    // }
}
int main(){
    file(road);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(16);
    Main();
    return 0;
}