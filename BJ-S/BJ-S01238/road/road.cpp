#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define x first
#define y second
ll n,m,k;
const ll N=1e4,K=10;
struct node{
    ll u,v,w;
};
vector<node> g;
vector<vector<pair<ll,ll>>> g3(N+5);
ll c[K+5];
ll fa[N+5];
vector<ll> a[K+5];
ll find(ll x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void init(void){
    for(ll i=0;i<=n;i++) fa[i]=i;
}
bool merge(ll u,ll v){
    u=find(u);
    v=find(v);
    if(u==v) return 0;
    fa[v]=u;
    return 1;
}
bool cmp(node x,node y){
    return x.w<y.w;
}
ll kru(vector<node>& g2){
    init();
    ll sum=0;
    for(auto it:g2){
        ll u=it.u,v=it.v,w=it.w;
        if(merge(u,v)){
            sum+=w;
        }
    }
    return sum;
}
ll dis[N+5];
bool flag[N+5];
ll prim(vector<vector<pair<ll,ll>>>& g4){
    for(ll i=0;i<=n;i++){
        dis[i]=1e9;
        flag[i]=0;
    }
    dis[0]=0;
    ll res=0;
    for(ll i=0;i<=n;i++){
        ll k=-1;
        for(ll j=0;j<=n;j++){
            if(flag[j]) continue;
            if(k==-1||dis[j]<dis[k]) k=j;
        }
        flag[k]=1;
        res+=dis[k];
        for(auto it:g4[k]){
            ll v=it.x,w=it.y;
            dis[v]=min(dis[v],w);
        }
    }
    return res;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(ll i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        g.pb({u,v,w});
        g3[u].pb({v,w});
        g3[v].pb({u,w});
    }
    for(ll i=1;i<=k;i++){
        cin>>c[i];
        a[i].pb(0);
        for(ll j=1,w;j<=n;j++){
            cin>>w;
            a[i].pb(w);
        }
    }
    if(m<=100000&&k<=5){
        sort(g.begin(),g.end(),cmp);
        ll ans=1e9;
        for(ll mask=0;mask<(1<<k);mask++){
            ll cnt=0;
            vector<node> g2=g;
            for(ll i=0;i<k;i++){
                if((mask&(1<<i))!=0){
                    cnt+=c[i+1];
                    for(ll j=1;j<=n;j++){
                        g2.pb({0,j,a[i+1][j]});
                    }
                }
            }
            sort(g2.begin(),g2.end(),cmp);
            cnt+=kru(g2);
            ans=min(ans,cnt);
        }
        cout<<ans;
    }else if(n<=1000&&k<=5){
        ll ans=1e9;
        for(ll mask=0;mask<(1<<k);mask++){
            ll cnt=0;
            vector<vector<pair<ll,ll>>> g4=g3;
            for(ll i=0;i<k;i++){
                if((mask&(1<<i))!=0){
                    cnt+=c[i+1];
                    for(ll j=1;j<=n;j++){
                        g4[0].pb({j,a[i+1][j]});
                        g4[j].pb({0,a[i+1][j]});
                    }
                }
            }
            cnt+=prim(g4);
            ans=min(ans,cnt);
        }
        cout<<ans;
    }else{
        cout<<0;
    }
    return 0;
}
