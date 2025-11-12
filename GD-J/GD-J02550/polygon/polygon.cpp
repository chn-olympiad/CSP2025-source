#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = 998244353;

int n;
int a[N];

long long f[N * 2];

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    int lim = N * 2 - 1;
    long long ans = 0;

    f[min(a[1] + a[2], lim)] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = lim; j >= 0; j--) {
            if(j + a[i] > a[i] * 2) ans = (ans + f[j]) % mod;
        }

        for(int j = lim; j >= 0; j--) {
            f[min(j + a[i], lim)] = (f[min(j + a[i], lim)] + f[j]) % mod;   
        }

        for(int j = i - 1; j >= 1; j--) {
            f[min(a[i] + a[j], lim)] = (f[min(a[i] + a[j], lim)] + 1) % mod;
        }
    }

    cout << ans << '\n';
}