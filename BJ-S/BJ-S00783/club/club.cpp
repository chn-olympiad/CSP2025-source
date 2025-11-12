#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int t, n, ans;

struct stu{
    int m[5], mx, cnt[5];
}f[100005], a[100005];

bool cmp(stu x, stu y) {
    if (x.mx != y.mx)
        return x.mx < y.mx;
    if (x.m[1] != y.m[1])
        return x.m[1] > y.m[1];
    if (x.m[2] != y.m[2])
        return x.m[2] > y.m[2];
    return x.m[3] > y.m[3];
}

void s(int n, int i) {
    for (int j = 1; j < n; j++)
        f[i].cnt[j] = f[i].cnt[j - 1];
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        memset(f, 0, sizeof(f));
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) {
                scanf("%d", &a[i].m[j]);
                a[i].mx = max(a[i].mx, a[i].m[j]);
            }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (f[i - 1].m[3] + a[i].m[j] > f[i].m[j - 1] && f[i - 1].cnt[j] + 1 <= n / 2) {
                    s(j, i);
                    f[i].cnt[j] = f[i - 1].cnt[j] + 1, f[i].m[j] = f[i - 1].m[3] + a[i].m[j];
                }
                else
                    f[i].cnt[j] = f[i - 1].cnt[j],f[i].m[j] = max(f[i - 1].m[3], f[i].m[j - 1]);
//                printf("%d ", f[i].m[j]);
            }
//            printf("\n");
        }
        printf("%d\n", f[n].m[3]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}