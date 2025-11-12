#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;
const ll maxn = 1e5 + 5;
ll t, n, a[maxn][3], ans, b[maxn], mx, cnt[3];
multiset <ll> s;
void solve(){
    cnt[1] = cnt[2] = cnt[3] = 0;
    s.clear();
    ans = 0;
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        mx = max(a[i][1], max(a[i][2], a[i][3]));
        if(mx == a[i][1]) b[i] = 1, cnt[1]++;
        else if(mx == a[i][2]) b[i] = 2, cnt[2]++;
        else b[i] = 3, cnt[3]++;
        ans += mx;
    }
    if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2){
        cout << ans << '\n';
        return;
    }
    if(cnt[2] > n / 2){
        mx = 2;
        for(ll i = 1; i <= n; ++i) swap(a[i][1], a[i][2]);
    } else if(cnt[3] > n / 2){
        mx = 3;
        for(ll i = 1; i <= n; ++i) swap(a[i][1], a[i][3]);
    } else mx = 1;
    for(ll i = 1; i <= n; ++i)
        if(b[i] == mx) s.insert(a[i][1] - max(a[i][2], a[i][3]));
    for(ll i = 1; i <= cnt[mx] - n / 2; ++i){
        ans -= (*s.begin());
        s.erase(s.begin());
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for(; t; --t) solve();
    return 0;
}
