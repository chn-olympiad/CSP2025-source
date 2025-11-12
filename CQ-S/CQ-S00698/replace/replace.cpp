#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int L = 5e6 + 5;
const int N = 2e5 + 5;
const int del = 5e6;
const ULL P = 131;
int n, q, p[N][2], cf[N];
string s[N][2], t[N][2];
bool speA = true;
ULL pw[L], pre[L][2], h[N][2];
inline void Solve1() {
    for (int i = 1;i <= n;i++) {
        int l = s[i][0].size() - 1;
        for (int j = 1;j <= l;j++) {
            if (s[i][0][j] == 'b')
                p[i][0] = j;
            if (s[i][1][j] == 'b')
                p[i][1] = j;
        }
    }
    for (int i = 1;i <= q;i++) {
        int l = t[i][0].size() - 1;
        int pa, pb;
        for (int j = 1;j <= l;j++) {
            if (t[i][0][j] == 'b')
                pa = j;
            if (t[i][1][j] == 'b')
                pb = j;
        }
        long long ans = 0;
        for (int j = 1;j <= n;j++) {
            int ll = s[j][0].size() - 1;
            if (p[j][0] - p[j][1] == pa - pb && min(p[j][0], p[j][1]) <= min(pa, pb) && max(pa, pb) + (ll - max(p[j][0], p[j][1])) <= l) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    pw[0] = 1;
    for (int i = 1;i <= n;i++)
        pw[i] = pw[i - 1] * P;
    for (int i = 1;i <= n;i++) {
        cin >> s[i][0] >> s[i][1];
        int cnt[2] = { 0,0 };
        for (int j = 0;j < (s[i][0].size());j++)
            if (s[i][0][j] > 'b' || s[i][0][j] > 'b')
                speA = false;
            else {
                cnt[0] += (s[i][0][j] == 'b');
                cnt[1] += (s[i][1][j] == 'b');
            }
        speA &= (cnt[0] == 1 && cnt[1] == 1);
        s[i][0] = "0" + s[i][0];
        s[i][1] = "0" + s[i][1];
    }
    for (int i = 1;i <= q;i++) {
        cin >> t[i][0] >> t[i][1];
        int cnt[2] = { 0,0 };
        for (int j = 0;j < (t[i][0].size());j++)
            if (t[i][0][j] > 'b' || t[i][0][j] > 'b')
                speA = false;
            else {
                cnt[0] += (t[i][0][j] == 'b');
                cnt[1] += (t[i][1][j] == 'b');
            }
        speA &= (cnt[0] == 1 && cnt[1] == 1);
        t[i][0] = "0" + t[i][0];
        t[i][1] = "0" + t[i][1];
    }
    if (speA)
        Solve1();
    else {
        for (int i = 1;i <= n;i++) {
            for (int x = 0;x <= 1;x++) {
                int l = s[i][x].size() - 1;
                for (int j = 1;j <= l;j++)
                    h[i][x] = h[i][x] + (s[i][x][j] - 'a' + 1) * pw[j];
            }
        }
        for (int i = 1;i <= q;i++) {
            int l = t[i][0].size() - 1;
            for (int x = 0;x <= 1;x++) {
                ULL lst = 0;
                for (int j = 1;j <= l;j++) {
                    lst = lst + (t[i][x][j] - 'a' + 1) * pw[j];
                    pre[j][x] = lst;
                }
            }
            long long ans = 0;
            for (int j = 1;j <= l;j++)
                for (int k = 1;k <= n;k++) {
                    int ll = s[k][0].size() - 1;
                    if (ll <= j && (pre[j][0] - pre[j - ll][0] == h[k][0] * pw[j - ll]) && (h[k][1] * pw[j - ll] == (pre[j][1] - pre[j - ll][1])
                        && (pre[j - ll][0] == pre[j - ll][1]) && (pre[l][0] - pre[j][0] == pre[l][1] - pre[j][1]))) {
                        ans++;
                    }
                }
            cout << ans << "\n";
        }
    }
    return 0;
}