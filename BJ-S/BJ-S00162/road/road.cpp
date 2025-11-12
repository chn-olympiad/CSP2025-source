#include<bits/stdc++.h>
#define ll long long
#define rep(a,b,c,d) for(ll (a)=(b);(a)<=(c);(a)+=(d))
#define per(a,b,c,d) for(ll (a)=(b);(a)>=(c);(a)-=(d))
#define pb push_back
#define pii pair<ll,ll>
#define mp make_pair
#define endl '\n'
#define _1 first
#define _2 second
#define puts(str) ((cout<<(str)<<endl),0)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const ll MAXN = 10050;
const ll MAXM = 1000010;
const ll MAXV = MAXN;
const ll MOD = 998244353;
#define LOG_INV

namespace Math {
    ll factorial[MAXV];
    #ifndef LOG_INV
    ll _inv[MAXV];
    #endif

    ll qpow(ll base, ll x) {
        ll res=1;
        while(x) {
            if(x&1ll) (res*=base)%=MOD;
            (base*=base)%=MOD;
            x>>=1ll;
        }
        return res;
    }

    void init(ll MAXV = MAXV) {
        factorial[0]=1;
        rep(i,1,MAXV,1) factorial[i]=factorial[i-1]*i%MOD;
        #ifndef LOG_INV
        _inv[1]=1;
        rep(i,2,MAXV,1) _inv[i]=(MOD-MOD/i)*_inv[MOD%i]%MOD;
        #endif
    }

    ll inv(ll x) {
        #ifndef LOG_INV
        return _inv[x];
        #else
        return qpow(x, MOD-2);
        #endif
    }
    
    ll A(ll n, ll m) {
        return factorial[n]*inv(factorial[n-m])%MOD;
    }

    ll C(ll n, ll m) {
        return factorial[n]*inv(factorial[n-m])%MOD*inv(factorial[m])%MOD;
    }
}

using namespace Math;

ll fa[MAXN], sz[MAXN];

ll getfa(ll x) {
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}

ll getsz(ll x) {
    if(fa[x]==x) return sz[x];
    return sz[x]=getsz(getfa(x));
}

void merge(ll x, ll y) {
    if(getfa(x)==getfa(y)) return;
    sz[getfa(x)]+=sz[getfa(y)];
    fa[getfa(y)]=getfa(x);
    getsz(y);
}

ll n,m,k;
vector<pii> edges[MAXN];
vector<pii> edges1[MAXN];
priority_queue<pair<ll,pii>, vector<pair<ll,pii> >, greater<pair<ll,pii> > > sortedEdges;
ll faw[MAXN], faid[MAXN];
ll c[20];
ll a[20][MAXN];
ll fa1[20];
ll RT;

void dfs(ll u, ll fa) {
    faid[u]=fa;
    for(auto vw : edges[u]) {
        if(vw._1!=fa) {
            faw[vw._1]=vw._2;
            dfs(vw._1,u);
        }
    }
}

void dfs1(ll u, ll fa) {
    faid[u]=fa;
    for(auto vw : edges1[u]) {
        if(vw._1!=fa) {
            faw[vw._1]=vw._2;
            dfs(vw._1,u);
        }
    }
}

void delEdge(ll u, ll v, ll w, vector<pii>* _edges) {
    for(auto it=_edges[u].begin();it!=_edges[u].end();++it) {
        auto vw=*it;
        if(vw._1==v&&vw._2==w) {
            _edges[u].erase(it);
            break;
        }
    }
    for(auto it=_edges[v].begin();it!=_edges[v].end();++it) {
        auto vw=*it;
        if(vw._1==u&&vw._2==w) {
            _edges[v].erase(it);
            break;
        }
    }
}

ll solve(ll sel) {
    ll res=0;
    memset(faw, 0, sizeof(faw));
    memset(faid, 0, sizeof(faid));
    dfs(RT, 0);
    rep(i,1,n,1) {
        res+=faw[i];
    }
    rep(i,1,n+10,1) edges1[i]=edges[i];
    // cout<<"ORI "<<res<<endl;
    // cout<<"FIX ";
    rep(i,1,k,1) {
        if(sel&(1ll<<(i-1))) {
            // cout<<i<<" ";
            res+=c[i];
            edges1[n+i].pb(mp(fa1[i],a[i][fa1[i]]));
            edges1[fa1[i]].pb(mp(n+i,a[i][fa1[i]]));
            dfs1(fa1[i], 0);
            RT=fa1[i];
            rep(u,1,n,1) {
                if(u==RT) continue;
                if(a[i][u]<faw[u]) {
                    // if(sel==3)cout<<i<<" MODIFY "<<faid[u]<<" -> "<<u<<": "<<faw[u]<<" -> "<<a[i][u]<<endl;
                    // cout<<n+i<<" "<<u<<endl;
                    res-=faw[u];
                    res+=a[i][u];
                    delEdge(faid[u], u, faw[u], edges1);
                    delEdge(u, faid[u], faw[u], edges1);
                    edges1[n+i].pb(mp(u, a[i][u]));
                    edges1[u].pb(mp(n+i, a[i][u]));
                    faw[u]=a[i][u];
                    faid[u]=n+i;
                }
            }
        }
    }
    // cout<<": "<<res<<endl;
    // cout<<c[1]<<endl;
    return res;
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init();
    cin>>n>>m>>k;
    rep(i,1,m,1) {
        ll u,v,w;
        cin>>u>>v>>w;
        sortedEdges.push(mp(w,mp(u,v)));
    }
    rep(i,1,n,1) sz[i]=1;
    rep(i,1,n,1) fa[i]=i;
    ll rt=sortedEdges.top()._2._1;
    ll rt1=sortedEdges.top()._2._2;
    ll w1=sortedEdges.top()._1;
    merge(rt,rt1);
    sortedEdges.pop();
    ll ans=0;
    edges[rt1].pb(mp(rt,w1));
    edges[rt].pb(mp(rt1,w1));
    ans+=w1;
    ll cnt=1;
    while(getsz(rt)!=n) {
        while(getfa(sortedEdges.top()._2._1)==getfa(sortedEdges.top()._2._2)) sortedEdges.pop();
        ll u=sortedEdges.top()._2._1;
        ll v=sortedEdges.top()._2._2;
        ll w=sortedEdges.top()._1;
        edges[u].pb(mp(v,w));
        edges[v].pb(mp(u,w));
        ans+=w;
        merge(u,v);
    }
    rep(i,1,k,1) {
        cin>>c[i];
        ll w=LLONG_MAX;
        fa1[i]=0;
        rep(j,1,n,1) {
            cin>>a[i][j];
            if(w>a[i][j]) {
                fa1[i]=j;
                w=a[i][j];
            }
        }
        c[i]+=w;
    }
    // cout<<"ORI "<<ans<<endl;
    dfs(rt, 0);
    rep(sel,0,(1ll<<k)-1,1) {
        RT=rt;
        ans=min(ans,solve(sel));
    }
    cout<<ans<<endl;
    return 0;
}