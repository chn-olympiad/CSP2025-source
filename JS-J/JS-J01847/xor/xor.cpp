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

long long n, k;
long long a[500001];
long long pre[500001]; //< prefix xor sum (pre[i] is the prefix xor sum of [1, i])
long long pos[500001]; //< pos[i] : the xor sum of [pos[i], i] is k and
                       //< the pos[i] is the max num that match the condition
                       //< if no position match the condition, its value is 0
long long dp[500001];
/*
dp[i] : the max count when the right of the latest [] <= i

dp[i] = max(dp[i - 1], dp[pos[i]] + 1);

++i
*/

int main() {

    finout("xor");
    use_iostream();

    // input
    cin >> n >> k;
    for (long long i = 1; i <= n; ++i) {
        // input
        cin >> a[i];
        // subprogram(prepare the pre array)  [O(n)]
        pre[i] = pre[i - 1] ^ a[i];
    }

    // subprogram(prepare the pos array) [O(n^2)]
    for (long long i = 1; i <= n; ++i) {
        for (long long j = i; j > 0; --j) {
            if ((pre[i] ^ pre[j - 1]) == k) {
                pos[i] = j;
                break;
            }
        }
    }
    
    #ifdef MYDBG2
    for (long long i = 1; i <= n; ++i) {
        cout << pos[i] << ' ';
    }
    cout << endl;
    #endif

    // mainprogram : dp [O(n)]
    for (long long i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (pos[i] != 0) {
            dp[i] = max(dp[i], dp[pos[i] - 1] + 1);
        }
        #ifdef MYDBG2
        cout << dp[i] << ' ';
        #endif
    }

    // output
    cout << dp[n];

    cout << endl;
    return 0;
}