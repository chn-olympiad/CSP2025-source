#include <bits/stdc++.h>
using namespace std;
int n, m, a[510], vis[510], b[510], ans;
const int mod = 998244353;
string s;
void dfs(int x){
    if (x > n){
        int y = 0;
        for (int i = 1; i <= n; i++){
            if (y >= a[b[i]] || s[i-1] == '0') y++;
        }
        if (n-y >= m) ans++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        b[x] = i;
        dfs(x+1);
        vis[i] = 0;
    }
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1);
    cout << ans;
	return 0;
}
