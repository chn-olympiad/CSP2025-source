#include <bits/stdc++.h>
using namespace std;
//#define int long long
struct node {
    int x, y, z;
} a[1000005];
int n;
int v1[1000005], v2[1000005], v3[1000005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            v1[i] = 0;
            v2[i] = 0;
            v3[i] = 0;
        }
        int c1 = 0, c2 = 0, c3 = 0;
        int ans = 0;
        priority_queue <pair <int, pair <int, int> > > q1, q2, q3;
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
            if (a[i].x >= a[i].y && a[i].x >= a[i].z) {
                // a[i].y = a[i].y - a[i].x;
                // a[i].z = a[i].z - a[i].x;
                ans += a[i].x;
                q1.push({a[i].y - a[i].x, {i, 2}});
                q1.push({a[i].z - a[i].x, {i, 3}});
                c1 ++;
                // cout << i << " x : " << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
            } else if (a[i].y >= a[i].x && a[i].y >= a[i].z) {
                // a[i].x = a[i].x - a[i].y;
                // a[i].z = a[i].z - a[i].y;
                q2.push({a[i].x - a[i].y, {i, 1}});
                q2.push({a[i].z - a[i].y, {i, 3}});
                ans += a[i].y;
                c2 ++;
                // cout << i << " y : " << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
            } else if (a[i].z >= a[i].x && a[i].z >= a[i].y) {
                // a[i].x = a[i].x - a[i].z;
                // a[i].y = a[i].y - a[i].z;
                q3.push({a[i].x - a[i].z, {i, 1}});
                q3.push({a[i].y - a[i].z, {i, 2}});
                ans += a[i].z;
                c3 ++;
                // cout << i << " z : " << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
            }
        }
        // cout << c1 << " " << q1.size() << "\n";
        // cout << ans << "\n";
            // cout << q1.size() << " " << (bool)(q2.size() / 2 > n / 2) << " " << q3.size() << "\n";
        while (c1 > n / 2 || c2 > n / 2 || c3 > n / 2) {
            // cout << q1.size() << " " << q2.size() << " " << q3.size() << " !!!\n";
            if (c1 > n / 2) {
                int nd = q1.top().first, nw = q1.top().second.first, to = q1.top().second.second;
                q1.pop();
                if (v1[nw]) continue;
                v1[nw] = 1;
                c1 --;
                if (to == 2) {
                    c2 ++;
                    ans += nd;
                    if (a[nw].y >= a[nw].z) q2.push({a[nw].z - a[nw].y, {to, 3}});
                    q2.push({a[nw].y - a[nw].x, {to, 2}});
                } else if (to == 3) {
                    c3 ++;
                    ans += nd;
                    if (a[nw].y <= a[nw].z) q3.push({a[nw].y - a[nw].z, {to, 2}});
                    q3.push({a[nw].z - a[nw].x, {to, 3}});
                }
                continue;
            } else if (c2 > n / 2) {
                int nd = q2.top().first, nw = q2.top().second.first, to = q2.top().second.second;
                q2.pop();
                // cout << nd << " " << nw << " " << to << "\n";
                if (v2[nw]) continue;
                v2[nw] = 1;
                c2 --;
                if (to == 1) {
                    ans += nd;
                    c1 ++;
                    if (a[nw].x >= a[nw].z) q1.push({a[nw].z - a[nw].x, {to, 3}});
                    q1.push({a[nw].x - a[nw].y, {to, 1}});
                } else if (to == 3) {
                    ans += nd;
                    c3 ++;
                    if (a[nw].x <= a[nw].z) q3.push({a[nw].x - a[nw].z, {to, 1}});
                    q3.push({a[nw].z - a[nw].y, {to, 3}});
                }
                continue;
            } else if (c3 > n / 2) {
                int nd = q3.top().first, nw = q3.top().second.first, to = q3.top().second.second;
                q3.pop();
                if (v3[nw]) continue;
                v3[nw] = 1;
                c3 --;
                if (to == 1) {
                    ans += nd;
                    c1 ++;
                    if (a[nw].x >= a[nw].y) q1.push({a[nw].y - a[nw].x, {to, 2}});
                    q1.push({a[nw].x - a[nw].z, {to, 1}});
                } else if (to == 2) {
                    ans += nd;
                    c2 ++;
                    if (a[nw].x <= a[nw].y) q2.push({a[nw].x - a[nw].y, {to, 1}});
                    q2.push({a[nw].y - a[nw].z, {to, 2}});
                }
                continue;
            }
        }
        // ans = 0;
        // for (int i = 1; i <= n; i ++) {
        //     v1[i] = 0;
        //     v2[i] = 0;
        //     v3[i] = 0;
        // }
        // while (q1.size()) {
        //     cout << 
        //     if (!v1[q1.top().second.first]) ans += a[q1.top().second.first].x;
        //     q1.pop();
        // }
        // while (q2.size()) {
        //     if (!v2[q2.top().second.first]) ans += a[q2.top().second.first].x;
        //     q2.pop();
        // }
        // while (q3.size()) {
        //     if (!v3[q3.top().second.first]) ans += a[q3.top().second.first].x;
        //     q3.pop();
        // }
        cout << ans << "\n";
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

4
4
4 2 1
3 2 4
5 3 4
3 5 1
4
1 1 0
1 1 0
2 2 0
2 1 0
2
10 9 8
4 0 0
4
1 1 0
5 4 0
4 1 0
1 9 0
*/