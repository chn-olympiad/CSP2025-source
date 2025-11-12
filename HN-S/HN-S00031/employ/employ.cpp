#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 15;
int n, m, c[N], p[N], a[N];
string s;
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m >> s, s = ' ' + s;
    iota(p, p + 1 + n, 0);
    for(int i = 1; i <= n; i++) cin >> c[i];
    int ans = 0;
    do {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '0') cnt++;
            else if(cnt >= c[p[i]]) cnt++;
        }
        if(n - cnt >= m) ans++;
    } while(next_permutation(p + 1, p + 1 + n));
    cout << ans;
    return 0;
}