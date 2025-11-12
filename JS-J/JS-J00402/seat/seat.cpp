#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], l, r, tmp;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    l = n * m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    r = a[1];
    for (int i = 1; i <= l; i++){
        for (int j = i + 1; j <= l; j++){
            if (a[j] >= a[i]){
                int t;
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i = 1; i <= l; i++){
        if (a[i] == r){
            tmp = i;
            break;
        }
    }
    int x = tmp, cnt = 1;
    while (x > n){
        x -= n;
        cnt++;
    }
    cout << cnt << " ";
    if (cnt % 2 == 1){
        cout << x << endl;
    }
    else{
        cout << n - x + 1 << endl;
    }
    return 0;
}