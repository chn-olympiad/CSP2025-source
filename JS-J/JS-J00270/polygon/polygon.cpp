#include "bits/stdc++.h"
#define int long long
using namespace std;

const int N = 5 * 1e5 + 10, P = 998244353;
int n, a[N], b[N], ans;

bool cmp(const int &A, const int &B) {
    return A > B;
}

inline void dfs(int i, int sum, int ma, int nu) {
    if (sum > ma * 2 && nu >= 3) {
        ans = (ans + 1) % P;
    }
    for (int j = i; j <= n; j ++) {
        if (!b[j]) {
            b[j] = 1;
            dfs(j + 1, sum + a[j], max(ma, a[j]), nu + 1);
            b[j] = 0;
        }
    }
}

inline int read() {
    int fa = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fa = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * fa;
}e

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i ++)
        a[i] = read();
    sort(a + 1, a + n + 1, cmp);
    dfs(1, 0, 0, 0);
    printf("%lld", ans);
}
