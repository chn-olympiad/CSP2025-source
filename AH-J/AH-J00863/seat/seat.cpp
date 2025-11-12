#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 1e5 + 10;
int a[N];
int k;
bool cmp(int A, int B) {
    return A > B;
}
signed main(void) {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i ++) cin >> a[i];
    k = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int cnt = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            int ni = i, nj = j;
            if(i % 2 == 0) nj = n - nj + 1;
            if(a[cnt] == k) {
                cout << ni << ' ' << nj << endl;
                return 0;
            }
            cnt ++;
        }
    }
    return 0;
}
