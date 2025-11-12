#include <bits/stdc++.h>
#define rep(x, y, z) for (int x = y; x <= z; x++)
using namespace std;
constexpr int N = 1e5 + 514;

namespace Otaku {
    int n, ans, cnt;
    int A, B, C, val[N][4];
    int vis[N];

    struct node {
        int v, id, k;

        bool operator<(const node & o) const { return v > o.v;}
    } a[N * 3];

    priority_queue<int, vector<int>, greater<int>> qA, qB, qC;

    void init() {
        cin >> n;
        cnt = ans = 0;
        A = B = C = 0;
        while (!qA.empty()) qA.pop();
        while (!qB.empty()) qB.pop();
        while (!qC.empty()) qC.pop();

        rep(i, 1, n) {
            rep(j, 1, 3) {
                cin >> val[i][j];
                a[++cnt].v = val[i][j];
                a[cnt].id = i;
                a[cnt].k = j;
            }
            vis[i] = 0;
        }

        sort(a + 1, a + cnt + 1);

        rep(i, 1, cnt) {
            int v = a[i].v, id = a[i].id, k = a[i].k;
            if (vis[id]) continue;

            vis[id] = 1;
            if (k == 1) {
                int sex = max(val[id][2], val[id][3]);
                if (A * 2 != n) {
                    A++;
                    ans += v;
                    qA.push(v - sex);
                }
                else {
                    if (v - sex > qA.top()) {
                        ans = ans - qA.top() + v;
                        qA.pop();
                        qA.push(v - sex);
                    }
                    else ans += sex;
                }
            }
            else if (k == 2) {
                int sex = max(val[id][1], val[id][3]);
                if (B * 2 != n) {
                    B++;
                    ans += v;
                    qB.push(v - sex);
                }
                else {
                    if (v - sex > qB.top()) {
                        ans = ans - qB.top() + v;
                        qB.pop();
                        qB.push(v - sex);
                    }
                    else ans += sex;
                }
            }
            else if (k == 3) {
                int sex = max(val[id][1], val[id][2]);
                if (C * 2 != n) {
                    C++;
                    ans += v;
                    qC.push(v - sex);
                }
                else {
                    if (v - sex > qC.top()) {
                        ans = ans - qC.top() + v;
                        qC.pop();
                        qC.push(v - sex);
                    }
                    else ans += sex;
                }
            }
        }

        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        Otaku::init();
    }

    return 0;
}

// 16.18 finished I am sick