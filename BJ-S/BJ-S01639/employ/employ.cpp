#include <iostream>
#include <string>
using namespace std;
const int MOD = 998244353;
int n, m, c[505], a[505], ans;
string s;
void dfs(int step, int f, int ss){
    if (step == n + 1){
        if (ss >= m) ans = (ans + 1) % MOD;
        return ;
    }
    for (int i = 1; i <= n; i ++){
        if (a[i]) continue;
        int lastf = f, lastss = ss;
        if (f >= c[i] || s[step] == '0') f ++;
        else ss ++;
        if (m > n - step + ss) {
            f = lastf, ss = lastss;
            continue;
        }
        a[i] = 1;
        //cout << step << " " << f << " " << ss << " " << i << endl;
        dfs(step + 1, f, ss);
        a[i] = 0;
        f = lastf, ss = lastss;
    }
    return ;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    s = " " + s;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    if (n <= 18){
        dfs(1, 0, 0);
        cout << ans << endl;
        return 0;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i ++)
        cnt1 += (c[i] == 0);
    for (int i = 1; i <= n; i ++)
        cnt2 += (s[i] == '0');
    if (max(cnt1, cnt2) > n - m){
        cout << 0 << endl;
        return 0;
    }
    long long ans = 1;
    for (int i = 2; i <= n; i ++)
        ans = (ans * i) % MOD;
    cout << ans << endl;
    return 0;
}
