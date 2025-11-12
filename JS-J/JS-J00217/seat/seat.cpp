#include <bits/stdc++.h>
using namespace std;
int a[120];
int m, n, num, x;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
        if(i == 1)  num = a[i];
    }
    sort(a + 1, a + n * m + 1);
    for (int i = n * m; i >= 1; i--){
        if(a[i] == num){
            num = n * m - i;
            break;
        }
    }
    x = num / n + 1;
    if(x % 2 == 0){
        cout << x << ' ' << n - (num - (x - 1) * n + 1);
    } else {
        cout << x << ' ' << num - (x - 1) * n + 1;
    }
    return 0;
}
