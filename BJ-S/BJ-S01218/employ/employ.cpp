#include<bits/stdc++.h>
using namespace std;
long long c[505];
bool vis[505];
long long cnt, ans;
long long n, m;
string s;
bool flag = true;
const int mod = 998244353;
void dfs(long long x, long long fail) {
    if(x > n) {
        if(n - fail >= m)
            ans++;
        ans %= mod;
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i] == true) {
            continue;
        }
        if(fail >= c[i]) {
            vis[i] = true;
            dfs(x + 1, fail + 1);
            vis[i] = false;
            continue;
        }
        vis[i] = true;
        if(s[x - 1] == '0') dfs(x + 1, fail + 1);
        else dfs(x + 1, fail);
        vis[i] = false;
    }

    return ;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    cnt = n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        if(s[i - 1] != '1') {
            flag = false;
        }
        if(c[i] == 0) {
            cnt--;
        }
    }
    if(cnt < m) {
        cout << 0 << endl;
        return 0;
    }
    if(flag == true){
        ans = 1;
        if(cnt >= m) {
            for(int i = cnt; i > cnt - m; i--) {
                ans *= i;
                ans %= mod;
            }
        }
        cout << ans % mod << endl;
        return 0;
    }
    else if(n <= 500) {
        dfs(1, 0);
        cout << ans % mod << endl;
        return 0;
    }
    return 0;
}
