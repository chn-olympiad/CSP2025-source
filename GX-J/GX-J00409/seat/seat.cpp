#include <cstdio>
#include <algorithm>

using namespace std;

struct tester {
    int point;
    bool isR = false;
} a[150];

int n, m;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (int i = 0;i < n*m;++i) {
        scanf("%d", &a[i].point);
    }
    a[0].isR = true;

    sort(&a[0], &a[n*m], [](const tester& l, const tester& r){
        return l.point > r.point;
    });

    int pos;
    for (int i = 0;i < n*m;++i) {
        if (a[i].isR) {
            pos = i + 1;
            break;
        }
    }

    int Rm = (pos / n) + (((pos % n) != 0) ? 1 : 0);
    int Rn = pos % n;
    if (Rn == 0) {
        Rn = n;
    }
    if (Rm % 2 == 0) {
        Rn = n - Rn + 1;
    }

    printf("%d %d\n", Rm, Rn);

    return 0;
}