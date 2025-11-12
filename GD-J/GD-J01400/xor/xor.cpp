#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = (1 << 21);
int n, k, s[N], f[N], mx[N];

signed main() {
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i], s[i] ^= s[i - 1];
    memset(mx, -0x3f, sizeof mx); f[0] = 0; mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], mx[s[i] ^ k] + 1);
        mx[s[i]] = max(mx[s[i]], f[i]);
    } cout << *max_element(f + 1, f + n + 1);
	return 0;
}