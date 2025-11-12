#include <bits/stdc++.h>

using namespace std;

int a[5001];
int sum = 0;

int e_op(int x) {
    if (x == 0) return 1;
    for (int i = 1; i < x; ++i) {
        x *= i;
    }
    return x;
}

int plzh(int m, int n) {
    return e_op(m) / e_op(m - n) / e_op(n);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    //freopen("polygon.out", "w", stdout);
    //freopen("polygon.in", "r", stdin);

    memset(a, 0, sizeof a);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        ++a[j];
        sum += j;
    }

    int numn = 0;
    for (int i = 1; i < 5001; ++i) {
        if (a[i] == 0) {
            continue;
        }
        --a[i];
        int maxn = i * 2;
        int dq = 0;
        int last = sum - maxn;
        if (last > maxn) {
            ++numn;
        } else {
            break;
        }
        for (int j = 1; j <= i; ++j) {
            int llen = a[j];
            if (llen == 0) continue;
            for (int n = 1; n <= a[j]; ++n) {
                if (last > maxn) {
                    numn += plzh(llen, dq);
                    ++dq;
                    last -= j;
                } else {
                    break;
                }
            }
            if (last > maxn) {
                numn += plzh(llen, dq);
            } else {
                break;
            }
        }
        ++a[i];
    }

    cout << numn;

    return 0;
}
