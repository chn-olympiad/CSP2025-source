#include<bits/stdc++.h>
#define FILE "club"
using namespace std;

namespace FakeWilson {
const int N = 1e5 + 5;
int a[N][8], num[15], tmp[15], d[N];
int p[N], byn[N], to[N], sq[N];

bool cmp(int x, int y) {
    return tmp[x] > tmp[y];
}

void get(int x) {
    tmp[1] = a[x][1], tmp[2] = a[x][2], tmp[3] = a[x][3];
    p[1] = 1, p[2] = 2, p[3] = 3;
    sort(p + 1, p + 1 + 3, cmp);
}

void solve() {
    int n;
    scanf("%d", &n);
    int ans = 0; num[1] = num[2] = num[3] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        get(i), num[p[1]]++;
        d[i] = a[i][p[1]] - a[i][p[2]];
        ans += a[i][p[1]];
        to[i] = p[1];
    }
    if(num[1] <= n / 2 && num[2] <= n / 2 && num[3] <= n / 2) {
        printf("%d\n", ans);
        return;
    }
    int cur = 0, cnt = 0;
    for(int i = 1; i <= 3; i++) if(num[i] > n / 2) cur = i;
    for(int i = 1; i <= n; i++) {
        if(to[i] != cur) continue;
        // cout << d[i] << " ";
        sq[++cnt] = d[i];
    }
    sort(sq + 1, sq + 1 + cnt);
    for(int i = 1; i <= (num[cur] - n / 2); i++) ans -= sq[i];
    printf("%d\n", ans);
}

signed main() {
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}

}

signed main() {
    freopen(FILE".in", "r", stdin);
    freopen(FILE".out", "w", stdout);
    return FakeWilson::main();
}

