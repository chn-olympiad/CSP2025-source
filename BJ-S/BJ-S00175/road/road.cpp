#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 发布时间      标题
// 15:02        S组解压密码
// 10-31 18:50	CSPJS考场常见问题解答
const int maxn = 1e4 + 10, maxm = 1e6 + 10, inf = 1e9 + 100;
struct node {
    int u, v, w;
    bool operator < (const node &b) const { return w < b.w; }
} e[maxm];
int fa[maxn], c[maxn], a[20][maxn];
int vis[20][maxn], mn[20], mn2[20], p[20], que[maxn], t;
int get(int x) { return (vis[x][0] ? 0 : c[x]) + (vis[x][t] ? 0 : (t == mn[x] ? a[x][t] + a[x][mn2[x]] : (vis[x][mn[x]] ? a[x][t] : a[x][t] + a[x][mn[x]]))); }
bool cmp(int x, int y) {
    int sx = get(x), sy = get(y);
    return sx < sy;
}
void init(int n) { for (int i = 1; i <= n; i++) fa[i] = i; }
int find(int x) { return x == fa[x] ? fa[x] : fa[x] = find(fa[x]); }
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    (fx != fy ? fa[fx] = fy : 0);
}
// Emacs(GUI)，点击Tools，点击Games，全是小游戏，可以随便玩
// FireFox，右键顶部标签栏，点击定制(C)...，把除了弹性空白的其它东西都拖进折叠菜单，点击下面新出现的独角兽，乒乓游戏
// 唉不是怎么虚拟机可以直接拖走阿
// 把虚拟机最小化直接露windows了
// 直接玩谷歌小恐龙
// 被小恐龙薄纱了55
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    init(n);
    int cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx != fy) {
            merge(e[i].u, e[i].v);
            ans += e[i].w, que[++cnt] = i;
            if (cnt == n - 1) break;
        }
    }
    if (!k) cout << ans;
    else {
        bool f = 1;
        for (int i = 1; i <= k; i++) {
            cin >> c[i];
            if (c[i]) f = 0;
            int minn = inf;
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (a[i][j] < minn) minn = a[i][j], mn[i] = j;
            }
            minn = inf;
            for (int j = 1; j <= n; j++) {
                if (j == mn[i]) continue;
                else if (a[i][j] < minn) minn = a[i][j], mn2[i] = j;
            }
        }
        for (int i = 1; i <= k; i++) p[i] = i;
        if (f) cout << 0;
        else {
            // 考试的时候类似糖巧的新歌一直在脑子里放
            // 好像叫什么目击！teto31世，后面忘了
            // 惩罚你考完试就上架wyy（qwq

            // 不会正解是不是废了
            // 这可是T2
            // 我死了
            for (int i = 1; i <= cnt; i++) {
                ans -= e[i].w, t = e[i].u;
                sort(p + 1, p + k + 1, cmp);
                int sum = get(p[1]);
                if (sum <= e[i].w) {
                    ans += sum;
                    if (!vis[x][0]) vis[x][0] = 1;
                    vis[x][t] = 1;
                    if (t == mn[x]) vis[x][mn2[x]] = 1;
                    else vis[x][mn[x]] = 1;
                }
                else ans += e[i].w;
            }
            cout << ans;
        }
    }
    return 0;
}