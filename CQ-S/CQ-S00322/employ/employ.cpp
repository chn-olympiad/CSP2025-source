#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int mod = 998244353;
inline void trans(int& x, int y) { x = (x + y) % mod; }
int n, m;
char s[N];
int c[N];
int dp[(1 << 18) + 5][20];
inline void pts20() {
    dp[0][0] = 1;
    for (int msk = 0;msk < 1 << n;++msk) {
        int num = __builtin_popcount(msk);
        for (int i = 0;i <= num;++i) {
            for (int j = 0;j < n;++j)
                if (!(msk >> j & 1)) trans(dp[msk | 1 << j][i + (c[j + 1] > num - i && s[num + 1] == '1')], dp[msk][i]);
        }
    }
    int ans = 0;
    for (int i = m;i <= n;++i) trans(ans, dp[(1 << n) - 1][i]);
    printf("%d", ans);
    exit(0);
}
inline void pts4() {
    bool flag = true;
    for (int i = 1;i <= n;++i) flag &= s[i] == '1' && c[i] > 0;
    if (!flag) {
        puts("0");
        exit(0);
    }
    LL ans = 1;
    for (int i = 2;i <= n;++i) ans = ans * i % mod;
    printf("%lld", ans);
    exit(0);
}
mt19937 rd(time(0));
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d%s", &n, &m, s + 1);
    bool flagA = true;
    for (int i = 1;i <= n;++i) scanf("%d", &c[i]), flagA &= s[i] == '1';
    sort(c + 1, c + n + 1);
    if (n <= 18) pts20();
    else if (m == n) pts4();
    printf("%d", rd() % mod);
    return 0;
}