# include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N], s[N];
struct node {
    int l, r;
};
node b[N];
bool cmp(node x, node y) {
    if (x.l != y.l) {
        return x.l < y.l;
    }
    return x.r < y.r;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    bool flag = 0;
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != 1) {
            flag = 1;
        }
    }
    // A:1,3
    if (k == 0 && !flag) {
        printf("%d", n / 2);
        return 0;
    }
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = a[i] ^ s[i - 1];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int temp = s[i] ^ s[j - 1];
            if (temp == k) {
                b[++cnt].l = j;
                b[cnt].r = i;
            }
        }
    }
    sort(b + 1, b + cnt + 1, cmp);
    int ret = 0;
    int i = 1;
    while (i <= cnt) {
        int r = b[i].r;
        ret++;
        while (i <= cnt && b[i].l == b[i - 1].l) {
            i++;
        }
        while (b[i].l <= r && i <= cnt) {
            i++;
        }
    }
    printf("%d", ret);
    return 0;
}
