#include<bits/stdc++.h>
using namespace std;
long long n, maxx, ans;
struct node {
    int x, y, z;
} a[1000005];

void f(int id, int xn, int yn, int zn, long long sum) {
    if (id > n) {
        ans = max(ans, sum);
        return ;
    }
    if (xn + 1 <= maxx) {
        f(id + 1, xn + 1, yn, zn, sum + a[id].x);
    }
    if (yn + 1 <= maxx) {
        f(id + 1, xn, yn + 1, zn, sum + a[id].y);
    }
    if (zn + 1 <= maxx) {
        f(id + 1, xn, yn, zn + 1, sum + a[id].z);
    }
    return ;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ans = -1;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        maxx = n / 2;
        f(1, 0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}