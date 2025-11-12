#include <bits/stdc++.h>
using namespace std;

const int N = 500, mod = 998244353;
int a[N], cnt, n, m, b[N];
bool vis[N];
long long ans;
string s;
void dfs(int x){
    if(x > n){
        int temp = 0, cnt_ans = 0;//temp 被拒绝
        for (int i = 1;i <= n;i++){
            if (temp >= b[i]){
                temp++;
                continue;
            }
            else if (s[i] == '0') {
                temp++;
                continue;
            }
            else cnt_ans++;
        }
        if (cnt_ans >= m) ans = (ans + 1) % mod;
        return ;
    }
    for(int i = 1;i <= n;i++){
        if (!vis[i]){
            vis[i] = true;
            b[x] = a[i];
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = "?" + s;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i]) cnt++; 
    }
    bool flag = true;
    if (m == 1){
        ans = 1;
        for (int i = 1;i <= cnt;i++) ans = (ans * i % mod) % mod;
        cout << ans % mod << endl;
    }
    else{
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}