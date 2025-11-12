#include <iostream>
#include <algorithm>
using namespace std;
const int N = 110;

int n, m, a[N], x;
bool cmp(int a, int b) {return a > b;}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
    x = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int pos = 0;
    for (int i = 1; i <= n * m; i++)
        if (a[i] == x) {pos = i; break;}
    int tmp = ((pos % n == 0) ? (n) : (pos % n));
    int col = ((pos % n == 0) ? (pos / n) : (pos / n + 1));
    if (col % 2) printf("%d %d", col, tmp);
    else printf("%d %d", col, n - tmp + 1);
    return 0;
}
