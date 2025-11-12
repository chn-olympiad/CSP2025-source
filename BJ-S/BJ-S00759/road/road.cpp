#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll db=1;
const ll inf=1e18;
struct bcj{
    vector<ll>f;
    bcj(ll n):f(n+1){for(ll i=1;i<=n;i++)f[i]=i;}
    ll fd(ll x){
        if(f[x]==x)return x;
        return f[x]=fd(f[x]);
    }
    ll mg(ll a,ll b){
        a=fd(a);b=fd(b);
        if(a==b)return 0;
        f[a]=f[b];
        return 1;
    }
};
struct node{
    ll u,v,w;
};
bool cmp(node a,node b){
    if(a.w!=b.w)return a.w<b.w;
    return a.u>b.u;
}
void solve(ll n,ll m,ll k,vector<node>&a,vector<ll>&c,vector<vector<ll>>&r){
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++)a.push_back({n+i,j,r[i][j]+c[i]});
    }
    sort(a.begin()+1,a.end(),cmp);
    ll ans=0,ct=0;
    bcj tr(n+k);
    vector<ll>vis(n+k+1);
    for(ll i=1;i<=a.size();i++){
        if(!tr.mg(a[i].u,a[i].v))continue;
        if(ct>=n)break;
        ans+=a[i].w;
        if(a[i].u<=n&&vis[a[i].u]==0)ct++;
        if(a[i].v<=n&&vis[a[i].v]==0)ct++;
        vis[a[i].u]++;vis[a[i].v]++;
        if(db&2)printf(":i=%lld:ans=%lld:a=(%lld,%lld,%lld):vis=(%lld,%lld):ct=%lld\n",i,ans,a[i].u,a[i].v,a[i].w,vis[a[i].u],vis[a[i].v],ct);
    }
    for(ll i=n+1;i<=n+k;i++)if(vis[i])ans-=c[i-n]*(vis[i]-1);
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    if(db&1)freopen("road.in","r",stdin);
    if(db&1)freopen("road.out","w",stdout);
    ll n,m,k;cin>>n>>m>>k;
    vector<node>a(m+1);
    for(ll i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    vector<vector<ll>>r(k+1,vector<ll>(m+1));
    vector<ll>c(k+1);
    for(ll i=1;i<=k;i++){
            cin>>c[i];
        for(ll j=1;j<=n;j++)cin>>r[i][j];
    }
    solve(n,m,k,a,c,r);

    return 0;
}
