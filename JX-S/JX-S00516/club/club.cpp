#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'

constexpr int MAXN = 1e5 + 5;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
int n;
int a[MAXN][4], choice[MAXN];
int tosub[MAXN], tot;

void work() {
    cin >> n;
    rep (i, 1, n) rep (j, 1, 3) cin >> a[i][j];
    int sum = 0;
    int cnt[4] = {0};
    rep (i, 1, n) {
        int mx = max(a[i][1], max(a[i][2], a[i][3]));
        sum += mx;
        if (a[i][1] == mx) {
            cnt[1]++;
            choice[i] = 1;
        } else if (a[i][2] == mx) {
            cnt[2]++;
            choice[i] = 2;
        } else {
            cnt[3]++;
            choice[i] = 3;
        }
    }

    int goal;

    if ((goal = max(cnt[1], max(cnt[2], cnt[3]))) > n / 2) {
        goal -= n / 2;
        int cur;
        if (cnt[1] > n / 2) {
            cur = 1;
        } else if (cnt[2] > n / 2) {
            cur = 2;
        } else {
            cur = 3;
        }
        tot = 0;
        rep (i, 1, n) {
            if (choice[i] == cur) {
                tosub[++tot] = INF;
                rep (j, 1, 3) if (j != cur) {
                    tosub[tot] = min(tosub[tot], a[i][cur] - a[i][j]);
                }
            }
        }
        sort(tosub + 1, tosub + tot + 1);
        rep (i, 1, goal) {
            sum -= tosub[i];
        }
    }
    cout << sum << endl;
}

int T;

signed main() {
#ifndef INFTER
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) work();

    return 0;
}