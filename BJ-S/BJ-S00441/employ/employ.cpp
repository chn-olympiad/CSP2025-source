#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 510;
const int P = 998244353;
int n, m, c[maxn];
bool s[maxn];
namespace pts_1_2 {
    bool check() { return n <= 10; }
    void work() {
        int a[n + 1], res = 0;
        for (int i = 1; i <= n; i++) a[i] = i;
        do {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (s[i] == 0 || cnt >= c[a[i]]) cnt++;
            if (n - cnt >= m) res++;
        } while (next_permutation(a + 1, a + n + 1));
        cout << res << "\n";
        exit(0);
    }
}
// namespace pts_A {
//     bool check() {
//         int sum = 0;
//         for (int i = 1; i <= n; i++) sum += s[i];
//         return sum == n;
//     }
//     void work {
        
//     }
// }
signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        char ch = getchar();
        s[i] = ch - '0';
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    if (pts_1_2::check()) pts_1_2::work();
    return 0;
}

// 8 pts