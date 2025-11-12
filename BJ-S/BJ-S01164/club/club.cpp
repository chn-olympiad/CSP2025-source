#include<bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005], n, ans = 0;
bool f1[205][105], f2[205][105], f3[205][105], f = 1;
void dfs(int pos, int x, int y, int z, int sum){
    if (pos == n + 1){
        ans = max(ans, sum);
        return ;
    }
    if (x >= 1) dfs(pos + 1, x - 1, y, z, sum + a1[pos]);
    if (y >= 1) dfs(pos + 1, x, y - 1, z, sum + a2[pos]);
    if (z >= 1) dfs(pos + 1, x, y, z - 1, sum + a3[pos]);
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T; cin >> T;
    while (T--){
        cin >> n;
        ans = 0;
        bool f_1 = 1;
        for (int i = 1; i <= n; i++){
            cin >> a1[i] >> a2[i] >> a3[i];
            if (a2[i] != 0) f_1 = 0;
            if (a3[i] != 0) f_1 = 0;
        }
        if (n <= 20) dfs(0, n / 2, n / 2, n / 2, 0);
        else{
            if (f_1){
                sort(a1 + 1, a1 + n + 1);
                for (int i = n; i >= n / 2 + 1; i--) ans += a1[i];
            }
            else{
                for (int i = 1; i <= n; i++){
                    ans += max(a1[i], max(a2[i], a3[i]));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
