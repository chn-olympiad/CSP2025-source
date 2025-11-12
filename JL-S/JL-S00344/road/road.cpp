#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10020,M=1e6+10;
const ll inf=1e18;
int n,m,k,a[11][N],c[11];
ll ans=inf;
struct edge{int u,v,w;}e[M],ee[N*10];
inline bool operator <(edge a,edge b){return a.w<b.w;}
// inline int read(){
//     int x=0;char ch=getchar();
//     while(ch<'0'||ch>'9') ch=getchar();
//     while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
//     return x;
// }
struct dsu{
    int fa[N],siz[N];
    void init(int n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
    inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    inline bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return 0;
        if(siz[x]>siz[y]) swap(x,y);
        fa[x]=y,siz[y]+=siz[x];
        return 1;
    }
}d;
inline ll solve(int s){
    int nn=n+__builtin_popcount(s);
    ll res=0;
    int cnt=0,tot=0;
    for(int i=1;i<=k;i++) if(s>>(i-1)&1){
        res+=c[i];
        for(int j=1;j<=n;j++) ee[++tot]={n+i,j,a[i][j]};
    }
    if(res>ans) return inf;
    d.init(nn);
    sort(ee+1,ee+tot+1);
    int i=1,j=1;
    while(cnt<nn-1&&(i<=m||j<=tot)){
        edge E;
        if(j>tot) E=e[i++];
        else if(i>m) E=ee[j++];
        else E=(e[i]<ee[j]?e[i++]:ee[j++]);
        if(d.merge(E.u,E.v)) res+=E.w,cnt++;
        if(res>ans) return inf;
    }
    if(cnt<nn-1) return inf; 
    return res;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    // n=read(),m=read(),k=read();
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        // u=read(),v=read(),w=read();
        e[i]={u,v,w};
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=k;i++){
        cin>>c[i];
        // c[i]=read();
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    // cerr<<"done\n";
    for(int s=(1<<k)-1;s>=0;s--) ans=min(ans,solve(s));
    cout<<ans<<"\n";
    return 0;
}