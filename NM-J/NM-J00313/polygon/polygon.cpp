//过于暴力

#include <bits/stdc++.h>
using namespace std;

const int N = 5005, MOD = 998244353;
int a[N], vis[N];
int n;

unordered_set<string> st;

void dfs(int x, int ma, int cnt) {
    if (cnt > ma * 2) {
        string res = "";
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                res += i + '0';
            }
        }
        st.insert(res);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i, max(ma, a[i]),cnt + a[i]);
            vis[i] = 0;
        }
    }
}

int main() {
    freopen("polygon", "r", stdin);
    freopen("polygon", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        dfs(i, a[i], a[i]);
        vis[i] = 0;
    }

    cout << st.size() % MOD;
    return 0;
}