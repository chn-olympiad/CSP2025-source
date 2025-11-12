#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ans, c[16];
string s;
vector<int> now;
bool use[16];

bool check(){
    int t = 0;
    for (int i = 0; i < n; i++){
        if (t >= now[i] || s[i] == '0')
            t++;
    }
    return n - t >= m;
}

void dfs(int dep){
    if (dep == n){
        ans += check();
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!use[i]){
            use[i] = true, now.push_back(c[i]);
            dfs(dep + 1);
            use[i] = false, now.pop_back();
        }
    }
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += s[i] == '0';
    if (n - cnt < m){
        cout << 0;
        return 0;
    }
    if (n > 15){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            cnt += x == 0;
        }
        if (n - cnt >= m){
            ans = 1;
            for (int i = 1; i <= n; i++)
                ans = (ans * i) % 998244353;
            cout << ans;
        }
        else
            cout << 0;
    }
    else {
        for (int i = 1;i <= n; i++)
            cin >> c[i];
        dfs(0);
        cout << ans;
    }
    return 0;
}
