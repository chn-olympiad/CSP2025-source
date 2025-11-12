#include <bits/stdc++.h>

#define fst first
#define snd second

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using ld = long double;
using namespace std;
const int N = 15, M = 15;
int n, m, t;
int a[N * M], mp[N][M];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    t = a[1];
    sort(a + 1, a + 1 + n * m, greater <int> ());
    for (int i = 1; i <= n * m; i++) {
        if ((i + n - 1) / n % 2) mp[(i - 1) % n + 1][(i + n - 1) / n] = a[i];
        else mp[n - (i - 1) % n][(i + n - 1) / n] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == t) return cout << j << ' ' << i, 0;
        }
    }
    return 0;
}