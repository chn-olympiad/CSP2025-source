#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n, cnt[4], ans = 0;
struct node{
    int x, y, z;
}a[N];
void dfs(int step, int sum) {
    if (step == n) {
        ans = max(ans, sum);
        return ;
    }
    if (cnt[1]>= n / 2 || cnt[2]>= n/2 || cnt[3]>=n/2) return;
    cnt[1]++; dfs(step + 1, sum + a[step].x); cnt[1]--;
    cnt[2]++; dfs(step + 1, sum + a[step].y); cnt[2]--;
    cnt[3]++; dfs(step + 1, sum + a[step].z); cnt[3]--;
}
void work() {
    cnt[0] = 1; cnt[1] = 1; cnt[2] = 0; cnt[3] = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    if (n < 30) {
        ans = 0;
        dfs(1, 0);
        cout << ans << endl;
    }
}
int main() {
    freopen("club.in","r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) work();
    return 0;
}
