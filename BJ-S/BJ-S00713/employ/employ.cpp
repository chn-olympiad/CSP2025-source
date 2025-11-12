#include <bits/stdc++.h>
using namespace std;
constexpr int N = 555;
constexpr int mod = 998244353;
#define int long long
int n, m, a[N], cnt[N];
string s;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(m == 1) {
        int ans = 1;
        for(int i = 2; i <= n; i++) ans = ans * i % mod;
        cout << ans;
        return 0;
    }
    if(m == n) {
        cout << 1;
        return 0;
    }
    if(s[1] == '0') cnt[0] = 1;
    for(int i = 1; i < s.size(); i++) {
        cnt[i] = cnt[i - 1];
        if(s[i] == '0') cnt[i]++;
    }
    sort(a + 1, a + n + 1);
    int ans = 1;
    int c = 0;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '0') continue;
        int num = 0;
        for(int j = n; j >= 1; j--) {
            if(a[j] > cnt[i]) num++;
            else break;
        }
        ans = ans * (num - c) % mod;
        c++;
    }
    cout << ans;
    return 0;
}
