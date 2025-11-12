#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int grade;
bool cmp (int x, int y) {
    return x > y;
}
int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    int k = n * m;
    for (int i = 1; i <= k; i++) cin >> a[i];
    grade = a[1];
    sort (a+1, a+k+1, cmp);
    int h = 1, l = 1;
    for (int i = 1; i <= k; i++) {
        if (a[i] == grade) {
            cout << l << " " << h;
            break;
        }
         if (l % 2 == 1) h++;
         else if (l % 2 == 0) h--;
         if (h > n) h = n, l++;
         if (h < 1) h = 1, l++;
    }
    return 0;
}
