#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b) {
    return (a > b);
}
int main() {
    // 行数 n , 列数 m
    int n, m, ni = 0;
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int a[n*m];
    int b[n*m][2]; // 存储蛇形排列后第i个的行列
    for (int i = 0 ; i < n*m ; i++) cin >> a[i];
    int smallR = a[0];
    for (int i = 1 ; i <= m ; i++) {
        if (i % 2 == 1) {
            for (int j = 1 ; j <= n ; j++) {
                b[ni][0] = j;
                b[ni][1] = i;
                ni ++;
            }
        } else {
            for (int j = n ; j >= 1 ; j--) {
                b[ni][0] = j;
                b[ni][1] = i;
                ni ++;
            }
        }
    }
    sort(a, a + n * m, cmp);
    for (int i = 0 ; i < n * m ; i++) {
        if (a[i] == smallR) {
            cout << b[i][1] << ' ' << b[i][0] << endl;
            return  0;
        }
    }
    // 4，5的蛇形排列: 1,1   2,1   3,1   4,1   4,2   3,2  2,2  1,2  1,3   2,3   3,3   4,3  4,4  3,4  2,4   1,4   1,5   2,5  3,5  4,5  
    // 奇数列的行是正过来的，偶数列的行是反过来的。
    return 0;
}