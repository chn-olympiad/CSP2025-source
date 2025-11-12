#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, a[100001][4], vis[100001];
bool cmp(int x, int y){
    return x > y;
}
void function_a(){
    vector<int> p;
    for (int i = 1; i <= n; i++){
        p.push_back(a[i][1]);
    }
    sort (p.begin(), p.end(), cmp);
    for (int i = 0; i < p.size() / 2; i++){
        ans += p[i];
    }
}
void function_b(){
    vector<int> d1;
    vector<int> d2;
    for (int i = 1; i <= n; i++){
        int k = a[i][1] - a[i][2];
        if (k >= 0){
            d1.push_back(k);
            ans += a[i][1];
        } else if (k <= 0){
            d2.push_back(-k);
            ans += a[i][2];
        }
    }
    if (d1.size() < d2.size()) {
        swap(d1, d2);
    }
    sort(d1.begin(), d1.end());
    for (int i = 0; i < (d1.size() - d2.size()) / 2; i++)
        ans -= d1[i];
}
void dfs(int p, int cnt1, int cnt2, int cnt3, int k1, int k2, int k3){
    if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2)
        return ;
    if (p > n){
        ans = max(ans, k1 + k2 + k3);
        return ;
    }
    for (int i = 1; i <= 3; i++){
        vis[p] = i;
        if (i == 1){
            dfs(p + 1, cnt1 + 1, cnt2, cnt3, k1 + a[p][1], k2, k3);
        } else if (i == 2){
            dfs(p + 1, cnt1, cnt2 + 1, cnt3, k1, k2 + a[p][2], k3);
        } else if (i == 3){
            dfs(p + 1, cnt1, cnt2, cnt3 + 1, k1, k2, k3 + a[p][3]);
        }
    }
}
void solve(){
    ans = 0;
    bool flag1 = true, flag2 = true;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            scanf("%d", &a[i][j]);
            if (j == 2 && a[i][j] != 0){
                flag1 = false;
            }
            if (j == 3 && a[i][j] != 0){
                flag2 = false;
            }
        }
    }
    if (flag1 && flag2){
        function_a();
    } else if (flag2){
        function_b();
    } else{
        memset(vis, 0, sizeof(vis));
        dfs(1, 0, 0, 0, 0, 0, 0);
    }
    printf("%d\n", ans);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
