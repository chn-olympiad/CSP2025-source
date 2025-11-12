#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y) {
    return x > y;
}
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    int r = a[0];
    int u;
    sort(a,a + n * m, cmp);
    for (int i = 0; i < n * m; i++) {
        if (a[i] == r) {
            u = i;
            break;
        }
    }
    if ((u + 1) % (2 * n) <= n)
        cout << u / n + 1 << " " << u % n + 1;
    else
        cout << u / n + 1 << " " << n - ((u + 1) % n) + 1;
    return 0;

}
