#include<bits/stdc++.h>
using namespace std;
int a[100005], b[100005], c[100005], n, maxn = 0;//, cnt1 = 0, cnt2 = 0, cnt3 = 0;
bool cmp(int x, int y) {
    return x > y;
}
void dfs(int sum, int p, int cnt1, int cnt2, int cnt3) {
    if (p == n) {
        maxn = max(maxn, sum);
        return ;
    }

    if (cnt1 < n / 2) {
        //cnt1++;
        dfs(sum + a[p + 1], p + 1, cnt1 + 1, cnt2, cnt3);
        //cnt1--;
        //cout << a[p] << endl;
    }
    if (cnt2 < n / 2) {
        //cnt2++;
        dfs(sum + b[p + 1], p + 1, cnt1, cnt2 + 1, cnt3);
        //cnt2--;
    }
    if (cnt3 < n / 2) {
        //cnt3++;
        dfs(sum + c[p + 1], p + 1, cnt1, cnt2, cnt3 + 1);
    }
}
int main () {
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        //int n;
        //cnt1 = 0;
        //cnt2 = 0;
        //cnt3 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        dfs(0, 0, 0, 0, 0);
        cout << maxn << '\n';
        maxn = 0;
    }
    return 0;
}
