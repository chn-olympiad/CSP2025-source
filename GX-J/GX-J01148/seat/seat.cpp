#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
int a[105];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int pm = 1;
    scanf("%d%d", &n, &m);
    scanf("%d", &a[0]);
    for (int i = 1; i < (n*m); i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[0]) {
            pm++;
        }
    }
    int shang = pm / n;
    int yushu = pm % n;
    if (yushu > 0) {
        if ((shang+1) % 2 == 0) {
            cout << (shang+1) << ' ' << (n-yushu+1);
        }
        else {
            cout << (shang+1) << ' ' << yushu;
        }
    }
    else {
        if (shang % 2 == 0) {
            cout << shang << ' ' << 1;
        }
        else {
            cout << shang <<  ' ' << n;
        }
    }
    return 0;
}
