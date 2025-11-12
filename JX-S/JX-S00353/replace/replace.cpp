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
const int N = 200005, M = 2005, INF = 1e18;
const int Mod = 1e9 + 7;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x * f;
}

int n, q;
string s1[N], s2[N];
string t1[N], t2[N];
int nxt[M][M];

inline void init_nxt() {
    for (int now = 1; now <= q; now++) {
        int len = s1[now].size();
        string p = s1[now] + ' ';
        for (int i = 2, j = 0; i <= len; i++) {
            while (j && p[i] != p[j + 1]) j = nxt[now][j];
            if (p[i] == p[j + 1]) j++;
            nxt[now][i] = j;
        }
    }
    return ;
}

inline void Solve(string X, string Y) {
    // cout << "NEW" << '\n';
    int len = X.size();
    int ans = 0;
    X = ' ' + X, Y = ' ' + Y;
    for (int i = 1; i <= n; i++) {
        // cout << i << ": " << '\n';
        vector <int> pos; // Find the pos
        int need = s1[i].size();
        string now = ' ' + s1[i];
        string tag = ' ' + s2[i];
        for (int j = 1, k = 0; j <= len; j++) {
            while (k && X[j] != now[k + 1]) k = nxt[i][k];
            if (X[j] == now[k + 1]) k++;
            if (k == need) k = nxt[i][k], pos.pb(j);
        }
        // for (auto v : pos) cout << v << ' ';
        // cout << '\n';
        for (auto v : pos) {
            string P = X;
            for (int j = v - need + 1; j <= v; j++) P[j] = tag[j - (v - need + 1) + 1];
            bool flag = 1;
            for (int j = 1; j <= len; j++) if (P[j] != Y[j]) flag = 0;
            ans += (flag == 1); 
        }
    }
    cout << ans << '\n';
    return ;
}

signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    IO;
    // cout << "CSP-S 2025 RP++" << '\n';
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
    for (int i = 1; i <= q; i++) cin >> t1[i] >> t2[i];

    init_nxt();
    for (int i = 1; i <= q; i++) Solve(t1[i], t2[i]);
    return 0;    
}