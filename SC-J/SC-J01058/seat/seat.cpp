#include <cstdio>
#include <algorithm>
using namespace std;
struct IO {
    IO () {
        freopen("seat.in", "r", stdin);
        freopen("seat.out", "w", stdout);
    }
    ~IO () {
        fclose(stdin);
        fclose(stdout);
    }
} io;
const int N = 109;
int n, m;
struct Node {
    int val, idx;
    bool operator < (const Node &rhs) const {
        return val > rhs.val;
    }
} a[N];
int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++)
        scanf("%d", &a[i].val), a[i].idx = i;
    sort(a + 1, a + n * m + 1);
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
        if (j & 1) {
            for (int i = 1; i <= n; i++) {
                ++cnt;
                if (a[cnt].idx == 1) {
                    printf("%d %d\n", j, i);
                    return 0;
                }
            }
        } else {
            for (int i = n; i >= 1; i--) {
                ++cnt;
                if (a[cnt].idx == 1) {
                    printf("%d %d\n", j, i);
                    return 0;
                }
            }
        }
    }
    return 0;
}