#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll t, n, ans;
vector<tuple<ll, ll, ll>> a;
map<pair<pair<ll, ll>, pair<ll, ll>>, ll> mp;
map<pair<pair<ll, ll>, pair<ll, ll>>, bool> vis;
void dfs(ll nod, ll cur, ll ca, ll cb, ll cc){
    // curnod, cursum, number of 1, number of 2, number of 3
    //<<nod<<' '<<cur<<' '<<ca<<' '<<cb<<' '<<cc<<endl;
    if(nod==n) {
        ans=max(ans, cur);
        return;
    }
    if (vis[{{nod, ca}, {cb, cc}}]==1){
        if(mp[{{nod, ca}, {cb, cc}}]<=cur) return;
    }
    vis[{{nod, ca}, {cb, cc}}]==1;
    mp[{{nod, ca}, {cb, cc}}]=cur;
    if(ca+1<=n/2){
        if(!vis[{{nod+1, ca+1}, {cb, cc}}]||
           vis[{{nod+1, ca+1}, {cb, cc}}]&&mp[{{nod+1, ca+1}, {cb, cc}}]<cur+get<0>(a[nod]))
           dfs(nod+1, cur+get<0>(a[nod]), ca+1, cb, cc);
    }
    if(cb+1<=n/2){
        if(!vis[{{nod+1, ca}, {cb+1, cc}}]||
           vis[{{nod+1, ca}, {cb+1, cc}}]&&mp[{{nod+1, ca}, {cb+1, cc}}]<cur+get<1>(a[nod]))
            dfs(nod+1, cur+get<1>(a[nod]), ca, cb+1, cc);
    }
    if(cc+1<=n/2){
        if(!vis[{{nod+1, ca}, {cb, cc+1}}]||
           vis[{{nod+1, ca}, {cb, cc+1}}]&&mp[{{nod+1, ca}, {cb, cc+1}}]<cur+get<2>(a[nod]))
            dfs(nod+1, cur+get<2>(a[nod]), ca, cb, cc+1);
    }
}
void dfss(ll nod, ll cur, ll ca, ll cb, ll cc){
    // curnod, cursum, number of 1, number of 2, number of 3
    //<<nod<<' '<<cur<<' '<<ca<<' '<<cb<<' '<<cc<<endl;
    if(nod==n) {
        ans=max(ans, cur);
        return;
    }
    if(ca+1<=n/2){
        dfss(nod+1, cur+get<0>(a[nod]), ca+1, cb, cc);
    }
    if(cb+1<=n/2){
        dfss(nod+1, cur+get<1>(a[nod]), ca, cb+1, cc);
    }
    if(cc+1<=n/2){
        dfss(nod+1, cur+get<2>(a[nod]), ca, cb, cc+1);
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    for(ll x=0; x<t; x++){
        cin>>n;
        ans=0;
        bool btwze=1, bthze=1;
        a.clear();
        a.resize(n);
        for(ll i=0 ; i<n; i++){
            ll a1, a2,a3;
            cin>>a1>>a2>>a3;
            if(a2!=0) btwze=0;
            if(a3!=0) btwze=0;
            a[i]={a1, a2, a3};
        }
        if(btwze&&bthze){
            sort(a.begin(), a.end());
            for(ll i=0; i<n/2; i++) ans+=get<0>(a[n-1-i]);
        }
        else if(btwze){
            sort(a.begin(), a.end());
            vector<ll> alar, blar;
            ll cnta=0, cntb=0, anss=0;
            for(ll i=0; i<n; i++){
                ll ta=get<0>(a[i]), tb=get<1>(a[i]);
                if(ta>tb)
                    alar.pb(i);
                else if(tb>ta)
                    blar.pb(i);
                else anss+=ta;
            }
            if(cnta<=n/2&&cntb<=n/2){
                for(ll i=0; i<n; i++){
                    ans+=max(get<0>(a[i]), get<1>(a[i]));
                }
            }
            //else{

            //}
        }
        else if(n<=10) dfss(0, 0, 0, 0, 0);
        else dfs(0, 0, 0, 0, 0);
        cout<<ans<<'\n';
    }
    return 0;
}
