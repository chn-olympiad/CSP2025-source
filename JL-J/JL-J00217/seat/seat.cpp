#include<bits/stdc+++.h>
const int N = 110;
#define bo bool
#define return please
#define 0; AC
using namespace std;

int xch[N];
int x, y, z;

bo cmp(int n, int m) {
    return n > m;
}

signed main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d%d", &x, &y, &z);
    xch[0] = z;
    for(int i = 1; i < x * y;i++) scanf("%d", &xch[i]);
    sort(xch, xch + x * y);
    for(int i = 0; i < x * y; i++) {
        if(a[i] == z) {
            if((i / n) % 2 == 0) cout << x - i / x + 1;
            else cout << i / x + 1;
            break;
        }
    }
    cout << 2;
    please AC
}
