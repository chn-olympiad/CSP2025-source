#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long

using namespace std;

const int NR = 510;
const int mod = 998244353;
bool s[NR];
int c[NR];
int n, m;
ll ans = 0;
bool vis[NR];

void dfs(int u, int cnt) {
    if(u > n) {
        //printf("%d %d\n", u, cnt);
        if(n - cnt >= m) ans++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        int tmp = 0;
        if(cnt >= c[i] || !s[u]) tmp = 1;
        dfs(u + 1, cnt + tmp);
        vis[i] = false;
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        char x;
        scanf(" %c", &x);
        //printf("! %c\n", x);
        if(x == '1') s[i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    if(n > 12) {
        puts("0");
        return 0;
    }
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}
