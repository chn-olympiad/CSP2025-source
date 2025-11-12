#include <bits/stdc++.h>
#define int long long
#define P 998244353ll
using namespace std;

int n, res = 0;
vector<int> v(n + 1), vis(n + 1);

void dfs(int i) {
    if (i > n) {
        int sum = 0, mx = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) continue;
            sum += v[j];
            mx = max(mx, v[j]);
        }
        if (sum - mx <= mx) return ;
        res++;
        return ;
    }
    vis[i] = 1;
    dfs(i + 1);
    vis[i] = 0;
    dfs(i + 1);
}

int fpow(int a, int b) {
    int res = 1;
    for (;b /= 2;) {
        if (b % 2) res = res * a % P;
        a = a * a % P;
    }
    return res;
}

vector<int> fct, invf;
int C(int n, int m) {
    return fct[n] * invf[m] % P * invf[n - m] % P;
}

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    if (n > 20) {
        fct.resize(n + 1);
        invf.resize(n + 1);
        fct[0] = 1;
        for (int i = 1; i <= n; i++) fct[i] = fct[i - 1] * i % P;
        invf[n] = fpow(fct[n], P - 2);
        for (int i = n - 1; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % P;
        //cout << 12 * invf[3] << endl;
        int res = 0;
        for (int i = 3; i <= n; i++)
            res += C(n, i);
        cout << res;
        return 0;
    }
    v.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    dfs(1);
    cout << res;
    return 0;
}
