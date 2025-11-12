#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005;
int n, a[maxn][5], tmp[maxn], Max[maxn][5];
void work(); bool cmp(int, int);
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        work();
    }
    return 0;
}
bool cmp(int t1, int t2) {
    if (a[t1][Max[t1][1]] - a[t1][Max[t1][2]] != a[t2][Max[t2][1]] - a[t2][Max[t2][2]])
        return a[t1][Max[t1][1]] - a[t1][Max[t1][2]] > a[t2][Max[t2][1]] - a[t2][Max[t2][2]];
    if (a[t1][Max[t1][2]] - a[t1][Max[t1][3]] != a[t2][Max[t2][3]] - a[t2][Max[t2][3]])
        return a[t1][Max[t1][2]] - a[t1][Max[t1][3]] > a[t2][Max[t2][2]] - a[t2][Max[t2][3]];
    return a[t1][Max[t1][1]] > a[t2][Max[t2][1]];
}
void work() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3], tmp[i] = i;
    for (int i = 1; i <= n; i++) {
        if (a[i][1] >= a[i][2] && a[i][2] >= a[i][3]) Max[i][1] = 1, Max[i][2] = 2, Max[i][3] = 3;
        if (a[i][1] >= a[i][3] && a[i][3] >= a[i][2]) Max[i][1] = 1, Max[i][2] = 3, Max[i][3] = 2;
        if (a[i][2] >= a[i][1] && a[i][1] >= a[i][3]) Max[i][1] = 2, Max[i][2] = 1, Max[i][3] = 3;
        if (a[i][2] >= a[i][3] && a[i][3] >= a[i][1]) Max[i][1] = 2, Max[i][2] = 3, Max[i][3] = 1;
        if (a[i][3] >= a[i][1] && a[i][1] >= a[i][2]) Max[i][1] = 3, Max[i][2] = 1, Max[i][3] = 2;
        if (a[i][3] >= a[i][2] && a[i][2] >= a[i][1]) Max[i][1] = 3, Max[i][2] = 2, Max[i][3] = 1;
    }
    sort(tmp + 1, tmp + n + 1, cmp);
    int left[5] = {0, 0, 0, 0}, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (left[Max[tmp[i]][1]] != n / 2) {
            ans += a[tmp[i]][Max[tmp[i]][1]];
            left[Max[tmp[i]][1]]++;
        } else {
            ans += a[tmp[i]][Max[tmp[i]][2]];
            left[Max[tmp[i]][2]]++;
        }
    }
    cout << ans << endl;
    return ;
}
