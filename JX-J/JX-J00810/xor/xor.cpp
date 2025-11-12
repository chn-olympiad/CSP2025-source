//niu qi chong tian
//by dog_emperor
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, k, a[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] != 1) ok = false;
    }
    //0 1
    if (k == 0 && ok) {
        printf("%d\n", n / 2);
    } else {
        //1 1
        if (k == 1 && ok) {
            printf("%d\n", n);
        } else if (k == 0 && !ok) { //0 ?
            int sum = 0;
            for (int i = 1; i <= n; ++i) {
                if (a[i] == a[i + 1] && i + 1 <= n) {
                    i++;
                    sum++;
                } else if (a[i] == 0 && a[i + 1] == 1 && a[i + 2] == 1 && i + 2 <= n) {
                    i += 2;
                    sum++;
                } else if (a[i] == 1 && a[i + 1] == 0 && a[i + 2] == 1 && i + 2 <= n) {
                    i += 2;
                    sum++;
                }
            }
            printf("%d\n", sum);
        } else if (k == 1 && !ok) { // 1  ?
            int sum = 0;
            for (int i = 1; i <= n; ++i)
                if (a[i] == 1) sum++;
            printf("%d\n", sum);
        }
    }
    return 0;
}
