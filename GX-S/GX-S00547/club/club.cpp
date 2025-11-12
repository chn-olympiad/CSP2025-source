#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+9, M = 209;

int T, n, v[N], a[N][5], ans, flag = 0;
int f[M][M][M];
struct Node{
    int w, i;
    bool operator<(const Node B) const {return w < B.w;}
    bool operator>(const Node B) const {return w > B.w;}
};
priority_queue<Node> q, qq, pp;
priority_queue<Node, vector<Node>, greater<Node>> p;
void clean() {
    memset(v, 0, sizeof v);
    memset(a, 0, sizeof a);
    ans = 0;
}
void solve1() {
    memset(f, 0xc0, sizeof f);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n/2; j++) {
            for (int k = 0; k <= n/2; k++) {
                if (j) f[i][j][k] = max(f[i][j][k], f[i-1][j-1][k] + a[i][1]);
                if (k) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-1] + a[i][2]);
                f[i][j][k] = max(f[i][j][k], f[i-1][j][k] + a[i][3]);
            }
        }
    }
    for (int j = 0; j <= n/2; j++) {
        for (int k = 0; k <= n/2; k++) {
            int p = n-j-k;
            if (p > n/2) continue;
            ans = max(ans, f[n][j][k]);
        }
    }
    cout << ans << '\n';
}
void solve2() {
    for (int i = 1; i <= n/2; i++) {ans += a[i][1]; q.push((Node){a[i][2]-a[i][1], i}); v[i]=1;}
                                                // after exchange will lose
    for (int i = n/2+1; i <= n; i++) {ans += a[i][2]; p.push((Node){a[i][2]-a[i][1], i}); v[i]=2;}
    while (n) {
        Node A = q.top(), B = p.top();
        if (A.w > B.w) {
            q.pop(); q.push(B);
            p.pop(); p.push(A);
            ans += A.w-B.w;
            v[A.i] = 2;
            v[B.i] = 1;
        }
        else break;
    }
    while (q.size()) q.pop();
    while (p.size()) p.pop();
    while (q.size()) q.pop();
    cout << ans << '\n';
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        clean();
        cin >> n;
        flag = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
            if (a[i][3]) flag = 0;
        }
        if (flag && n > 200) solve2();
        else solve1();
    }
    return 0;
}
