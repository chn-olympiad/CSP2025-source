#include<bits/stdc++.h>

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)

#define all(vc) vc.begin(),vc.end()
#define SZ(vc) (int)(vc.size())

#define pb push_back
#define fi first
#define se second


using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL,LL> PLL;

const int N=1e4+5,M=1e6+5,K=15;
int n,k,m,p[N],c[K];
PII cost[K][N];
bool st[N];
int find(int x){
    if(p[x]^x)p[x]=find(p[x]);
    return p[x];
}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x^y)p[x]=y;
}
void init(){rep(i,1,n)p[i]=i;}
struct Edge{
    int u,v,w;
    bool operator<(const Edge&W)const{
        return w<W.w;
    }
}e[M],me[M];


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);



    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    rep(i,1,m){
        int u,v,w;cin>>u>>v>>w;
        e[i]=(Edge){u,v,w};
    }
    rep(i,1,k){
        cin>>c[i];
        rep(j,1,n)cin>>cost[i][j].fi,cost[i][j].se=j;
        sort(cost[i]+1,cost[i]+1+n);
    }
    init();
    sort(e+1,e+1+m);
    int now=0;
    LL ans=0;
    rep(i,1,m){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        if(find(u)!=find(v))merge(u,v),ans+=w,me[++now]=(Edge){u,v,w};
    }
    rep(i,1,(1<<k)-1){
        LL res=0;
        rep(j,0,k-1)if(i>>j&1)res+=1ll*c[j+1]+cost[j+1][1].fi;
        if(res>=ans)continue;
        init();
        rep(j,1,n-1)e[j]=me[j];
        int cnt=n-1;
        rep(j,0,k-1)if(i>>j&1)
            rep(l,2,n)if(cost[j+1][l].fi<e[n-1].w)e[++cnt]=(Edge){cost[j+1][1].se,cost[j+1][l].se,cost[j+1][l].fi};
        sort(e+1,e+1+cnt);
        int now=0;
        rep(j,1,cnt){
            int u=e[j].u,v=e[j].v,w=e[j].w;
            if(find(u)!=find(v))merge(u,v),res+=w,++now;
            if(res>=ans||now>=n-1)break;
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';




    return 0;
}
