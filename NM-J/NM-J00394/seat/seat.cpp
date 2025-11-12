#include <bits/stdc++.h>
using namespace std;

int score, n, m, r_score, flag, c, r;

int main (){
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    flag = 1;
    cin >> n >> m;
    for (int i = 0; i < n*m; i++){
        cin >> score;
        if (i == 0) r_score = score;
        else {
            if (score > r_score) flag++;
        }
    }
    if (flag % n != 0){
        c = flag / n + 1;
        if (c % 2 == 0){
            r = n + 1 - flag % n;
        }
        else {
            r = flag % n;
        }
    }
    else {
        c = flag / n;
        if (c % 2 == 0){
            r = 1;
        }
        else {
            r = n;
        }
    }
    cout << c << ' ' << r;
    return 0;
}
