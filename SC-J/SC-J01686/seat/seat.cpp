#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n, m, scr[N], uscr;
//n行 m列
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i ++) cin >> scr[i];
    uscr = scr[1];
    sort(scr + 1, scr + 1 + n * m);
    int x = 1, y = 1, idx = m * n;
    //y行x列
    //for (int i = 1;i <= n * m;i ++) cout << scr[i] << ' ';
    while (scr[idx] != uscr){
        //cout << x << ' ' << y << ' ' << scr[idx] << '\n';
        idx --;
        if ((x % 2 == 1 && y == n) || (x % 2 == 0 && y == 1)) {
            x ++;
            continue;
        }
        if (x % 2 == 1) y ++;
        else y --;

    }
    cout << x << ' ' << y;
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92

*/
