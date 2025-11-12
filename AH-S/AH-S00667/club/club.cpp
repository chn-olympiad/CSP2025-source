#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define ll long long

const int N = 100005;
int a[N], b[N], c[N];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int cnta = 0, cntb = 0, cntc = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if (x >= y && x >= z) {
                ans += x;
                a[++cnta] = x - max(y, z);
            } else if (y >= z && y >= x) {
                ans += y;
                b[++cntb] = y - max(x, z);
            } else {
                ans += z;
                c[++cntc] = z - max(x, y);
            }
        }

        if (cnta > n / 2) {
            sort(a + 1, a + 1 + cnta);
            for (int i = 1; i <= cnta - n / 2; i++) {
                ans -= a[i];
            }
        } else if (cntb > n / 2) {
            sort(b + 1, b + 1 + cntb);
            for (int i = 1; i <= cntb - n / 2; i++) {
                ans -= b[i];
            }
        } else if (cntc > n / 2) {
            sort(c + 1, c + 1 + cntc);
            for (int i = 1; i <= cntc - n / 2; i++) {
                ans -= c[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}