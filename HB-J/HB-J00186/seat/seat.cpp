#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000100];
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    int c = 1, r = 1;
    bool flag = true;
    /*
    Judge flag:
        if true:
            down
        else:
            up;
    */
    int tw;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    tw = a[1];
    sort(a + 1, a + n * m + 1, [](int x, int y) {
         return x > y;
    });
    int time = 0;
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == tw) {
            time = i;
            break;
        }
    }
    for (int _ = 1; _ <= n * m; _++) {
        if (_ == time) {
            cout << r << " " << c << endl;
            return 0;
        }
        if (flag){
            c++;
            if (c > n)
                r++, c = n, flag = false;
        }
        else{
            c--;
            if (c < 1)
                r++, c = 1, flag = true;
        }
    }
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
