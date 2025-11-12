#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;

struct node {
    int x1, x2, x3;
    bool operator<(const node &x) const {
        int m1 = max({x1, x2, x3}), m3 = min({x1, x2, x3}), m2 = x1 + x2 + x3 - m1 - m3;
        int v1 = max({x.x1, x.x2, x.x3}), v3 = min({x.x1, x.x2, x.x3}), v2 = x.x1 + x.x2 + x.x3 - v1 - v3;
        if (m1 - m2 == v1 - v2) {
            return m1 - m3 > v1 - v3;
        }
        return m1 - m2 > v1 - v2;
    }
} a[MAXN];

int T, n, ans;
priority_queue<node> q1, q2, q3;

inline int read() {
    int f = 1, x = 0;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') {
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar_unlocked();
    }
    return f * x;
}

inline int fdmx(node x) {
    if (x.x1 >= max(x.x2, x.x3)) {
        return 1;
    }
    if (x.x2 >= max(x.x1, x.x3)) {
        return 2;
    }
    return 3;
}

inline int fdmn(node x) {
    if (x.x1 <= min(x.x2, x.x3)) {
        return 1;
    }
    if (x.x2 <= min(x.x1, x.x3)) {
        return 2;
    }
    return 3;
}

inline int fdms(node x) {
    return 6 - fdmx(x) - fdmn(x);
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    T = read();
    while (T--) {
        n = read(), ans = 0;
        for (int i = 1; i <= n; i++) {
            a[i].x1 = read(), a[i].x2 = read(), a[i].x3 = read();
            int pos = fdmx(a[i]);
            if (pos == 1) {
                q1.push(a[i]);
                if (2 * q1.size() > n) {
                    node tmp = q1.top();
                    q1.pop();
                    int pos2 = fdms(tmp);
                    if (pos2 == 1) {
                        pos2 = fdmn(tmp);
                    }
                    if (pos2 == 2) {
                        q2.push(tmp);
                    } else {
                        q3.push(tmp);
                    }
                }
            } else if (pos == 2) {
                q2.push(a[i]);
                if (2 * q2.size() > n) {
                    node tmp = q2.top();
                    q2.pop();
                    int pos2 = fdms(tmp);
                    if (pos2 == 2) {
                        pos2 = fdmn(tmp);
                    }
                    if (pos2 == 1) {
                        q1.push(tmp);
                    } else {
                        q3.push(tmp);
                    }
                }
            } else {
                q3.push(a[i]);
                if (2 * q3.size() > n) {
                    node tmp = q3.top();
                    q3.pop();
                    int pos2 = fdms(tmp);
                    if (pos2 == 3) {
                        pos2 = fdmn(tmp);
                    }
                    if (pos2 == 1) {
                        q1.push(tmp);
                    } else {
                        q2.push(tmp);
                    }
                }
            }
        }
        while (!q1.empty()) {
            ans += q1.top().x1;
            q1.pop();
        }
        while (!q2.empty()) {
            ans += q2.top().x2;
            q2.pop();
        }
        while (!q3.empty()) {
            ans += q3.top().x3;
            q3.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}
