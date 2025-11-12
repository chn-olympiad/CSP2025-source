//RP++ csp I love you, see you, OI! AFO? forever? please remember me, I'm dog_emperor.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int T, a[N][4], pos[N];
struct info {;
    int b, id;
}bx[N];

inline bool cmp(const info &x, const info &y) {
    return x.b < y.b;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
        int ans = 0, num1 = 0, num2 = 0, num3 = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
                num1++, pos[i] = 1;
            else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
                num2++, pos[i] = 2;
            else num3++, pos[i] = 3;
            ans += max(a[i][1], max(a[i][2], a[i][3]));
        }
        if (num1 > n / 2) {
            int len = 0;
            for (int i = 1; i <= n; ++i) {
                if (pos[i] == 1) {
                    if (a[i][1] - a[i][2] < a[i][1] - a[i][3])
                        bx[++len].b = a[i][1] - a[i][2], bx[len].id = 2;
                    else bx[++len].b = a[i][1] - a[i][3], bx[len].id = 3;
                }
            }
            sort(bx + 1, bx + len + 1, cmp);
         //   for (int i = 1; i <= len; ++i)
          //      printf("%d %d\n", bx[i].b, bx[i].id);
            for (int i = 1; i <= num1 - n / 2; ++i) {
                if (bx[i].id == 2) {
                    ans -= bx[i].b;
                    num2++;
                } else if (bx[i].id == 3) num3++, ans -= bx[i].b;
            //  printf("%d %d %d\n", num1, num2, num3);
            }
        } else if (num2 > n / 2) {
                int len = 0;
                for (int i = 1; i <= n; ++i) {
                    if (pos[i] == 2) {
                        if (a[i][2] - a[i][1] < a[i][2] - a[i][3])
                            bx[++len].b = a[i][2] - a[i][1], bx[len].id = 1;
                        else bx[++len].b = a[i][2] - a[i][3], bx[len].id = 3;
                    }
                }
                sort(bx + 1, bx + len + 1, cmp);
                //for (int i = 1; i <= len; ++i)
                  //  printf("%d %d\n", bx[i].b, bx[i].id);
                for (int i = 1; i <= num2 - n / 2; ++i) {
                    if (bx[i].id == 1) {
                        ans -= bx[i].b;
                        num1++;
                    } else if (bx[i].id == 3) num3++, ans -= bx[i].b;
                //  printf("%d %d %d\n", num1, num2, num3);
                }
        } else {
            int len = 0;
            for (int i = 1; i <= n; ++i) {
                if (pos[i] == 3) {
                    if (a[i][3] - a[i][1] < a[i][3] - a[i][2])
                        bx[++len].b = a[i][3] - a[i][1], bx[len].id = 1;
                    else bx[++len].b = a[i][3] - a[i][2], bx[len].id = 2;
                }
            }
            sort(bx + 1, bx + len + 1, cmp);
         //   for (int i = 1; i <= len; ++i)
          //      printf("%d %d\n", bx[i].b, bx[i].id);
            for (int i = 1; i <= num3 - n / 2; ++i) {
                if (bx[i].id == 1) {
                    ans -= bx[i].b;
                    num1++;
                } else if (bx[i].id == 2) num2++, ans -= bx[i].b;
            //  printf("%d %d %d\n", num1, num2, num3);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
