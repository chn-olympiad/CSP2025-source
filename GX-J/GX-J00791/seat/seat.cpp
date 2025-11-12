#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[114];
struct pos {
    int x, y;
};
bool cmp(int a, int b) {
    return a > b;
}
pos f(int k) {
    int ansx, ansy;
    ansx = k / 3 + 1;
    if (ansx % 2 == 0) {
        ansy = n - k % 3;
    } else {
        ansy = k % 3;
    }
    return {ansx, ansy};
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; ++i) {
        scanf("%d", &a[i]);
    }
    int sc = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; ++i) {
        if (a[i] == sc) {
            pos ans = f(i);
            printf("%d %d\n", ans.x, ans.y);
            return 0;
        }
    }
    return 0;
}
