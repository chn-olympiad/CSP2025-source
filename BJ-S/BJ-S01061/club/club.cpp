#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int t, n, res, vis[N];

struct node{
    int A, B, C;
}a[N];

bool cm(node x, node t){
    return x.A > t.A;
}

void dfs(int x, int c1, int c2, int c3){
    if (c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return ;
    if (x > n){
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if (vis[i] == 1) ans += a[i].A;
            else if (vis[i] == 2) ans += a[i].B;
            else ans += a[i].C;
        }
        res = max(res, ans);
        return ;
    }
    vis[x] = 1;
    dfs(x + 1, c1 + 1, c2, c3);
    vis[x] = 2;
    dfs(x + 1, c1, c2 + 1, c3);
    vis[x] = 3;
    dfs(x + 1, c1, c2, c3 + 1);
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--){
        memset(vis, 0, sizeof vis);
        res = -1;
        cin >> n;
        bool spA = true;
        for (int i = 1; i <= n; i++){
            cin >> a[i].A >> a[i].B >> a[i].C;
            if (a[i].B || a[i].C) spA = 0;
        }
        if (spA){
            sort(a + 1, a + n + 1, cm);
            res = 0;
            for (int i = 1; i <= n / 2; i++) res += a[i].A;
            cout << res << '\n';
            continue;
        }
        dfs(1, 0, 0, 0);
        cout << res << '\n';
    }
    return 0;
}