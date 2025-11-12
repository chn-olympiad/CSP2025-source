#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 1;

struct Stu { int a, b, c, mx, id, used; } a[MAXN];

int t, n;
ll ans;
bool f1, f2;

bool cmp1(Stu& a, Stu& b) { return a.a > b.a; }
bool cmp2(Stu& a, Stu& b) { return a.b > b.b; }
bool cmp3(Stu& a, Stu& b) { return a.c > b.c; }

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    for (scanf("%d", &t); t--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
            a[i].mx = max({a[i].a, a[i].b, a[i].c});
            if (a[i].mx == a[i].a) a[i].id = 1;
            if (a[i].mx == a[i].b) a[i].id = 2;
            if (a[i].mx == a[i].c) a[i].id = 3;
            a[i].used = 0;
        }
        for (int i = 1; i <= 3; i++) {
            if (i == 1) sort(a + 1, a + 1 + n, cmp1);
            if (i == 2) sort(a + 1, a + 1 + n, cmp2);
            if (i == 3) sort(a + 1, a + 1 + n, cmp3);
            for (int j = 1; j <= n / 2; j++) {
                if (a[j].used) continue;
                if (i == 1) ans += a[j].a;
                if (i == 2) ans += a[j].b;
                if (i == 3) ans += a[j].c;
                a[j].used = 1;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
拼尽全力无法战胜
可以看出没有后效性，即不能贪心，但是 DP 是真不会了，只能码一个贪心拿部分分
1.5KB 的史山
期望得分：20
完成时间：2h 30min
*/
