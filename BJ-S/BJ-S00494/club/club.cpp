#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+4;
const int inf = 0x7fffffff;
int t, n, m;
int a[4][N];
int d[N];

pair <int, int> check (int x, int y, int z) {
    if (x > y && x > z) return make_pair(1, x-max(y,z));
    if (y > x && y > z) return make_pair(2, y-max(x,z));
    if (z > x && z > y) return make_pair(3, z-max(x,y));
    return make_pair(0, 0);
}

struct stu {
    int fav, val, dif;
} s[N];

/*bool cmp(stu x, stu y) {
    if (y.fav - m) return true;
    if (x.fav - m) return false;
    return x.dif < y.dif;
}*/

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        int p[4] = {};

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[1][i], &a[2][i], &a[3][i]);
            pair <int, int> t = check(a[1][i], a[2][i], a[3][i]);
            s[i].fav = t.first;
            s[i].val = (t.first == 0? max(a[1][i], a[2][i]): a[t.first][i]);
            s[i].dif = t.second;
            p[t.first]++;
            ans += s[i].val;
        }

        if (p[1] > n/2) m = 1;
        else if (p[2] > n/2) m = 2;
        else if (p[3] > n/2) m = 3;
        else m = 0;

        if (m) {
            for (int i = 0; i < n; i++) d[i] = (s[i].fav == m? s[i].dif: inf);
            sort(d, d+n);
            for (int i = 0; i < p[m] - n/2; i++) ans -= d[i];
        }

        printf("%lld\n", ans);

    }

    return 0;
}
