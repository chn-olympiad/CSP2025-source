#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int t, n, a[100005][4], ans, flg, sm, flg2;
priority_queue<int> q;
void dfs(int pos, int c1, int c2, int c3, int sm){
    if (pos == n + 1){
        ans = max(ans, sm);
        return;
    }
    if (c1 < n / 2) dfs(pos + 1, c1 + 1, c2, c3, sm + a[pos][1]);
    if (c2 < n / 2) dfs(pos + 1, c1, c2 + 1, c3, sm + a[pos][2]);
    if (c3 < n / 2) dfs(pos + 1, c1, c2, c3 + 1, sm + a[pos][3]);
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--){
        cin >> n;
        ans = 0;
        flg = flg2 = 1;
        while (!q.empty()) q.pop();
        for (int i = 1; i <= n; i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            q.push(a[i][1]);
            if (a[i][2] || a[i][3]) flg = 0;
            if (a[i][3]) flg2 = 0;
        }
        if (flg){
            sm = 0;
            for (int i = 1; i <= n / 2; i++) sm += q.top(), q.pop();
            cout << sm << "\n";
            continue;
        }
        if (flg2){

        }
        dfs(1, 0, 0, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}

