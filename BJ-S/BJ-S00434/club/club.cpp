#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int d[N][3], cnt[5], id[N], mx[N], se[N];
bool cmp(int i, int j) { return d[i][mx[i]] - d[i][se[i]] > d[j][mx[j]] - d[j][se[j]]; }
void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i][0] >> d[i][1] >> d[i][2];
    for (int i = 1; i <= n; i++) id[i] = i;
    for (int i = 1; i <= n; i++) {
        mx[i] = 0;
        for (int j = 0; j < 3; j++)
            if (d[i][j] > d[i][mx[i]]) mx[i] = j;
        se[i] = (mx[i] ? 0 : 1);
        for (int j = 0; j < 3; j++)
            if (d[i][j] > d[i][se[i]] && j != mx[i]) se[i] = j;
    }
    sort(id + 1, id + n + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i++) 
        if (cnt[mx[id[i]]] == n / 2) ans += d[id[i]][se[id[i]]], cnt[se[id[i]]]++;
        else ans += d[id[i]][mx[id[i]]], cnt[mx[id[i]]]++;
    cout << ans << endl;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}