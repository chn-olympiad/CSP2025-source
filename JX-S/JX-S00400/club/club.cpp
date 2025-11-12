#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, l, r) for(int i = (r); i >= (l); i--)
#define FRE(NAME) freopen(NAME".in", "r", stdin), freopen(NAME".out", "w", stdout);
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;
using i32 = int32_t;
using i64 = int64_t;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (5, 0));
    rep(i, 1, n){ rep(j, 1, 3) cin >> a[i][j]; }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int ans = 0;
    vector<int> res1, res2, res3;
    rep(i, 1, n){
        int now = max({a[i][1], a[i][2], a[i][3]});
        if(a[i][1] == now) cnt1++, res1.pb(min(now - a[i][2], now - a[i][3]));
        else if(a[i][2] == now) cnt2++, res2.pb(min(now - a[i][1], now - a[i][3]));
        else cnt3++, res3.pb(min(now - a[i][1], now - a[i][2]));
        ans += now;
    }
    sort(res1.begin(), res1.end()), sort(res2.begin(), res2.end()), sort(res3.begin(), res3.end());
    if(res1.size() > n / 2){
        int add = res1.size() - n / 2;
        rep(i, 0, add - 1) ans -= res1[i];
    }else if(res2.size() > n / 2){
        int add = res2.size() - n / 2;
        rep(i, 0, add - 1) ans -= res2[i];
    }else if(res3.size() > n / 2){
        int add = res3.size() - n / 2;
        rep(i, 0, add - 1) ans -= res3[i];
    }
    cout << ans << endl;
}

i32 main(){
    FRE("club");
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}

/*
g++ club.cpp -o club -Wall -Wextra -O2 -g3 -DQwQ
./club
*/