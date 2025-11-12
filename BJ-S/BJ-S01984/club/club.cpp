#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 3;
int n, a[N][3], ans;
bool hhhh;
bool flag[N];
struct node {
    int x, id, op;
    bool friend operator < (node a, node b) {
        return a.x < b.x;
    }
};
void dfs (int step, int c1, int c2, int c3, int hat) {
    int kk[3];
    kk[0] = c1;
    kk[1] = c2;
    kk[2] = c3;
    if (step > n) {
        ans = max(ans, hat);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (kk[i] >= n / 2) continue;
        if (i == 0) {
            dfs(step + 1, c1 + 1, c2, c3, hat + a[step][i]);
        }
        else if (i == 1) {
            dfs(step + 1, c1, c2 + 1, c3, hat + a[step][i]);
        }
        else {
            dfs(step + 1, c1, c2, c3 + 1, hat + a[step][i]);
        }
    }
}
priority_queue <node> q;
signed main () {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        while (!q.empty()) q.pop();
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            flag[i] = 0;
            int x, y, z;
            cin >> x >> y >> z;
            if (y != 0 || z != 0) hhhh = 1;
            q.push({x, i, 0});
            q.push({y, i, 1});
            q.push({z, i, 2});
            a[i][0] = x;
            a[i][1] = y;
            a[i][2] = z;
        }
        if (hhhh == 0) {
            int cnt1 = 0;
            int cnt2 = 0;
            int cnt3 = 0;
            while (cnt1 + cnt2 + cnt3 < n) {
                int x = q.top().x;
                int id = q.top().id;
                int op = q.top().op;
                q.pop();
                if (flag[id]) continue;
                if (op == 0) {
                    if (cnt1 >= n / 2) continue;
                    ans += x;
                    cnt1++;
                    flag[id] = 1;
                }
                else if (op == 1) {
                    if (cnt2 >= n / 2) continue;
                    ans += x;
                    cnt2++;
                    flag[id] = 1;
                }
                else {
                    if (cnt3 >= n / 2) continue;
                    ans += x;
                    cnt3++;
                    flag[id] = 1;
                }
            }
            cout << ans << '\n';
            continue;
        }
        dfs(1, 0, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
//中国共产党万岁！！！
//中国共产党万岁！！！
//中国共产党万岁！！！