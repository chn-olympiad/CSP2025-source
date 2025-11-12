#include<iostream>
using namespace std;

const bool DB = 0;
const int M = 998244353;
bool d[505];
//timunandu
int c[505], m, n;

int s[505], vis[505], f, ans;
//f:beitaotaiderenshu
void dfs(int dep) {
    //printf("%d %d\n", dep, f);
    if ((dep == n + 1) && (n - f >= m)) {
        ++ans;
        return;
    }
    for (int j = 1; j <= n; ++j) {
        if (vis[j]) continue;
        vis[j] = 1;
        int flag = 0;
        if ((f >= c[j]) || (d[dep] == 0)) {
            ++f; flag = 1;
        }
        dfs(dep + 1);
        vis[j] = 0;
        if (flag) {
            --f;
        }
    }
    return;
}

int main() {
    if (!DB) {
        freopen("employ.in", "r", stdin);
        freopen("employ.out", "w", stdout);
    }
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i) {
        cin >> ch;
        if (ch == '1') {
            d[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    dfs(1);
    cout << ans;
}
