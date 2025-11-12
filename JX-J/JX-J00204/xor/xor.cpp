#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int a[N];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    int mx = -1;
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }

    if (n == 1) {
        cout << a[1];
    } else {
        cout << mx;
    }

    return 0;
}
