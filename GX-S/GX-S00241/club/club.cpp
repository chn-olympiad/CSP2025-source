#include<bits/stdc++.h>
using namespace std;
int n, t;
struct node{
    int x, y, z;
}a[100005];
int s[5], ans, res;
void dfs(int p, int q){
    if (p > n) {
        res = max(ans, res);
        return;
    }
    for (int i = 1; i <= 3; i++){
        if (s[1] >= n / 2 && i == 1) continue;
        if (s[2] >= n / 2 && i == 2) continue;
        if (s[3] >= n / 2 && i == 3) continue;
        s[i]++;
        if (i == 1) ans += a[p].x;
        else if (i == 2) ans += a[p].y;
        else if (i == 3) ans += a[p].z;
        dfs(p + 1, i);
        if (i == 1) ans -= a[p].x;
        else if (i == 2) ans -= a[p].y;
        else if (i == 3) ans -= a[p].z;
        s[i]--;
    }
}
int cmp(node a, node b){
    return a.x > b.x;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        ans = 0, res = 0;
        fill(s + 1, s + 4, 0);
        cin >> n;
        int xx = 0, yy = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            xx += a[i].y;
            yy += a[i].z;
        }
        if (xx == 0 && yy == 0){
            sort(a + 1, a + n + 1, cmp);
            for (int i = 1; i <= n / 2; i++){
                ans += a[i].x;
            }
            cout << ans;
            continue;
        }
        dfs(1, 1);
        cout << res << '\n';
    }
    return 0;
}

