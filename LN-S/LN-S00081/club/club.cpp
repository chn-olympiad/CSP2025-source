#include <bits/stdc++.h>
#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second

using namespace std;

const int N = 5e5 + 50, p = 998244353;

int n;
int a[N][4], f[205][205][205], b[N][3];

void init() {

}

void chk(int &x, int y) {
    x = max(x, y);
}

void subtask1() {
    memset(f, 128, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n / 2; j++)
            for (int k = 0; k <= n / 2; k++)
                if (f[i][j][k] >= 0)
                    chk(f[i + 1][j + 1][k], f[i][j][k] + a[i + 1][1]),
                    chk(f[i + 1][j][k + 1], f[i][j][k] + a[i + 1][2]),
                    chk(f[i + 1][j][k], f[i][j][k] + a[i + 1][3]);
    int ans = 0;
    for (int i = 0; i <= n / 2; i++)
        for (int j = 0; j <= n / 2; j++)
            if (n - i - j <= n / 2)
                ans = max(ans, f[n][i][j]);
    printf("%d\n", ans);
}

multiset <pii> s[4];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
    if (n <= 200) {
        subtask1();
        return;
    }
    for (int i = 1; i <= n; i++) {
        int top1, top2;
        if (a[i][2] > a[i][1] || (a[i][2] == a[i][1] && s[1].size() < s[2].size())) top2 = 1, top1 = 2;
        else top1 = 1, top2 = 2;
        if (a[i][3] > a[i][top1] || (a[i][3] == a[i][top1] && s[top1].size() < s[3].size())) top2 = top1, top1 = 3;
        else if (a[i][3] > a[i][top2]) top2 = 3;
        b[i][1] = top1, b[i][2] = top2;
        if (s[top1].size() < n / 2) {
            s[top1].insert({a[i][top1], i});
            //cerr << i << " 1" << endl;
        } else {
            int j = s[top1].begin()->se;
            if (a[i][top2] > a[j][b[j][2]] - a[j][b[j][1]] + a[i][top1]) {
                s[top2].insert({a[i][top2], i});
                //cerr << i << " 2" << endl;
            } else {
                s[top1].erase(s[top1].begin());
                s[b[j][2]].insert({a[j][b[j][2]], j});
                s[top1].insert({a[i][top1], i});
                //cerr << i << " 3" << endl;
            }
        }
    }
    int ans = 0;
    while (!s[1].empty()) {
        ans += s[1].begin()->fi;
        s[1].erase(s[1].begin());
    }
    while (!s[2].empty()) {
        ans += s[2].begin()->fi;
        s[2].erase(s[2].begin());
    }
    while (!s[3].empty()) {
        ans += s[3].begin()->fi;
        s[3].erase(s[3].begin());
    }
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    init();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
/*
14
4 1 1
9 2 0
8 4 1
2 8 4
1 5 9
6 9 0
7 5 2
9 6 9
9 0 3
5 8 1
6 4 4
2 1 0
4 8 6
0 3 9
*/
