#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(r);i>=(l);--i)
#define pr pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define bg(x) (x).begin()
#define ed(x) (x).end()
#define sz(x) (int)(x).size()

#define N 202511
#define K 12
#define int long long

int n,m,k,c[K],a[K][N];

struct edge{
    int u,v,w;
};
vector<edge>edg,e;

struct dsu{
    int fa[N];

    inline void init(){
        rep(i,1,n+k){
            fa[i]=i;
        }
    }

    inline int ask(int k){
        if(fa[k]==k){
            return k;
        }
        return fa[k]=ask(fa[k]);
    }

    inline bool mg(int x,int y){
        x=ask(x),y=ask(y);

        if(x==y){
            return 0;
        }

        fa[x]=y;

        return 1;
    }
}d;

int tot,ans,du[N];

inline void init(){
    e=edg;
    d.init();

    int re=0;
    vector<edge>sb;

    sort(all(e),[](edge x,edge y){
        return x.w<y.w;
    });

    for(edge x:e){
        int u=x.u,v=x.v,w=x.w;

        if(d.mg(u,v)){
            re+=w;
            sb.pb(x);
        }
    }

    edg=sb;
}

inline int sol(int s){
    e=edg;
    d.init();

    rep(i,1,n+k){
        du[i]=0;
    }

    int re=0;

    rep(i,1,k){
        if(!(s>>(i-1)&1)){
            continue;
        }

        re+=c[i];

        rep(j,1,n){
            e.pb({n+i,j,a[i][j]});
        }
    }

    sort(all(e),[](edge x,edge y){
        return x.w<y.w;
    });

    for(edge x:e){
        int u=x.u,v=x.v,w=x.w;

        if(d.mg(u,v)){
            re+=w;
            du[u]++,du[v]++;
        }

        if(re>ans){
            return 1e18;
        }
    }

    rep(i,1,k){
        if(!(s>>(i-1)&1)){
            continue;
        }
        if(du[i+n]<=1){
            re-=c[i];
        }
    }

    return re;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // clock_t st=clock();

    cin>>n>>m>>k;

    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        edg.pb({u,v,w});
    }

    bool az=1;

    rep(i,1,k){
        cin>>c[i];
        az&=(c[i]==0);
        rep(j,1,n){
            cin>>a[i][j];
        }
    }

    init();

    // cout<<sz(edg)<<'\n';

    tot=(1<<k)-1;

    ans=1e18;

    // if(az){
    //     ans=sol(tot);
    //     cout<<ans<<'\n';
    //     return 0;
    // }

    rep(s,0,tot){
        ans=min(ans,sol(s));
    }

    cout<<ans<<'\n';

    /*
    g++ road.cpp -o road -O2 -std=c++14 -Wall -Wextra -Wshadow
    */

    return 0;
}