#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 10;
const int MOD = 998244353;
    
int n, m;
int c[N], p[N], flag[N];
string s;

bool chk() {
    int wlq = 0, fq = 0;
    for (int i = 1; i <= n; ++i) {
        if (wlq >= c[p[i]]) 
            fq++;
        else if (s[i - 1] == '0')
            wlq++;
    }
    return ((n - wlq - fq) >= m); 
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) p[i] = i;
    int ans = 0;
    ans += chk();
    while (next_permutation(p + 1, p + n + 1)) {
        int wlq = 0, fq = 0;
        for (int i = 1; i <= n; ++i) {
            if (wlq + fq >= c[p[i]]) 
                fq++;
            else if (s[i - 1] == '0')
                wlq++;
        }
        if (n - wlq - fq >= m) 
            ans = (ans + 1) % MOD;   
    }
    cout << ans << endl;
    return 0;
}