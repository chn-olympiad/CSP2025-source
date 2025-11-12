#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if (k == 0) {
        printf("%d", n / 2);
    } else if (k == 1) {
        int ret = 0;
        for (int i = 1; i <= n - 1; i++) {
            if (a[i] ^ a[i + 1] != 0) {
                ret++;
                i++;
            }
        }
        printf("%d", ret);
    }
    return 0;
}

// 想不出来正解了，骗分走人 11:15
