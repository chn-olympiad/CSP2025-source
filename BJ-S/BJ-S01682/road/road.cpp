#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
typedef long long ll;
constexpr int N=1e4+100,M=1e6+5;
int n,m,k;
array<int,4> edge[M],e[M*2];
int c[10],a[10][N];
int fa[N];
inline int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={w,u,v};
    }
    rep(i,0,k-1){
        cin>>c[i];
        rep(j,1,n)cin>>a[i][j];
    }
    sort(edge+1,edge+1+m);
    iota(fa+1,fa+1+n,1);
    ll ans=0;
    int es=0;
    rep(i,1,m){
        int w=edge[i][0],u=edge[i][1],v=edge[i][2];
        u=getfa(u),v=getfa(v);
        if(u!=v){
            ans+=w;
            fa[v]=u;
            e[++es]={w,u,v,-1};
        }
    }
    rep(i,0,k-1){
        rep(j,1,n)e[++es]={a[i][j],n+i+1,j,i};
    }
    sort(e+1,e+1+es);
    rep(s,1,(1<<k)-1){
        ll the=0;
        rep(i,0,k-1)if(s>>i&1)the+=c[i];
        iota(fa+1,fa+1+n+k,1);
        int bl=n+k;
        rep(i,1,es){
            if(e[i][3]!=-1&&!(s>>e[i][3]&1))continue;
            int w=e[i][0],u=e[i][1],v=e[i][2];
            u=getfa(u),v=getfa(v);
            if(u!=v){
                the+=w;
                bl--;
                fa[v]=u;
                if(the>=ans||bl==1)break;
            }
        }
        ans=min(ans,the);
    }
    cout<<ans;
    return 0;
}