#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long LL;

const int N = 505, mod = 998244353;

int n, m;
char s[N];
int c[N];
int p[N];
int le[N];

void solve1() {
    for (int i = 1; i <= n; i ++ )
        if (s[i] == '0') {
            puts("0");
            return ;
        }
    int ans = 1;
    for (int i = 1; i <= n; i ++ ) ans = (LL) ans * i % mod;
    printf("%d\n", ans);
}

void solve2() {
    int ans = 0;
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for (int i = n; i; i -- ) le[i] = le[i + 1] + (s[i] == '0');
    do {
        int fl = 0;
        for (int i = 1; i <= n; i ++ ) {
            int now = p[i];
            if (fl >= c[now] || s[i] == '0')
                fl ++ ;
            if (n - fl - le[i + 1] < m) {
                fl = n;
                break;
            }
        }
        if (n - fl >= m) ans ++ ;
    } while (next_permutation(p + 1, p + n + 1));
    printf("%d\n", ans);
}

void solve3() {
    int ans = 1;
    for (int i = 1; i <= n; i ++ ) ans = (LL) ans * i % mod;
    printf("%d\n", ans);
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    bool flag = true;
    for (int i = 1; i <= n; i ++ ) if (s[i] == '0') {
        flag = false;
        break;
    }
    for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
    if (m == n) solve1();
    else if (flag) solve3();
    else solve2();
}