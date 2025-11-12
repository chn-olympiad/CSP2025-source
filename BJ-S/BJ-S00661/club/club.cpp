#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long

using namespace std;

const int NR = 1e5 + 10;
ll a[NR][5];
int d[5][NR], sz[5];
int p[NR];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        sz[0] = sz[1] = sz[2] = 0;
        int n;
        scanf("%d", &n);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            int mx = 0;
            for(int j = 0; j < 3; j++) {
                scanf("%lld", &a[i][j]);
                if(a[i][j] > a[i][mx]) {
                    mx = j;
                }
            }
            d[mx][++sz[mx]] = i;
            ans += a[i][mx];
        }
        int tmp = -1;
        for(int i = 0; i < 3; i++) {
            if(sz[i] > n / 2) {
                tmp = i;
                break;
            }
        }
        if(tmp != -1) {
            for(int i = 1; i <= sz[tmp]; i++) {
                int u = d[tmp][i];
                p[i] = a[u][tmp] - max(a[u][(tmp + 1) % 3], a[u][(tmp + 2) % 3]);
            }
            sort(p + 1, p + 1 + sz[tmp]);
            int len = sz[tmp] - n / 2;
            for(int i = 1; i <= len; i++) {
                ans -= p[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
