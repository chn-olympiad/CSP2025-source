#include<bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
#ifndef LOCAL
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
#endif

    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    vector<int> f(n + 1), g(1 << 20, -1);
    g[0] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if(g[s[i] ^ k] != -1) {
            f[i] = max(f[i], g[s[i] ^ k] + 1);
        }
        g[s[i]] = f[i];
    }

    cout << f[n] << '\n';

    return 0;
}
// 9:06