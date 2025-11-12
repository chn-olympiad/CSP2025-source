#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10;
int a[maxn][3];
int n;
int mx;
int ans;
int vis[maxn];
void dfs1(int sz_a, int lst){
    if(sz_a == mx){
        int sum = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i] == 1){
                sum += a[i][1];
            }
            else{
                sum += a[i][2];
            }
        }
        ans = max(ans, sum);
    }
    for(int i = lst+1;i <= n;i++){
        vis[i] = 1;
        dfs1(sz_a + 1, i);
        vis[i] = 0;
        dfs1(sz_a, i);
    }
}
void dfs(int sz_a, int sz_b, int sz_c, int sm_a, int sm_b, int sm_c, int lst){
    if(sz_a > mx || sz_b > mx || sz_c > mx) return ;
    if(sz_a + sz_b + sz_c == n){
        ans = max(ans, sm_a + sm_b + sm_c);
        return ;
    }
    for(int i = lst+1;i <= n;i++){
        dfs(sz_a + 1, sz_b, sz_c, sm_a + a[i][1], sm_b, sm_c, i);
        dfs(sz_a, sz_b + 1, sz_c, sm_a, sm_b + a[i][2], sm_c, i);
        dfs(sz_a, sz_b, sz_c + 1, sm_a, sm_b, sm_c + a[i][3], i);
    }
}
void solve(){
    cin >> n;
    ans = 0;
    bool flag = true, flag1 = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][2] != 0 || a[i][3] != 0) flag = false;
        if(a[i][3] != 0) flag1 = false;
    }
    mx = n / 2;
    if(flag){
        vector<int> a1;
        for(int i = 1;i <= n;i++){
            a1.push_back(a[i][1]);
        }
        sort(a1.begin(), a1.end());
        int cnt = 1;
        int sum = 0;
        for(int i = n-1;i >= 0;i--){
            if(cnt > mx) break;
            sum += a1[i];
            cnt++;
        }
        cout << sum << endl;
    }
    else if(flag1){
        dfs1(0, 0);
        cout << ans << endl;
    }
    else{
        dfs(0, 0, 0, 0, 0, 0, 0);
        cout << ans << endl;
    }
}
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
