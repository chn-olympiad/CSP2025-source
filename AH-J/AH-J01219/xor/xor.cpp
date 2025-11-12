#include <bits/stdc++.h>
using namespace std;
int n, k, x[1919810], m, t, cnt;
struct node {
    int l, r;
} a[32000000];
bool cmp(node s, node b) {
    return s.r < b.r;
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i=1, p; i<=n; i++) {
        cin >> p;
        x[i] = x[i - 1] ^ p;
        for(int j=0; j<i; j++) {
            if((x[i] ^ x[j]) == k) {
                a[++ m].l = j + 1;
                a[m].r = i;
            }
        }
    }
    sort(a + 1, a + m + 1, cmp);
    for(int i=1; i<=m; i++) {
        if(a[i].l > t) {
            t = a[i].r;
            cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
