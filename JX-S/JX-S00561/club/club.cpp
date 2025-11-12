#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][4], ans;
bool cmp(int x, int y) {
    return x > y;
}
void dfs(int ans1, int ans2, int ans3, int cnt1, int cnt2, int cnt3, int m) {
    if (m == n) {
        ans = max(ans1 + ans2 + ans3, ans);
        return;
    }
    if (cnt1 == n / 2) {
        dfs(ans1, ans2 + a[m][2], ans3, cnt1, cnt2 + 1, cnt3, m + 1);
        dfs(ans1, ans2, ans3 + a[m][3], cnt1, cnt2, cnt3 + 1, m + 1);
    }
    else if (cnt2 == n / 2) {
        dfs(ans1 + a[m][1], ans2, ans3, cnt1 + 1, cnt2, cnt3, m + 1);
        dfs(ans1, ans2, ans3 + a[m][3], cnt1, cnt2, cnt3 + 1, m + 1);
    }
    else if (cnt3 == n / 2) {
        dfs(ans1, ans2 + a[m][2], ans3, cnt1, cnt2 + 1, cnt3, m + 1);
        dfs(ans1 + a[m][1], ans2, ans3, cnt1 + 1, cnt2, cnt3, m + 1);
    }
    else {
        dfs(ans1 + a[m][1], ans2, ans3, cnt1 + 1, cnt2, cnt3, m + 1);
        dfs(ans1, ans2 + a[m][2], ans3, cnt1, cnt2 + 1, cnt3, m + 1);
        dfs(ans1, ans2, ans3 + a[m][3], cnt1, cnt2, cnt3 + 1, m + 1);
    }
}
void dfs2(int ans1, int ans2, int cnt1, int cnt2, int m) {
    if (m == n) {
        ans = max(ans1 + ans2, ans);
        return;
    }
    if (cnt1 == n / 2) {
        dfs2(ans1, ans2 + a[m][2], cnt1, cnt2 + 1, m + 1);
    }
    else if (cnt2 == n / 2) {
        dfs2(ans1 + a[m][1], ans2, cnt1 + 1, cnt2, m + 1);
    }
    else {
        dfs2(ans1 + a[m][1], ans2, cnt1 + 1, cnt2, m + 1);
        dfs2(ans1, ans2 + a[m][2], cnt1, cnt2 + 1, m + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        bool b1 = 1, b2 = 1, b3 = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
            }
            if (a[i][1] != 0) {
                b1 = 0;
            }
            if (a[i][2] != 0) {
                b2 = 0;
            }
            if (a[i][3] != 0) {
                b3 = 0;
            }
        }
        if (b2 && b3) {
            int aa[n];
            for (int i = 0; i < n; i++) {
                aa[i] = a[i][1];
            }
            sort(aa, aa + n, cmp);
            for (int i = 0; i < n / 2; i++) {
                ans += aa[i];
            }
            cout << ans;
        }
        else if (b3) {
            dfs2(0, 0, 0, 0, 0);
            cout << ans << "\n";
        }
        else {
            dfs(0, 0, 0, 0, 0, 0, 0);
            cout << ans << "\n";
        }
    }
    return 0;
}
