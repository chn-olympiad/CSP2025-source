#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll n, m, k, cost=0, ans;
bool b=1;
vector<ll> par, pa, c;
vector<tuple<ll, ll, ll>> a, idk;
vector<vector<tuple<ll, ll, ll>>> cc;
ll parr(ll n){
    if(par[n]==n) return n;
    else return par[n]=parr(par[n]);
}
ll nparr(ll n){
    if(pa[n]==n) return n;
    else return pa[n]=nparr(pa[n]);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    par.resize(n+1);
    pa.resize(n+k+1);
    c.resize(k);
    cc.resize(k);
    for(ll i=1; i<=n; i++) par[i]=i;
    for(ll i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        a.pb({w, u, v});
    }
    if(k==0){
        sort(a.begin(), a.end());
        for(ll i=0; i<m; i++){
            tuple<ll, ll, ll> tm=a[i];
            ll aa=get<1>(tm), bb=get<2>(tm);
            ll para=parr(aa), parb=parr(bb);
            if(para==parb) continue;
            cost+=get<0>(tm);
            if(para>parb) par[para]=parb;
            else par[parb]=para;
        }
        cout<<cost<<"\n";
        return 0;
    }
    //ans=cost;
    idk=a;
    for(ll i=1; i<=n+k; i++) pa[i]=i;
    for(ll i=0; i<k; i++){
        cin>>c[i];
        if(c[i]!=0) b=0;
        for(ll j=0; j<n; j++){
            ll w; cin>>w;
            if(w==0&&c[i]==0){
                ll para=nparr(j+1), parb=nparr(i+n+1);
                if(para==parb) continue;
                if(para>parb) pa[para]=parb;
                else pa[parb]=para;
            }
            cc[i].pb({w, j+1, i+n+1});
            idk.pb({w, j+1, i+n+1});
        }
        sort(cc[i].begin(), cc[i].end());
    }
    if(b){
        cost=0;
        sort(idk.begin(), idk.end());
        for(ll i=0; i<idk.size(); i++){
            tuple<ll, ll, ll> tm=idk[i];
            ll aa=get<1>(tm), bb=get<2>(tm);
            ll para=nparr(aa), parb=nparr(bb);
            if(para==parb) continue;
            cost+=get<0>(tm);
            if(para>parb) pa[para]=parb;
            else pa[parb]=para;
        }
        cout<<cost<<'\n';
        return 0;
    }
    else{
        cost=0;
        sort(a. begin(), a.end());
        for(ll i=0; i<m; i++){
            tuple<ll, ll, ll> tm=a[i];
            ll aa=get<1>(tm), bb=get<2>(tm);
            ll para=parr(aa), parb=parr(bb);
            if(para==parb) continue;
            cost+=get<0>(tm);
            if(para>parb) par[para]=parb;
            else par[parb]=para;
        }
        ans=cost;
    }
    cout<<ans<<'\n';
    return 0;
}
