#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using vint = vector<int>;
using pii = pair<int,int>;
void solve(){
    int n;
    cin >> n;
    vector<tuple<int,int,int,int>> all(3 * n);
    vector<bool> vis(n);
    for(int i = 0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        all[3*i] = {a-max(b,c),a,i,1};
        all[3*i+1] = {b-max(a,c),b,i,2};
        all[3*i+2] = {c-max(a,b),c,i,3};
    }
    array<int,4> cnt{};
    sort(all.begin(),all.end(),greater<>());
    int ans = 0;
    for(auto [_,v,id,to]:all){
        if(!vis[id] && (cnt[to]<n/2)){
            ans += v;
            cnt[to]++;
            vis[id]=true;
        }
    }
    cout << ans << endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
