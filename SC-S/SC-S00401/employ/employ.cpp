#include <bits/stdc++.h>
#define int long long
const int MAXN = 520;
const int MOD = 998244353;
namespace calc {
    int add(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
    int mul(int x, int y) { return (x * y) % MOD; }
} using namespace calc;

int n, m;
std::string str;
int c[MAXN], s[MAXN];
int p[11];

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    std::cin >> str;
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    
    bool subtaskA = true;
    for (int i = 0; i < str.length(); i++) s[i + 1] = str[i] - '0', subtaskA &= (s[i + 1] == 1);
    
    if (n <= 10) {
        for (int i = 1; i <= n; i++) p[i] = i;
        int ans = 0;
        do {
            int kill = 0, eat = 0;
            for (int i = 1; i <= n; i++) {
                if (kill >= c[p[i]]) { kill++; continue; }
                if (s[i]) eat++;
                else kill++;
            }
            if (eat >= m) ans++;
        } while (std::next_permutation(p + 1, p + n + 1));
        printf("%lld", ans);
    } else if (subtaskA) {
        int fac = 1;
        for (int i = 1; i <= n; i++) fac = mul(fac, i);
        printf("%lld", fac);
    }
    
    return 0;
}