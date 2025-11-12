#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int t, n, m, mx = -1e9;
int cntq[N][5];
int cnt[N * 3];
bool A = true, B = true;
struct node {
    int j1, j2, j3;
};
node a[N];

bool cmp(node x,node y) {
    if (x.j1 != y.j1) return x.j1 > y.j1;
    else if (x.j2 != y.j2) return x.j2 > y.j2;
    else return x.j3 > y.j3;
}

int dfs(int now, int cnt, int ans, int jj1, int jj2, int jj3, int n) {
    int l1, l2, l3;
    if (now > n) {
        mx = max(mx, ans);
        //cout << cnt << ": " << jj1 << " " << jj2 << " " << jj3 << " " << ans << ": " << mx << "\n";
        return mx;
    }
    if (cnt == 1 && jj1 < n / 2) {
        jj1++;
        ans += a[now].j1;
    }
    if (cnt == 2 && jj2 < n / 2) {
        jj2++;
        ans += a[now].j2;
    }
    if (cnt == 3 && jj3 < n / 2) {
        jj3++;
        ans += a[now].j3;
    }
    for (int i = 1; i <= 3; i++) {
        dfs(now + 1, i, ans, jj1, jj2, jj3, n);
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].j1 >> a[i].j2 >> a[i].j3;
            if (a[i].j2 != 0 || a[i].j3 != 0) A = false;
        }
        if (A) {
            sort(a + 1, a + n + 1, cmp);
            int suma = 0;
            for (int i = 1; i <= n / 2; i++) {
                suma += a[i].j1;
            }
            cout << suma << "\n";
        }
        else {
            mx = -1e9;
            int xx1 = dfs(1, 1, 0, 0, 0, 0, n);
            int xx2 = dfs(1, 2, 0, 0, 0, 0, n);
            int xx3 = dfs(1, 3, 0, 0, 0, 0, n);
            cout << max({xx1, xx2, xx3}) << "\n";
        }
    }
    return 0;
}