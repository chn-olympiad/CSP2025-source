#include <bits/stdc++.h>
using namespace std;

struct node {
    int l;
    int r;
} b[500005];
bool cmp(node ax, node by) {
    return (ax.l == by.l ? ax.r < by.r : ax.l < by.l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, same, a[500005];
    cin >> n >> same;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int d = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int z = 0;
            for (int k = i; k <= j; k++) z ^= a[k];
            if (z == same) b[++d] = {i, j};
        }
    }
    sort(b + 1, b + d + 1, cmp);
    int ans = 1, lt = b[1].l, rt = b[1].r;
    for (int i = 2; i <= d; i++) {
        if (b[i].l > rt) {
            ans++;
            lt = b[i].l;
            rt = b[i].r;
        }
    }
    cout << ans;
    return 0;
}
