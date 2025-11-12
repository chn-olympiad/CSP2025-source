#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout); 
#define ll long long
#define eb emplace_back
const int N = 1e5 + 5;
int a[N][3],n,ans;
vector<int>cnt[3];
inline int getse(int v){
    int minn = min({a[v][0],a[v][1],a[v][2]}), maxx = max({a[v][0],a[v][1],a[v][2]});
    return a[v][0] + a[v][1] + a[v][2] - minn - maxx;
}
int g[N],len;
inline void solve(){
    cin>>n; cnt[0].clear();cnt[1].clear();cnt[2].clear(); ans = len = 0;
    int m = n>>1; 
    for(int i=1;i<=n;i++) {
        cin>>a[i][0] >>a[i][1]>>a[i][2];
        int maxx = max({a[i][0],a[i][1],a[i][2]});
        if(maxx == a[i][0]) cnt[0].eb(i); 
        else if(maxx == a[i][1]) cnt[1].eb(i);
        else cnt[2].eb(i);
    }
    if((int)cnt[0].size() <= m && (int)cnt[1].size() <= m && (int)cnt[2].size() <= m){
        for(int v : cnt[0]) ans += a[v][0] ; 
        for(int v : cnt[1]) ans += a[v][1] ; 
        for(int v : cnt[2]) ans += a[v][2] ; 
        return cout<<ans<<'\n',void();
    }
    int id = 0;
    for(int i = 0; i < 3;i++) 
        if((int)cnt[i].size() > m) id = i;
    for(int v : cnt[id]) 
        g[++len] = getse(v) - a[v][id];
    stable_sort(g+1,g+len+1,greater<int>());
    for(int v : cnt[0]) ans += a[v][0] ; 
    for(int v : cnt[1]) ans += a[v][1] ; 
    for(int v : cnt[2]) ans += a[v][2] ;
    for(int i = 1;i<=(len - m);i++) ans += g[i];
    cout<<ans<<'\n';
}
signed main(){
    FILE("club");
    cin.tie(nullptr) -> sync_with_stdio(false);
    int T; cin>>T;
    while(T--) solve();
    return 0;
}