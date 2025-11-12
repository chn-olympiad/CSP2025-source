#include <bits/stdc++.h>
using namespace std;
// T2
int n, m, r, k, cc, a[110];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m >> r;
    a[0] = r;
    for (int i = 1; i < n * m; i ++) cin >> a[i];
    sort(a, a + n * m, cmp);
    for (int i = 0; i < n * m; i ++)
        if (a[i] == r) k = i;
    cc = k / n + 1;
    cout << cc;
    cout << ' ';
    if (cc % 2) cout << k % n + 1;
    else cout << n - (k % n);
    return 0;
}
