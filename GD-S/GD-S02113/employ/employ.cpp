#include <bits/stdc++.h>

using namespace std;

const int N = 510;
const int MOD = 998244353;
int c[N];
int n, m;
string s;
bool vis[N];
int ret = 0;

void dfs(int now, int lst, int emp) {
//    cout << now << " " << lst << " " << emp << "\n";
    if (now > n) {
//        cout<< " " <<emp << "\n";
        if (emp >= m) ret = (ret + 1) % MOD;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
//        cout << i << "\n";
        if (lst >= c[i] || s[now - 1] == '0') {
            dfs(now + 1, lst + 1, emp);
        } else {
            dfs(now + 1, 0, emp + 1);
        }
        vis[i] = 0;
    }

}

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    int len = s.size();
    bool flag = 1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            flag = 0;
            break;
        }
    }
    if (flag) {
        int cnt = 1;
        for (int i = n; i >= 1; i--) {
            cnt = cnt * n % MOD;
        }
        cout << cnt;
        return 0;
    }
    dfs(1, 0, 0);
    cout << ret;
	return 0;
}
