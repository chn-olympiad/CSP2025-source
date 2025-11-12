#include "bits/stdc++.h"
using namespace std;

const int N = 1e3;
int n, m;
pair<int, int> a[N];

inline int read() {
    int fa = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fa = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * fa;
}

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
    return A.first > B.first;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = read(), m = read();
    for (int i = 1; i <= m * n; i ++)
        a[i].first = read(), a[i].second = i;
    sort(a + 1, a + n * m + 1, cmp);
    for (int j = 1; j <= m; j ++) {
        if (j % 2 == 1)
            for (int i = 1; i <= n; i ++) {
                if (a[(j - 1) * n + i].second == 1) {
                    printf("%d %d", j, i);
                    return 0;
                }
            }
        else
             for (int i = n; i >= 1; i --) {
                if (a[(j - 1) * n + (n - i + 1)].second == 1) {
                    printf("%d %d", j, i);
                    return 0;
                }
            }
    }
}
