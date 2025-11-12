#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[500005];
int s[500005];
int p[3000005];
struct node {
    int l, r;
    bool operator<(node b) const {
        if(r == b.r) return l > b.l;
        return r < b.r;
    }
} c[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= (1 << 20); ++i) p[i] = -1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]), s[i] = s[i - 1] ^ a[i];
        if(p[s[i] ^ k] != -1) { c[++m].l = p[s[i] ^ k] + 1; c[m].r = i; }
        p[s[i]] = i;
    }
    sort(c + 1, c + m + 1);
    int d = c[1].r, ans = 1;
    for(int i = 2; i <= m; ++i) {
        if(c[i].l > d) ++ans, d = c[i].r;
    }
    printf("%d\n", ans);
    return 0;
}
