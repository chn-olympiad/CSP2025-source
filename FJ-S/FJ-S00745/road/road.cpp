#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define mkp make_pair
#define eb emplace_back
using namespace std;
il int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N=20005,M=2000005;
const int INF=0x3f3f3f3f;
int n,m,k,a[12][N],c[N];
pii v[12][N];
struct E{int x,y,w;}eg[M],e[N];
int tot=0,id[N];

int fa[N],siz[N];
il void init(){
    forto(i,1,n+k)fa[i]=i,siz[i]=1;
}
il int find(int x){return x==fa[x]?x:(fa[x]=find(fa[x]));}
il void merge(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
        if(siz[x]<siz[y])swap(x,y);
        fa[y]=x,siz[x]+=siz[y],siz[y]=0;
    }
}

signed main(){
    freopen("road.in","r",stdin),freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    forto(i,1,m)eg[i].x=read(),eg[i].y=read(),eg[i].w=read();
    sort(eg+1,eg+m+1,[](E &x,E &y){return x.w<y.w;});
    forto(i,1,k){
        c[i]=read();
        forto(j,1,n)a[i][j]=read(),v[i][j]={a[i][j],j};
        sort(v[i]+1,v[i]+n+1);
    }
    init();
    ll ans=0;
    forto(i,1,m){
        int x=eg[i].x,y=eg[i].y;
        if(find(x)!=find(y))merge(x,y),e[++tot]=eg[i],ans+=eg[i].w;
    }
    // cerr<<tot<<'\n';
    // forto(i,1,n-1)cerr<<e[i].w<<' ';cerr<<'\n';
    cerr<<ans<<'\n';
    vector<int>used;
    forto(s,1,(1<<k)-1){
        init();
        ll cost=0;used.clear();
        id[0]=1;
        int need=n-1;
        forto(i,1,k){
            id[i]=1;
            if(s>>(i-1)&1)cost+=c[i],used.eb(i),need++;
        }
        int ecnt=0;
        while(ecnt<need){
            int mn=id[0]<n?e[id[0]].w:INF,mnp=0;
            for(int i:used)if(id[i]<=n&&v[i][id[i]].first<mn){
                mn=v[i][id[i]].first,mnp=i;
            }
            int x,y;
            if(!mnp){
                x=e[id[0]].x,y=e[id[0]].y;
            }else{
                x=n+mnp,y=v[mnp][id[mnp]].second;
            }
            if(find(x)!=find(y)){
                ecnt++,merge(x,y),cost+=mn;
            }
            id[mnp]++;
            // cerr<<mn<<' ';
        }
        // cerr<<'\n';
        ans=min(ans,cost);
    }
    printf("%lld\n",ans);
    return 0;
}