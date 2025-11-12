/*
Author: Shunpower in CSP-S2025

我感到 soul cries
灵魂被 sold out
但不会懈怠 腐烂被嗅到
炙热的心才是最好解药
2025AMBITION with my freestyle
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fr1(i,a,b) for(int i=(a);i<=(b);i++)
#define fr2(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;
const int N=1e5+10;
int n;
int a[N][4];
vector <int> id[4];
int tc;
void solve(){
    fr1(i,1,3) id[i].clear();
    cin>>n;
    fr1(i,1,n) fr1(j,1,3) cin>>a[i][j];
    ll ans=0;
    fr1(i,1,n){
        int pos=max_element(a[i]+1,a[i]+4)-a[i];
        ans+=a[i][pos];
        id[pos].pb(i);
    }
    int szmx=0;
    fr1(i,1,3){
        if(id[i].size()>id[szmx].size()) szmx=i;
    }
    // cout<<"!"<<ans<<endl;
    if(id[szmx].size()>n/2){
        int rem=id[szmx].size()-n/2;
        vector <int> dif;
        for(auto i:id[szmx]){
            int maxn=0;
            fr1(j,1,3){
                if(j!=szmx) maxn=max(maxn,a[i][j]);
            }
            dif.pb(maxn-a[i][szmx]);
        }
        sort(dif.begin(),dif.end(),greater<int>());
        fr1(i,0,rem-1) ans+=dif[i];
    }
    cout<<ans<<'\n';
}
#define shun cute
int main(){
#ifdef shun
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>tc;
    while(tc--) solve();
    // cerr<<clock()<<endl;
    return 0;
}
/*
注意只考到18:30
last 15min, NOI Linux for big samples
never stop thinking
Stage 9
冷静。冷静。冷静。

g++ -O2 -std=c++14 club.cpp -o club
*/