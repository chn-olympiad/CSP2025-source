#include<bits/stdc++.h>
#define FILE "employ"
using namespace std;

namespace FakeWilson {
const int mod = 998244353;
const int N = 505;
char s[N];
int c[N];

signed main() {
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if(x == 0) {puts("0"); return 0;}
    }
    for(int i = 1; i <= n; i++) if(s[i] == '0') {puts("0"); return 0;}
    int ans = 1;
    for(int i = 1; i <= n; i++) ans = 1LL * ans * i % mod;
    printf("%d", ans);
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}

