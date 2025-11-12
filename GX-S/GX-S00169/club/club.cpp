#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
typedef pair<int, int> pii;
namespace tianyu{
    int n;
    ll a[N][3];
namespace nnn{
    ll dp[205][205], ans;
    void solve(){
        ans = 0;
        for (int i = 1;i <= n;i++){
            ans += a[i][0];
            a[i][1] -= a[i][0];
            a[i][2] -= a[i][0];
        }
        for (int i = 0;i <= n / 2;i++){
            for (int j = 0;j <= n / 2;j++){
                dp[i][j] = -1e16;
            }
        }
        dp[0][0] = 0;
        for (int i = 1;i <= n;i++){
            for (int j = n / 2;j >= 0;j--){
                for (int k = n / 2;k >= 0;k--){
                    if (j) dp[j][k] = max(dp[j][k], dp[j - 1][k] + a[i][1]);
                    if (k) dp[j][k] = max(dp[j][k], dp[j][k - 1] + a[i][2]);
                }
            }
        }
        ll mx = -1e16;
        for (int j = 0;j <= n / 2;j++){
            for (int k = 0;k <= n / 2;k++){
                if (j + k >= n / 2) mx = max(mx, dp[j][k]);
            }
        }
        cout << ans + mx << '\n';
    }
}
namespace sub2{
    ll ans, b[N];
    void solve(){
        ans = 0;
        for (int i = 1;i <= n;i++) b[i] = a[i][0];
        sort(b + 1, b + 1 + n, greater<ll>());
        for (int i = 1;i <= n / 2;i++) ans += b[i];
        cout << ans << '\n';
    }
}
namespace sub3{
    ll ans;
    priority_queue<ll> pq;
    void solve(){
        ans = 0;
        while (pq.size()) pq.pop();
        for (int i = 1;i <= n;i++){
            ans += a[i][0];
            pq.emplace(a[i][1] - a[i][0]);
        }
        for (int i = 1;i <= n / 2;i++){
            ans += pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
}
    void awa(){
        cin >> n;
        for (int i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (n <= 200) return nnn::solve();
        bool FFF = 1;
        for (int i = 1;i <= n;i++){
            if (a[i][2]) FFF = 0;
        }
        if (FFF) return sub3::solve();
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--) tianyu::awa();
    return 0;
}
/*
froepen

zhe sha a?????
wo zen me bu hui T1
fa xian B = zheng jie???
nononono
oh no
wo yao fei le???????????
wo bu hui mei qu nian gao ba
/fn/fn/fn/fn/fn/fn/fn/fn/fn/fn/fn
wo yao na gou 7!!!!!!!!!!!!!!!!!!
xiang xin wo bu hui de bie ren ye bu hui
qwq

70+72+50+24=216

plzplzplzplzplzplzplzplzplzplz

rang wo na gou 7 ba qwq

*/