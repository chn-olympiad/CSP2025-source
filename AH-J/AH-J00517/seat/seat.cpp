#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], n, m;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n*m; i++) cin >> a[i];
    int b = a[0];
    sort(a, a+n*m, greater<int>());
    int i = lower_bound(a, a+n*m, b, greater<int>()) - a;
    int c = i / n+1, r;
    if (c&1) r = i % n + 1;
    else r = n - i % n;
    cout << c << ' ' 
    << r << '\n';
    return 0;
}