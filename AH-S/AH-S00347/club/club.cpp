#include<bits/stdc++.h>
using namespace std;

struct edge {
    int x, y;
};
int t;

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        int n;
        int ans = 0;
        edge b[100011], d[100011];
        for(int i = 0; i <= 100010; i++) {
            b[i].x = 0, b[i].y = 0;
        }
        int a[100011][4], c[100011], l, r;
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                scanf("%d", &a[i][j]);
                if(b[i].x < a[i][j]) {
                    b[i].x = a[i][j];
                    b[i].y = j;
                }
            }
            d[i].x = a[i][1] + a[i][2] + a[i][3] - b[i].x - min({a[i][1], a[i][2], a[i][3]});
            for(int j = 1; j <= 3; j++) {
                if(j !=  b[i].y && d[i].x == a[i][j]) {
                    d[i].y = j;
                    continue;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            ans += b[i].x;
            c[b[i].y]++;
        }
        for(int i = 1; i <= 3; i++) {
            if(c[i] > n / 2) {
                l = i;
                r = c[i];
            }
        }
        while(r > n / 2) {
            int L = 0, R = 0;
            int m = 1 << 30, I = 0;
            bool flag = false;
            for(int i = 1; i <= n; i++) {
                if(b[i].y != l) {
                    continue;
                }
                if(m > b[i].x - d[i].x) {
                    m = b[i].x - d[i].x;
                    L = b[i].x, R = d[i].x;
                    I = i;
                }
            }
            b[I].x = 1 << 30, d[I].x = 0;
            ans -= m;
            r--;
        }
        printf("%d \n", ans);
    }
}
