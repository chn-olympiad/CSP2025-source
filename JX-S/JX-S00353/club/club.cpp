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
const int N = 255, M = 200005, INF = 1e18;
const int Mod = 1e9 + 7;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') f = (ch == '-' ? -f : f), ch = getchar();
    while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch - '0'), ch = getchar();
    return x * f;
}

inline bool cmp(PII X, PII Y) {
    return X.se > Y.se;
}

inline bool cmp1(int x, int y) {
    return x > y;
}

int T;
int n;
int a[M][3], ano[M];
int dp[N][N][N];
int delta[M];
PII del[M];
bool vis[M];
struct Node {
    int x, val;
    inline bool operator < (const Node &P) const {
        return val > P.val;
    }
};

inline bool cmp2(PII X, PII Y) {
    return X.fi > Y.fi;
}

inline void Solve() {
    // cnt = 0;
    cin >> n;
    if (n <= 210) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) cin >> a[i][j];
        mem (dp, -0x3f);
        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, n / 2); j++)
                for (int k = 0; k <= min(i, n / 2); k++) {
                    if (i - j - k <= n / 2) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + a[i][3]);
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + a[i][1]);
                    if (k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][2]);
                }
        }

        int ans = 0;
        for (int j = 0; j <= n / 2; j++)
            for (int k = 0; k <= n / 2; k++)
                if (n - j - k <= n / 2) ans = max(ans, dp[n][j][k]);
        cout << ans << '\n';
    }
    else {
        bool A = 1, B = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++) {
                cin >> a[i][j];
                if (j != 1 && a[i][j] > 0) A = 0;
                if (j == 3 && a[i][j] > 0) B = 0;
            }
        if (A) {
            for (int i = 1; i <= n; i++) ano[i] = a[i][1];
            sort(ano + 1, ano + n + 1);
            int ans = 0;
            for (int i = n; i > n / 2; i--) ans += ano[i];
            cout << ans << '\n';
        }
        else if (B) { // Use Greedy
            int ans = 0;
            for (int i = 1; i <= n; i++) ans += a[i][1], delta[i] = a[i][2] - a[i][1];
            sort(delta + 1, delta + n + 1, cmp1);
            for (int i = 1; i <= n / 2; i++) ans += delta[i];
            cout << ans << '\n';
        }
        else { // Random Case, Use Greedy
            // cout << "!C" << '\n';
            int t[4];
            t[1] = t[2] = t[3] = 0;
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                PII tmp[5];
                tmp[1] = {1, a[i][1]};
                tmp[2] = {2, a[i][2]};
                tmp[3] = {3, a[i][3]};
                sort(tmp + 1, tmp + 3 + 1, cmp);
                if (t[tmp[1].fi] < n / 2) t[tmp[1].fi]++, ans += tmp[1].se;
                else if (t[tmp[2].fi] < n / 2) t[tmp[2].fi]++, ans += tmp[2].se;
                else t[tmp[3].fi]++, ans += tmp[3].se;
            }
            cout << ans << '\n';

            // int ans = 0;
            // for (int i = 1; i <= n; i++) ans += a[i][1], del[i] = {a[i][2] - a[i][1], i};
            // sort(del + 1, del + n + 1, cmp2);
            // for (int i = 1; i <= n / 2; i++) vis[del[i].se] = 1, ans += del[i].fi;
            // vector <int> CA, CB;
            // for (int i = 1; i <= n; i++) {
            //     if (vis[i] == 1) CB.pb(i);
            //     else CA.pb(i); 
            // }
            // set <Node> AC, BC;
            // for (auto v : CA) AC.insert((Node){v, a[v][3] - a[v][1]});
            // for (auto v : CB) BC.insert((Node){v, a[v][3] - a[v][2]});
            // set <Node> BA, AB;
            // for (auto v : CA) AB.insert((Node){v, a[v][2] - a[v][1]});
            // for (auto v : CB) BA.insert((Node){v, a[v][1] - a[v][2]});
            // for (int i = 1; i <= n; i++) vis[i] = 0;

            // int nt = 0;
            // while (nt <= n / 2 && (AC.size() || BC.size())) {
            //     int ti = 2;
            //     if ((AC.size() && (*(AC.rbegin())).val < 0) || !AC.size()) ti--;
            //     if ((BC.size() && (*(BC.rbegin())).val < 0) || !BC.size()) ti--;
            //     if (!ti) break;
            //     Node maxx1 = {-INF, -INF}, maxx2 = {-INF, -INF};
            //     if (AC.size()) maxx1 = *AC.rbegin();
            //     if (BC.size()) maxx2 = *BC.rbegin();
            //     if (maxx1.val > maxx2.val) { // A -> C
            //         ans += maxx1.val;
            //         AC.erase(AC.find(maxx1));
            //         vis[maxx1.x] = 1;
            //         // CAN B -> A;
            //         while (BA.size() && vis[(*(BA.rbegin())).x] == 1) BA.erase(prev(BA.begin()));
            //         if (BA.size() && (*(BA.rbegin())).val > 0) {
            //             Node now = *BA.rbegin();
            //             ans += now.val;
            //             BA.erase(BA.find(now));
            //             BC.erase(BC.find((Node){now.x, a[now.x][3] - a[now.x][2]}));
            //             AC.insert((Node){now.x, a[now.x][3] - a[now.x][1]});
            //         }
            //     }
            //     else { // B -> C
            //         ans += maxx2.val;
            //         BC.erase(BC.find(maxx2));
            //         vis[maxx2.x] = 1;
            //         // CAN A -> B;
            //         while (AB.size() && vis[(*(AB.rbegin())).x] == 1) AB.erase(prev(AB.end()));
            //         if (AB.size() && (*(AB.rbegin())).val > 0) {
            //             Node now = *AB.rbegin();
            //             ans += now.val;
            //             AB.erase(AB.find(now));
            //             AC.erase(AC.find((Node){now.x, a[now.x][3] - a[now.x][1]}));
            //             BC.insert((Node){now.x, a[now.x][3] - a[now.x][2]});
            //         }
            //     }
            // }
            // cout << ans << '\n';
        }
    }
    return ;
}

signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    IO;
    // cout << "CSP-S 2025 RP++" << '\n';
    cin >> T;
    while (T--) Solve();
    return 0;    
}