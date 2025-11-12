#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 5e2+5;
namespace tianyu{
    int n, m;
    string s;
    int a[N];
namespace nfac{
    int p[N], b[N];
    void solve(){
        for (int i = 1;i <= n;i++) p[i] = i;
        int ans = 0;
        do{
            for (int i = 1;i <= n;i++) b[i] = a[p[i]];
            int cnt = 0, c = 0;
            for (int i = 1;i <= n;i++){
                if (c >= b[i] || s[i] == '0'){
                    ++c;
                }
                else ++cnt;
            }
            if (cnt >= m) ++ans;
        }while (next_permutation(p + 1, p + 1 + n));
        cout << ans;
    }
}
namespace m1{
    const ll P = 998244353;
    ll ans, cnt[N];
    void solve(){
        for (int i = 1;i <= n;i++) ++cnt[a[i]];
        for (int i = 1;i <= n;i++) cnt[i] += cnt[i - 1];
        ans = 1;
        int c = 0;
        for (int i = 1;i <= n;i++){
            if (s[i] == '1'){
                ans = ans * (cnt[i - 1] - c) % P;
                ++c;
            }
        }
        for (int i = 1;i <= n - c;i++) ans = ans * i % P;
        ll res = 1;
        for (int i = 1;i <= n;i++) res = res * i % P;
        res = (res - ans + P) % P;
        cout << res;
    }
}
namespace mn{
    const ll P = 998244353;
    void solve(){
        for (int i = 1;i <= n;i++){
            if (s[i] == '0' || a[i] == 0){
                cout << 0;
                return;
            }
        }
        ll res = 1;
        for (int i = 1;i <= n;i++) res = res * i % P;
        cout << res;
    }
}
    void awa(){
        cin >> n >> m >> s;
        s = ' ' + s;
        for (int i = 1;i <= n;i++) cin >> a[i];
        if (n <= 10) nfac::solve();
        if (m == 1) m1::solve();
        if (n == m) nm::solve();
        
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int T = 1;
    while (T--) tianyu::awa();
    return 0;
}
/*
hyw
he yi wei
?????????????
qwq
qwq
qwq
qwq
qwq
qwq
qwq
*/