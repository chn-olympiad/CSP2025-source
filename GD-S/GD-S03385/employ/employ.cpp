#include <iostream>
#include <bitset>
#define MAXN 510
#define MOD 998244353
using namespace std;

int n, m;
char s[MAXN];
int c[MAXN];
bitset<MAXN> state;
int dfs(int day, int cur, int refuse) {
    if (day == n - 1) {
        if (s[day] == '0' || refuse >= c[cur]) return 0;
        return 1;
    }

    if (n - refuse < m) {
        // 招不够 m 人
        return 0;
    }

    int result = 0;

    state[cur] = true;
    for (int i = 1; i <= n; i++) {
        if (state[i]) continue;
        result = (result + dfs(day + 1, i, refuse + 1)) % MOD;
        if (s[day] == '1' && refuse < c[cur]) {
            result = (result + dfs(day + 1, i, refuse)) % MOD;
        }
    }
    state[cur] = false;

    return result % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    int ans;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dfs(0, i, 0)) % MOD;
    }

    cout << ans % MOD << '\n';

    return 0;
}