#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, k;
int a[N];
int lst[N];
int c[N];
map<int, int> mp;

struct Node {
    int l, r;
} v[N];

bool cmp (const Node &x, const Node &y) {
    return x.r < y.r;
}

int main () {
//    printf("use : %.10f\n", (sizeof(n) + sizeof(k) + sizeof(a) + sizeof(lst) + sizeof(c) + sizeof(mp) + sizeof(v)) / 1024. / 1024.);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] ^ a[i];
    mp[c[0]] = 0;
    int prexor = 0;
    memset(lst, 255, sizeof(lst));
    for (int i = 1; i <= n; i++) {
        if (mp.count(c[i] ^ k)) {
            lst[i] = mp[c[i] ^ k] + 1;
        }
        mp[c[i]] = i;
    }
    int len = 0;
    for (int i = 1; i <= n; i++) {
        if (lst[i] != -1) {
            v[++len].l = lst[i];
            v[len].r = i;
        }
    }
    sort(v + 1, v + len + 1, cmp);
    int R = 0;
    int ans = 0;
    int i = 1;
    for (; i <= len;) {
        while (R < v[i].l) {
            ans++;
            R = v[i].r;
            i++;
        }
        i++;
    }
    printf("%d\n", ans);
    return 0;
}
