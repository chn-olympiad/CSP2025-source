#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10007];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    int me = a[1];
    int myseat = 0;
    sort(a + 1, a + n * m + 1, [](int a, int b) -> bool {
         return a > b;
    });
    for(int i = 1; i <= n * m; i++) {
        if(a[i] == me) {
            myseat = i;
            break;
        }
    }
    int lie = ceil(myseat / (n * 1.0));
    if(lie & 1) {
        cout << lie << ' ' << myseat - (lie - 1) * n << '\n';
    } else {
        cout << lie << ' ' << lie * n - myseat + 1 << '\n';
    }
}
