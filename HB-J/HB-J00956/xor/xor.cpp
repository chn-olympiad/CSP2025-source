#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 5e5 + 10;

int n, k, a[N], s[N][30], tmp[30], idx;
struct node {int l, r;} q[N * 20];
bool cmp(node a, node b) {return a.r != b.r ? a.r < b.r : a.l < b.l;}
int read() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    return x;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = read(); k = read();
    for (int i = 1; i <= n; i++) {
        int x = 0, cnt = 0;
        a[i] = read(), x = a[i];
        memset(tmp, 0, sizeof tmp);
        while (x) {
            tmp[++cnt] = x % 2;
            x >>= 1;
        }
        for (int j = 1; j <= 20; j++) 
            s[i][j] = s[i - 1][j] + tmp[j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            memset(tmp, 0, sizeof tmp);
            for (int k = 1; k <= 20; k++) {
                if ((s[j][k] - s[i - 1][k]) % 2) tmp[k] = 1;
                else tmp[k] = 0;
            }
            int w = 0, res = 0;
            for (int k = 1; k <= 20; k++) {
                res += int(pow(2, w)) * tmp[k];
                w++;
            }
            if (res == k) {
                q[++idx].l = i, q[idx].r = j;
            }
        }
    }
    sort(q + 1, q + idx + 1, cmp);
    int now = q[1].r, ans = 1;
    for (int i = 2; i <= idx; i++) 
        if (now < q[i].l) now = q[i].r, ans++;
    printf("%d", ans);
    return 0;
}