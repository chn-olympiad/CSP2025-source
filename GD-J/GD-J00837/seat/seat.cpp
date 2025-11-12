#include<bits/stdc++.h>
using namespace std;
bool cmp(int o, int w) {
    return o > w;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;;
    cin >>n >>m;
    int zw[110][110] = { };
    int a[1100] = { };
    for(int i = 1; i <= n * m; i++) {
        cin >>a[i];
    }
    int qwq = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int pri = 1;
    bool fl = false; //false : up to down; true : down to up
    for(int i = 1; i <= m; i++) {
        if(fl == false) {
            for(int j = 1; j <= n; j++) {
                zw[j][i] = a[pri];
                pri++;
            }
        }
        else {
            for(int j = n; j >= 1; j--) {
                zw[j][i] = a[pri];
                pri++;
            }
        }
        if(fl == false) fl = true;
        else fl = false;
    }
    //find seat
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(zw[i][j] == qwq) {
                cout <<j <<" " <<i;
                break;
            }
        }
    }
    return 0;
}

