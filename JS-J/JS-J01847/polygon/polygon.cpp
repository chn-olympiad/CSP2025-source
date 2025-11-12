#include <bits/stdc++.h>
using namespace std;

#ifdef MYDBG
#define finout(filename) (void)0
#else
#define finout(filename) freopen(filename ".in", "r", stdin);    \
                         freopen(filename ".out", "w", stdout)
#endif

#define use_iostream() ios::sync_with_stdio(false);  \
                       cin.tie(nullptr);             \
                       cout.tie(nullptr)

long long n;
long long a[50001];

long long fast_pow(long long x, long long y) {
    // return x^y, just like the integer version of pow(x, y), but faster than it
    long long res = 0;
    while (y) {
        if (y & 1) {
            res += x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

long long endi;
long long dfs(long long starti, long long sum) {
    #ifdef MYDBG2
    cout << starti << ' ' << sum << endl;
    #endif
    long long ans = 0;
    for (long long i = starti; i < endi; ++i) {
        if (sum - a[i] < 0) {
            ans += fast_pow(2, endi - i) - 1;
            break;
        }
        ans += dfs(i + 1, sum - a[i]);
    }
    return ans;
}

int main() {

    finout("polygon");
    use_iostream();

    // input
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // program : [O(2 ^ n)?]
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        // the i is the max length in the next set(s)
        endi = i;
        ans += dfs(1, a[i]);
        ans %= 998244353;
        #ifdef MYDBG2
        cout << "outside:" << i << ' ' << ans << endl;
        #endif
    }

    // output
    cout << ans;

    cout << endl;
    return 0;
}