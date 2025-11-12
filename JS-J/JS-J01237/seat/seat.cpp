#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int a, b, n, m, cnt = 0, col_ = 0, row_ = 0;
    cin >> n >>  m;
    int seat_[n * m + 5] = {};
    for(int i = 1; i <= n * m; i++){
        cin >> b;
        if(i == 1){
            a = b;
        }else if(b > a){
            cnt ++;
        }
    } cnt += 1;
    if(n * m == 1){
        cout << a;
        return 0;
    }
    if(cnt % n == 0){
        col_ = cnt / n;
        cnt = n;
    } else {
        col_ = cnt / n + 1;
        cnt -= (col_ - 1) * n;
    }
    if(col_ % 2 == 1){
        cout << col_ << " " << cnt;
    } else {
        row_ = n - cnt + 1;
        cout << col_ << " " << row_;
    }
    return 0;
}
