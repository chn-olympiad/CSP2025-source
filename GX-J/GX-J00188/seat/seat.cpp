#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], l[105], k, x, t, x1, y;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> l[i];
    }
    k = l[1];
    for (int j = 1; j <= n * m - 1; j++){
        for (int i = 1; i <= n * m - 1; i++){
            if (l[i] < l[i + 1]){
                x = l[i];
                l[i] = l[i + 1];
                l[i + 1] = x;
            }
        }
    }
    for (int i = 1; i <= n * m - 1; i++){
        if (l[i] == k){
            t = i;
        }
    }
    if (t % n != 0){
        x1 = t / n + 1;
    }
    else{
        x1 = t / n;
    }
    if (x1 % 2 == 1){
        y = t - ((x1 - 1) * n);
    }
    else{
        y = n - ((t - ((x1 - 1) * n)) - 1);
    }
    cout << x1 << " " << y;
    return 0;
}
