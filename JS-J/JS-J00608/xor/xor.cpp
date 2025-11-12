#include <bits/stdc++.h>

using namespace std;

int a[500000];

int n;
int k;
int maxres = -1;

void sol(int bac, int l) {
    int maxn = bac;
    for (int fr = l; fr < n; ++fr) {
        int last = 0;
        for (int to = fr; to < n; ++to) {
            last ^= a[to];
            if (last == k) {
                for (int hf = fr + 1; hf <= to; ++hf) {
                    sol(maxn, hf);
                }
                ++maxn;
                fr = to;
                break;
            }
        }

    }
    if (maxn > maxres) {
        maxres = maxn;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    freopen("xor.out", "w", stdout);
    freopen("xor.in", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sol(0, 0);
    cout << maxres;

    return 0;
}
