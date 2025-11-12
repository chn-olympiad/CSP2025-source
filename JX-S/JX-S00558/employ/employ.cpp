#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, m, c[505], p[505], ans, flg = 1, cnt;
string s;
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) if (s[i] == '0') flg = 0;
    for (int i = 1; i <= n; i++) cin >> c[i], p[i] = i, cnt += (bool)c[i];
    if (flg){
        if (cnt < m) cout << 0;
        return 0;
    }
    do {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++){
            if (cnt0 >= c[p[i]]) cnt0++;
            else if (s[i] == '0') cnt0++;
            else cnt1++;
        }
        if (cnt1 >= m){
            ans++;
        }
    } while (next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}
