#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin>>n;
    ll a[n+5][4];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)cin>>a[i][j];
    }
    ll ans=0;
    vector<ll>shadan[4];
    for(int i=1;i<=n;i++){
        ll totmax=0;
        for(int j=1;j<=3;j++){
            totmax=max(totmax,a[i][j]);
        }
        ans+=totmax;
        for(int j=1;j<=3;j++){
            if(a[i][j]==totmax){
                shadan[j].push_back(i); break;
            }
        }
    }
    ll han=n/2;
    bool ok=1;
    for(int i=1;i<=3;i++){
        if(shadan[i].size()>han)ok=0;
    }
    if(ok){
        cout<<ans<<'\n'; return;
    }
    for(int i=1;i<=3;i++){
        if(shadan[i].size()>han){
            vector<ll>deltas;
            for(auto& u: shadan[i]){
                ll tkmax=0;
                for(int j=1;j<=3;j++){
                    if(j!=i){
                        tkmax=max(tkmax,a[u][j]);
                    }
                }
                deltas.push_back(a[u][i]-tkmax);
            }
            sort(deltas.begin(),deltas.end());
            ll changes=shadan[i].size()-han;
            for(int j=1;j<=changes;j++){
                ans-=deltas[j-1];
            }
            cout<<ans<<'\n'; return;
        }
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--)solve();   
}

/*
    g++ -std=c++2a -O2 club.cpp -o club && ./club
*/