# include <bits/stdc++.h>
using namespace std;
int n , m , a[105] , seat[15][15] , sum , pos;
bool towards;
bool cmp (int x , int y) {
    return x > y;
}
int main () {
    freopen ("seat.in" , "r" , stdin);
    freopen ("seat.out" , "w" , stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i ++) cin >> a[i];
    sum = a[1];
    sort (a + 1 , a + n * m + 1 , cmp);
    for (int i = 1;i <= n * m;i ++) {
        if (sum == a[i]) pos = i;
    }
    int j = 1;
    for (int i = 1;i <= m;i ++) {
        pos --;
        if (! pos) {
            cout << i << " " << j;
            return 0;
        }
        if (! towards && i % 2 == 1 && j != n) {
            j ++;
        }
        else if (towards && i % 2 == 0 && j != 1) {
            j --;
        }
        else {
            towards = ! towards;
            i ++;
        }
        i --;
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}
