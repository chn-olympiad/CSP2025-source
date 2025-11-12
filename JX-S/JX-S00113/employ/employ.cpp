/*
    Author : Sparkle_ZH & Sparklee
    Right Output ! & Accepted !
*/

#include <bits/stdc++.h>
#define lowbit(x) ((x) & (- (x)))
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define ll long long
#define fir first
#define sec second
using namespace std;

template<typename T> inline void write(T x, int f = -1) {
    if (x < 0) putchar('-'), x = -x;
    static short Stack[50], top(0);
    do Stack[++ top] = x % 10, x /= 10; while (x);
    while (top) putchar(Stack[top --] | 48);
    if (~ f) putchar(f ? '\n' : ' ');
}

const int N = 505, P = 998244353;
int n, m, a[N];
char s[N];

void add(int &x, int y) { x = (x + y < P ? x + y : x + y - P); }

namespace method1 {
    int ans, f[1 << 18][19];

    void solve() {
        sort(a + 1, a + 1 + n);
        f[0][0] = 1;

        for (int i = 0; i < (1 << n) - 1; i ++) {
            int day = __builtin_popcount(i) + 1;
            for (int j = 0; j < day; j ++) {
                for (int k = 0; k < n; k ++) {
                    if ((1 << k) & i) continue ;
                    add(f[i | (1 << k)][j + (s[day] == '0' || a[k + 1] <= j)], f[i][j]);
                }
            }
        }

        for (int i = 0; i <= n - m; i ++)
            add(ans, f[(1 << n) - 1][i]);

        write(ans, 1);
    }
}

namespace method2 {
    void solve() {
        for (int i = 1; i <= n; i ++) {
            if (s[i] == '0' || ! a[i]) {
                puts("0");
                return ;
            }
        }

        ll ans = 1;
        for (int i = 1; i <= n; i ++)
            ans = ans * i % P;

        write(ans, 1);
    }
}

namespace method3 {
    void solve() {
        sort(a + 1, a + 1 + n);

        ll tot = 1, ans = 1;
        for (int i = 1; i <= n; i ++)
            tot = tot * i % P;

        int pos = 0, cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (s[i] == '0') continue ;
            while (pos < n && a[pos + 1] < i) pos ++;
            ans = ans * (pos - cnt) % P, cnt ++;
        }

        for (int i = 1; i <= n - cnt; i ++)
            ans = ans * i % P;

        write((tot - ans + P) % P, 1);
    }
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d %d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    if (n <= 18) method1::solve();
    else if (m == n) method2::solve();
    else method3::solve();


    return 0;
}
