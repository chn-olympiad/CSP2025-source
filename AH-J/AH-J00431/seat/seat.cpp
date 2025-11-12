#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int k = n * m;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
    }
    int r = a[1];
    sort(a + 1, a + k + 1, cmp);
    int x = 1, y = 1, cnt = 1;
    bool flag = 0, quit = 0;
    while (cnt <= k && y <= m) {
        if (quit) {
            break;
        }
        if (flag == 0) {
            flag = !flag;
            while (x <= n && quit != 1) {
                if (a[cnt] == r) {
                    printf("%d %d", y, x);
                    quit = 1;
                    break;
                }
                x++;
                cnt++;
            }
            x--;
            if (quit) {
                break;
            }
            y++;
            if (a[cnt] == r) {
                printf("%d %d", y, x);
                quit = 1;
                break;
            }
        } else if (flag == 1) {
            flag = !flag;
            while (x >= 1 && quit != 1) {
                if (a[cnt] == r) {
                    printf("%d %d", y, x);
                    quit = 1;
                    break;
                }
                x--;
                cnt++;
            }
            x++;
            if (quit) {
                break;
            }
            y++;
            if (a[cnt] == r) {
                printf("%d %d", y, x);
                quit = 1;
                break;
            }
        }
    }
    if (!quit) {
        printf("%d %d", y, x);
    }
    return 0;
}
// ~~~
