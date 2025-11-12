#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3 + 5;
int n, m, r, k = 1, a[N], seat[N][N];
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i ++) cin >> a[i];
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= m; i ++) {
        if(i % 2 == 1) {
            for(int j = 1; j <= n; j ++) {
                seat[j][i] = a[k];
                k ++;
            }
        }
        else {
            for(int j = n; j >= 1; j --) {
                seat[j][i] = a[k];
                k ++;
            }
        }
    }
    bool f = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(seat[i][j] == r) {
                cout << j << " " << i;
                f = 1;
                break;
            }
        }
        if(f) break;
    }
    return 0;
}
