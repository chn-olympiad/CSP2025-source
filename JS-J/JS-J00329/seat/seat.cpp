#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 15;
int seat[N][N];
int a[N * N];
int cmp = 1 , n , m , r;
int ansi , ansj , ii = 0 , jj = 1;

signed main () {
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i];
    }
    r = a[1];
    if (n == 1 && m == 1) {
        cout << "1 1" << endl;
        return 0;
    }
    for (int i = 1; i <= n * m; i++) {
        int d = a[i] , w = i;
        for (int j = i + 1; j <= n * m; j++) {
            if (a[j] > d) {
                d = a[i];
                w = j;
            }
        }
        swap(a[i] , a[w]);

    }
    if (n == 1) ii = 1;
    while (cmp <= n * m) {
        if (ii + 1 <= n && jj % 2 == 1) {
            ii += 1;
        }
        else  if (ii - 1 >= 1 && jj % 2 == 0){
            ii -= 1;
        }else {
            jj ++;
        }

        if (a[cmp] == r) {
            cout << jj << " " <<  ii<< endl;
            break;
        }
        cmp++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
