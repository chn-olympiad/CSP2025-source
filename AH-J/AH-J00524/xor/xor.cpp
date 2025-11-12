#include<bits/stdc++.h>
using namespace std;

struct edge {
    int l, r;
} c[600000];

int n, k, tot, h, jian;
int a[600000], d[600000];
long long b[600000];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    memset(d, 0, sizeof(d));
    scanf("%d%d", &n, &k);
    b[0] = 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] ^ a[i];
    }
    for(int x = 1; x <= n; x++) {
        for(int y = x; y <= n; y++) {
            int m = b[y] ^ b[x - 1];
            if(m == k) {
                c[++tot].l = x;
                c[tot].r = y;
                if(d[x] > 0) {
                    if(y <= c[d[x]].r) {
                        int v = d[x];
                        for(int u = c[v].l; u <= c[v].r; u++) {
                            d[u] = 0;
                            if(u >= x && u <= y) {
                                d[u] = tot;
                            }
                        }
                        jian++;
                    }
                    else {
                        tot--;
                    }
                }
                else {
                    for(int i = x; i <= y; i++) {
                        d[i] = tot;
                    }
                }
                break;
            }
        }
    }
    printf("%d\n", tot - jian);
    return 0;
}
