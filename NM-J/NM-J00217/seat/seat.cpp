#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], ra, rs, r, c;

int cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) cin >> a[i];
    ra = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++){
        if (a[i] == ra) rs = i;
    }
    c = rs / n;
    if (rs % n != 0) c++;
    if (c % 2 == 1) r = rs % n;
    else r = n - (rs % n) + 1;
    if (r == 0) r = n;
    cout << c << ' ' << r;
    return 0;
}
