#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define LL long long
#define mem(a, b) memset(a, b, sizeof a)
#define PII pair<int, int> 
#define PDD pair<double, double>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define Array(a) vector<array<int, a>>

using namespace std;

const double eps = 1e-8;
const int N = 505, M = 500005, INF = 1e18;
const int Mod = 998244353;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x * f;
}

int n, m;
char ch[N];
int c[N];
int p[N];
bool vis[N];
int ans = 0;

inline void WorkA() {
    int res = 1;
    for (int i = 1; i <= n; i++) res = res * i % Mod;
    cout << res << '\n';
    return ;
}

inline void dfs(int dep, int no, int res) {
    if (dep == n) {
        ans += (res >= m);
        // if (res >= m) {
        //     cout << "OK!" << '\n';
        //     for (int i = 1; i <= n; i++) cout << p[i] << " ";
        //     cout << '\n';
        // } 
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p[dep + 1] = i;
            vis[i] = 1;
            if (no >= c[i]) dfs(dep + 1, no + 1, res);
            else if (ch[dep + 1] == '1') dfs(dep + 1, no, res + 1);
            else dfs(dep + 1, no + 1, res);
            vis[i] = 0;
        }
    }
    return ;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    IO;
    // cout << "CSP-S 2025 RP++" << '\n';
    cin >> n >> m;
    bool tagA = 1;
    for (int i = 1; i <= n; i++) {
        cin >> ch[i];
        if (ch[i] == '0') tagA = 0;
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    dfs(0, 0, 0);
    cout << ans << '\n';
    return 0;    
}