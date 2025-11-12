#include <bits/stdc++.h>
using namespace std;



int n, m, r, t, pos = 1;
int a[1010];
int b[20][20];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
     freopen("seat.in", "r", stdin);
     freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int l = n*m;
    for(int i = 1; i <= l; i++) {
        cin >> a[i];
        if(i == 1) r = a[i];

    }
    sort(a + 1, a + 1 + l, cmp);
    while(pos <= m) {
        for(int i = 1; i <= n; i++) {
        b[i][pos] = a[++t];
        if(i == n) {
            pos++;
            for(int i = n; i >= 1; i--) {
                b[i][pos] = a[++t];
            }
            pos++;
        }
    }

}

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(b[i][j] == r) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
/*

*/
