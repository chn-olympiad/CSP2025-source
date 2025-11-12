#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 110;
struct node {
    int x, id;
} a[N];
bool cmp(node x, node y) {
    return x.x > y.x;
}
int up(int x, int y) {
    if (x % y == 0) return y;
    return x/y+1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int x = 0, k = 0;
    for (int i = 1; i <= m*n; i++) {
        if (a[++k].id == 1) {
            x = i;
        }
    }
    if (x % n % 2 == 1) {
        cout << x % n + 1 << " "<<up(x,n);
    } else {
        cout << x % n << " " << up(x,n);
    }
    return 0;
}
//g++ -o seat seat.cpp -O2 -std=c++14 -static