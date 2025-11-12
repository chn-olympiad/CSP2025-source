/**
 * @brief CSP-S 2025
 *        Problem D. employ
 * @author BJ-S00244    liuli688
*/
#include <bits/stdc++.h>
using std::cin;
using std::cout;
using ll = long long;

const int N = 510, MOD = 998244353;
int n, m, c[N], p[30];
char s[N];

bool A = true, B = true;
ll f[N][N][2];

ll qpow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1, a = a * a % MOD)
        if (b & 1)
            res = res * a % MOD;
    return res;
}

int main(int argc, const char *argv[]) {
	cin.tie(nullptr) -> sync_with_stdio(false);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
	cin >> n >> m;
	char* s1 = s + 1;
	cin >> s1;
	for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1, one = 0; i <= n; ++i) {
        one += (s[i] -= 48);
        if (one < i)
            A = false;
        if (one > 18)
            B = false;
    }
    //A = false;
    if (A) {
        cout << "0\n";
        return 0;
    //} else if (B) {

    } else {
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
            p[i] = i;
            int cnt = 0;
        do {
            int fail = 0;
            for (int i = 1; i <= n; ++i)
                if (fail >= c[p[i]] || s[i] == 0)
                    ++fail;
            if (fail <= n - m)
                ++ans;
            if (ans >= MOD)
                ans -= MOD;
            ++cnt;
        } while (std::next_permutation(p + 1, p + n + 1));
        cout << ans << '\n';
    }
	return 0;
}

/**
 * 就这样结束了。
 * [0, 100] + [72, 100] + 0 + 10 = [82, 210]
 * 可谓毫无容错。
 * 但是

 > 即使诞于沉寂最终消融于颓圮 今天的我仍将继续
*/
