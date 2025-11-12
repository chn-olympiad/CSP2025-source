#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;
const int mod = 998244353;
int n, m, cnt, ans, a[N], tmp[N];
bool vis[N];
string s;

inline void dfs(int x) {
    if(x == n + 1) {
        int pre = 0, num = 0;

        for(int i = 1 ; i <= n ; ++ i) {
            if(pre >= a[tmp[i]] || s[i] == '0') ++ pre;
            else ++ num;
        }

        if(num < m) return ;

        ++ ans;
        ans %= mod;

        return ;
    }

    for(int i = 1 ; i <= n ; ++ i)
        if(! vis[i]) {
            tmp[x] = i;
            vis[i] = true;

            dfs(x + 1);

            vis[i] = false;
        }

    return ;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> s;
    for(int i = 1 ; i <= n ; ++ i)
        cin >> a[i], cnt += (a[i] != 0);

    s = " " + s;

    if(n <= 10) dfs(1);
    else if(m == 1) {
        ans = 1;

        for(int i = 1 ; i <= n ; ++ i)
            ans = ans * i % mod;
    }

    cout << ans;

    return 0;
}