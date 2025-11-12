#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    if (a > b) return true;
    return false;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m, scr_r, scr_r_i;
    int scr[105];
    int c, r;
    bool Flag = false;

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> scr[i];
        if (i == 1) scr_r = scr[i];
    }

    sort(scr + 1, scr + n * m + 1, cmp);

    for (int i = 1; i <= n * m; i++){
        if (scr[i] == scr_r) scr_r_i = i;
    }

    c = (scr_r_i - 1) / n + 1,
    r = scr_r_i % m;
    if (r == 0) r = m;
    if (c % 2 == 0) r = m - r + 1;

    cout << c << " " << r;

    return 0;
}
