#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, a[MAXN][4], cnt[4];

void solve(){
    cin >> n; int ans = 0;
    priority_queue<pair<int, int>> q;
    cnt[1] = cnt[2] = cnt[3] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j : {1, 2, 3}) cin >> a[i][j];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
            cnt[1]++; ans += a[i][1];
            q.push({max(a[i][2], a[i][3]) - a[i][1], 1});
        }else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
            cnt[2]++; ans += a[i][2];
            q.push({max(a[i][1], a[i][3]) - a[i][2], 2});
        }else{
            cnt[3]++; ans += a[i][3];
            q.push({max(a[i][1], a[i][2]) - a[i][3], 3});
        }
    }
    if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) return cout << ans << '\n', void();
    int now = max({cnt[1], cnt[2], cnt[3]}) - n / 2;
    int pos = (cnt[1] >= cnt[2] && cnt[1] >= cnt[3] ? 1 : (cnt[2] >= cnt[1] && cnt[2] >= cnt[3] ? 2 : 3));
    while(now){
        auto x = q.top(); q.pop();
        if(x.second != pos) continue;
        ans += x.first, now--;
    }
    cout << ans << '\n';
}

signed main(){
    freopen("club.in", "r", stdin), freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >> T; while(T--) solve();

    return 0;
}