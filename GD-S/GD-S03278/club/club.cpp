#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int maxn = 1e5 + 5;
int n, a[maxn][3];
vector<int> v[3];

void solve(){
    for(int j : {0, 1, 2}){
        v[j].clear();
    }
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        vector<pii> tmp;
        for(int j : {0, 1, 2}){
            cin >> a[i][j];
            tmp.pb({a[i][j], j});
        }
        sort(tmp.begin(), tmp.end(), greater<pii>());
        ans += tmp[0].fi;
        v[tmp[0].se].pb(tmp[0].fi - tmp[1].fi);
    }
    for(int i : {0, 1, 2}){
        if((int)v[i].size() > n / 2){
            sort(v[i].begin(), v[i].end(), greater<int>());
            while((int)v[i].size() > n / 2){
                ans -= v[i].back();
                v[i].pop_back();
            }   
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t; while(t--) solve();

    return 0;
}