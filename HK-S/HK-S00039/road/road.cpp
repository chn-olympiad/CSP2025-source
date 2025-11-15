#include <bits/stdc++.h>
#define ll long long
//#define pb push_back
//#define pp pair<ll, ll>
//#define tp tuple<ll, ll, ll>
using namespace std;
ll n, m, k, u, v, w, sum=0;
vector<vector<pair<ll, ll>>> r, add;
vector<ll> d, pre, vis;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    r.resize(n), d.resize(n), pre.resize(n), vis.resize(n);
    for(ll i=0; i<m; i++){
        cin>>u>>v>>w;
        u--, v--;
        r[u].push_back({v, w});
        r[v].push_back({u, w});
    }
    if(k==0){
        for(ll i=0; i<n; i++) d[i]=1e18, pre[i]=0, vis[i]=0;
        d[0]=0;
        priority_queue<vector<pair<ll, ll>>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            ll u=pq.top().second;
            pq.pop();
            vis[u]=1;
            for(ll i=0; i<r[u].size(); i++){
                ll v=r[u][i].first, w=r[u][i].second;
                if(vis[v]) continue;
                //cout<<u<<" "<<v<<" "<<d[u]<<" "<<d[v]<<" "<<w<<" "<<pre[v]<<" "<<sum<<endl;
                if(d[v]>d[u]+w){
                    sum=sum-pre[v]+w;
                    pre[v]=w;
                    d[v]=d[u]+w;
                    pq.push({d[v], v});
                }
            }
        }
        //cout<<d[n-1]<<endl;
        cout<<sum<<endl;
        return 0;
    }
    ll c[n]={}, a[k][n]={};
    for(ll o=0; o<k; o++){
        cin>>c[o];
        for(ll i=0; i<n; i++) cin>>a[o][i];
        for(ll i=0; i<n; i++){
            for(ll j=i+1; j<n; j++){
                r[i].push_back({j, a[o][i]+a[o][j]});
                r[j].push_back({i, a[o][i]+a[o][j]});
            }
        }
    }
    for(ll i=0; i<n; i++) d[i]=1e18, pre[i]=0, vis[i]=0;
    d[0]=0;
    priority_queue<vector<pair<ll, ll>>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll u=pq.top().second;
        pq.pop();
        vis[u]=1;
        for(ll i=0; i<r[u].size(); i++){
            ll v=r[u][i].first, w=r[u][i].second;
            if(vis[v]) continue;
            //cout<<u<<" "<<v<<" "<<d[u]<<" "<<d[v]<<" "<<w<<" "<<pre[v]<<" "<<sum<<endl;
            if(d[v]>d[u]+w){
                sum=sum-pre[v]+w;
                pre[v]=w;
                d[v]=d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
    //cout<<d[n-1]<<endl;
    cout<<sum<<endl;
    return 0;
}
