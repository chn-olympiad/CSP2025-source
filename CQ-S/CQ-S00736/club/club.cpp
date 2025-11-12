#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ai2 = array<int, 2>;
using ai3 = array<int, 3>;
const int N = 2e5 + 10;
int n, cnt[3];
ai3 a[N];
struct Node1 {
    int x, y, z;
    bool operator < (const Node1 &val) const {
        return x - max(y, z) == val.x - max(val.y, val.z) ? x > val.x : x - max(y, z) > val.x - max(val.y, val.z);
    }
};
struct Node2 {
    int x, y, z;
    bool operator < (const Node2 &val) const {
        return y - max(x, z) == val.y - max(val.x, val.z) ? y > val.y : y - max(x, z) > val.y - max(val.x, val.z);
    }
};
struct Node3 {
    int x, y, z;
    bool operator < (const Node3 &val) const {
        return z - max(x, y) == val.z - max(val.x, val.y) ? z > val.z : z - max(x, y) > val.z - max(val.x, val.y);
    }
};
priority_queue<Node1> q0;
priority_queue<Node2> q1;
priority_queue<Node3> q2;
int f[2][2010][2010];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    cnt[0] = cnt[1] = cnt[2] = 0;
    while(q0.size()) q0.pop();
    while(q1.size()) q1.pop();
    while(q2.size()) q2.pop();
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int t = max({a[i][0], a[i][1], a[i][2]});
        if(t == a[i][0] && t == a[i][1] && t == a[i][2]) {
            if(cnt[0] < n >> 1) cnt[0] ++, ans += t, q0.push({a[i][0], a[i][1], a[i][2]});
            else if(cnt[1] < n >> 1) cnt[1] ++, ans += t, q1.push({a[i][0], a[i][1], a[i][2]});
            else cnt[2] ++, ans += t, q2.push({a[i][0], a[i][1], a[i][2]});
        } else if(t == a[i][0] && t == a[i][1]) {
            if(cnt[0] < n >> 1) cnt[0] ++, ans += t, q0.push({a[i][0], a[i][1], a[i][2]});
            else if(cnt[1] < n >> 1) cnt[1] ++, ans += t, q1.push({a[i][0], a[i][1], a[i][2]});
        } else if(t == a[i][0] && t == a[i][2]) {
            if(cnt[0] < n >> 1) cnt[0] ++, ans += t, q0.push({a[i][0], a[i][1], a[i][2]});
            else if(cnt[2] < n >> 1) cnt[2] ++, ans += t, q2.push({a[i][0], a[i][1], a[i][2]});
        } else if(t == a[i][1] && t == a[i][2]) {
            if(cnt[1] < n >> 1) cnt[1] ++, ans += t, q1.push({a[i][0], a[i][1], a[i][2]});
            else if(cnt[2] < n >> 1) cnt[2] ++, ans += t, q2.push({a[i][0], a[i][1], a[i][2]});
        } else if(t == a[i][0]) {
            if(cnt[0] < n >> 1) cnt[0] ++, ans += t, q0.push({a[i][0], a[i][1], a[i][2]});
            else {
                auto ft = q0.top();
                if(ft.x + max(a[i][1], a[i][2]) > max(ft.y, ft.z) + a[i][0]) {
                    if(a[i][1] > a[i][2]) cnt[1] ++, ans += a[i][1], q1.push({a[i][0], a[i][1], a[i][2]});
                    else cnt[2] ++, ans += a[i][2], q2.push({a[i][0], a[i][1], a[i][2]});
                } else {
                    q0.pop();
                    q0.push({a[i][0], a[i][1], a[i][2]});
                    ans -= ft.x, ans += a[i][0];
                    if(ft.y > ft.z) cnt[1] ++, ans += ft.y, q1.push({ft.x, ft.y, ft.z});
                    else cnt[2] ++, ans += ft.z, q2.push({ft.x, ft.y, ft.z});
                }
            }
        } else if(t == a[i][1]) {
            if(cnt[1] < n >> 1) cnt[1] ++, ans += t, q1.push({a[i][0], a[i][1], a[i][2]});
            else {
                auto ft = q1.top();
                if(ft.y + max(a[i][0], a[i][2]) > max(ft.x, ft.z) + a[i][1]) {
                    if(a[i][0] > a[i][2]) cnt[0] ++, ans += a[i][0], q0.push({a[i][0], a[i][1], a[i][2]});
                    else cnt[2] ++, ans += a[i][2], q2.push({a[i][0], a[i][1], a[i][2]});
                } else {
                    q1.pop();
                    q1.push({a[i][0], a[i][1], a[i][2]});
                    ans -= ft.y, ans += a[i][1];
                    if(ft.x > ft.z) cnt[0] ++, ans += ft.x, q0.push({ft.x, ft.y, ft.z});
                    else cnt[2] ++, ans += ft.z, q2.push({ft.x, ft.y, ft.z});
                }
            }
        } else {
            if(cnt[2] < n >> 1) cnt[2] ++, ans += t, q2.push({a[i][0], a[i][1], a[i][2]});
            else {
                auto ft = q2.top();
                if(ft.z + max(a[i][0], a[i][1]) > max(ft.x, ft.y) + a[i][2]) {
                    if(a[i][0] > a[i][1]) cnt[0] ++, ans += a[i][0], q0.push({a[i][0], a[i][1], a[i][2]});
                    else cnt[1] ++, ans += a[i][1], q1.push({a[i][0], a[i][1], a[i][2]});
                } else {
                    q2.pop();
                    q2.push({a[i][0], a[i][1], a[i][2]});
                    ans -= ft.z, ans += a[i][2];
                    if(ft.x > ft.y) cnt[0] ++, ans += ft.x, q0.push({ft.x, ft.y, ft.z});
                    else cnt[1] ++, ans += ft.y, q1.push({ft.x, ft.y, ft.z});
                }
            }
        }
        // cerr << "ans = " << ans << '\n';
    }
    cout << ans << '\n';
}
/*
1
6
5 7 6
4 0 7
3 6 1
2 1 0
2 5 1
1 7 2
*/
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T --) {
        solve();
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
//freopen("club.in", "r", stdin);
6KB T1 wcwcwc
*/
