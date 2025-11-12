#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
struct Qujian {
    int l, r;
}s[N];
bool cmp1(Qujian x, Qujian y) {
    return x.r < y.r;
}

int a[N], n, k, m = 0;
int sum[N];
int cnt = 0;
int ha[1 << 20];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
        if (ha[sum[i]] == 0) ha[sum[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (ha[sum[i] ^ k]) {
            int l = i, r = ha[sum[i] ^ k] - 1;
            if (l > r) swap(l, r);
            s[++cnt] = {l , r};
        }
    }
    sort(s + 1, s + cnt + 1, cmp1);
    for (int i = 1; i <= cnt; i++) {
        cout << s[i].l << ' ' << s[i].r << endl;
    }
    int ans = 0, last = 0;
    for (int i = 1; i <= cnt; i++) {
        if (s[i].l > last) {
            last = s[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}