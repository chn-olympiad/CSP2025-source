#include <bits/stdc++.h>
using namespace std;
int n, m, R;
int a[225];
int seat[15][15];
bool cmp (int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int T = n * m;
    for (int i = 1; i <= T; i++) cin >> a[i];
    R = a[1];
    sort (a + 1, a + T + 1, cmp);
    int ansi, ansj,x = 1, y = 1, f = 1;
    for(int i = 1; i <= T; i++){
        if (a[i] == R){
            cout << y << " " << x;
            return 0;
        }
        seat[x][y] = a[i];
        x += f;
        if (x > n || x < 1) x -= f, y++, f = -f;
    }
    return 0;
}

