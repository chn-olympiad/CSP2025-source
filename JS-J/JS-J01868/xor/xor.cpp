#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const int M = 1e6 + 10;

ll n, k, idx, ans, cnt, a[N];
struct node {
    int l, r;
    bool vis;
}b[M];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if ((k == 0 || k == 1) && (a[i] == 0 || a[i] == 1)) cnt++;
    }
    if (n <= M && cnt != n) {
        for (int l = 1; l <= n; ++l) {
            ll sum = 0;
            for (int r = l; r <= n; ++r) {
                sum = sum ^ a[r];
                if (sum == k) b[++idx].l = l, b[idx].r = r, b[idx].vis = 0;
            }
        }
        ans = idx;
        for (int i = 1; i <= idx; ++i) {
            for (int j = 1; j <= idx; ++j) {
                if (i == j || b[j].vis || b[i].vis) continue;
                ll l_1 = b[i].l, r_1 = b[i].r;
                ll l_2 = b[j].l, r_2 = b[j].r;
                if ((r_1 >= l_2 && r_1 <= r_2) ||
                    (r_2 >= l_1 && r_2 <= r_1) ||
                    (l_1 >= l_2 && l_1 <= r_2) ||
                    (l_2 >= l_1 && l_2 <= r_1)) {
                        ans--;
                        if (r_1 - l_1 > r_2 - l_2) b[i].vis = 1;
                        else b[j].vis = 1;
                }
            }
        }
        cout << ans;
    }
    else {
        ans = 0;
        if (k == 0) {
            bool lst = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 0) ans++, lst = 0;
                else if (lst) ans++, lst = 0;
                else lst = 1;
            }
        }
        else for (int i = 1; i <= n; ++i) if (a[i] == 1) ans++;
        cout << ans;
    }
    return 0;
}
