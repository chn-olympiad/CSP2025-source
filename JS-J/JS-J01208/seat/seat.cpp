#include <bits/stdc++.h>
using namespace std;
const int N = 115;
int a[N];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int len = n * m;
    for (int i = 1; i <= len; i++) {
        cin >> a[i];
    }
    int R = a[1];
    int ans;
    sort(a + 1, a + len + 1, greater<int>());
    for (int i = 1; i <= len; i++) {
        if (R == a[i]) {
            ans = i;
            break;
        }
    }

  //  cout << ans << endl;
    int i, j;
    if (ans / n < 1) j = 1;
    if (ans / n >= 1 && ans % n == 0) j = ans / n;
    if (ans / n >= 1 && ans % n != 0) j = ans / n + 1;

   // bool flag = true;
    if (j % 2 == 0) {
        i = n + 1 - (ans % n);
    //    flag = false;
        if (i == n + 1) i = 1;
    }
    else {
        i = ans % n;
        if (i == 0) i = n;
    }
 //   cout << flag << endl;
    cout << j << " " << i << endl;
    return 0;
}
