

#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int MAXI = 509, mod = 998244353;
int n, m;
char s[MAXI];
int a[MAXI];

int b[MAXI];
bool vis[MAXI];

int ans = 0;

void Dfs (int cnt) {
    if (cnt == n) {
        int num = 0;
        for (int i = 1; i <= n; i++)
            if (a[b[i]] <= num || s[i] == '0') num++;
        if (n - num >= m) ans++;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1, b[cnt + 1] = i;
            Dfs(cnt + 1);
            vis[i] = 0;
        }
    }
}

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    Dfs(0);

    cout << ans << '\n';

    return 0;
}
