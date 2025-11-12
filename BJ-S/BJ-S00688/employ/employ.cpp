#include <bits/stdc++.h>
using namespace std;
#define inlfc __attribute__((always_inline))
typedef long long ll;
typedef pair<int, int> pii;

const int P = 998244353;

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    if (n <= 10) {
        int ans = 0;
        int a[105];
        for (int i = 1; i <= n; i ++) {
            a[i] = i;
        }
        while(next_permutation(a + 1, a + n + 1)) {
            int x = 0;
            for (int i = 1; i <= n; i ++) {
                if (c[a[i]] < i) continue;
                if (s[i]) x ++;
            }
            if (x >= m) ans ++;
        }
        cout << ans;
    } else {
        cout << 0;
    }
    return 0;
}
