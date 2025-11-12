#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define ft first
#define sd second
#define pii pair <int, int>
#define ll long long
#define pb push_back
#define gmin(a, b) a = min(a, b)
#define gmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define debug cout << "------------------\n"
const int N = 1e5 + 10;
using namespace std;
int a[N][5], vis[N], cnt[5];
void solve() {
    int n; cin >> n;
    cnt[1] = cnt[2] = cnt[3] = 0;
    ll ans = 0;
    rep1(i, 1, n) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) vis[i] = 1, ans += a[i][1], ++cnt[1];
        else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) vis[i] = 2, ans += a[i][2], ++cnt[2];
        else if(a[i][3] >= a[i][2] && a[i][3] >= a[i][1]) vis[i] = 3, ans += a[i][3], ++cnt[3];
    }
    if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) return cout << ans << '\n', void();
    int id = 0;
    rep1(i, 1, 3) if(cnt[i] > n / 2) id = i;
    priority_queue <int> q;
    rep1(i, 1, n) if(vis[i] == id) {
        int mx = 0;
        rep1(j, 1, 3) if(j != id) gmax(mx, a[i][j]);
        q.push(mx - a[i][id]);
    }
    while(cnt[id] > n / 2) {
        int u = q.top(); q.pop();
        // cout << u << ' ' << cnt[id] << '\n';
        --cnt[id]; ans += u;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = 1; cin >> T;
    while(T--) solve();
    return 0;
}

/*
begin : 14:40

end : 14:52
*/