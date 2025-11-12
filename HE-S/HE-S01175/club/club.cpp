#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 1e5 + 3;
int n;
ll ans;
ll a[MN][4]; // 满意度
int rec[4];

ll b[MN];
bool cmp(int a, int b) { return a > b; }

struct jjj {
    ll val; // 差值
    int tpy; // 类型
    int id; // 编号
    bool operator < (const jjj &x) const { return val > x.val; } // 差值从小到大排序
};
priority_queue<jjj> q[4]; // 换到某类型之后会损失多少

void change(int id, int tt) { // 编号，类型
    ll minn = LONG_LONG_MAX / 2;
    int id1 = 0, id2 = 0;
    for (int i = 1; i <= 3; i++) {
        if (i == tt) continue;
        int tmp = a[id][tt] - a[id][i];
        if (minn > tmp) minn = tmp, id1 = i;
    }
    for (int i = 1; i <= 3; i++) if (i != tt && i != id1) id2 = i;

    int ttp = 0; // (更换)差值最小时id
    ll tcz = LONG_LONG_MAX / 2; // 最小差值
    for (int i = 1; i <= 3; i++) {
        if (i == tt) continue;
        if (tcz > q[i].top().val) ttp = i, tcz = q[i].top().val;
    }
    if (tcz < minn) { // 更换之前的
        // jjj tmp = q[ttp].top();
        rec[ttp]++;
        ans -= tcz;
        q[ttp].pop();
        ans += a[id][tt];
        q[id1].push((jjj){a[id][tt] - a[id][id1], tt, id});
        q[id2].push((jjj){a[id][tt] - a[id][id2], tt, id});
    }
    else { // 直接使用剩下一个,即id1
        rec[id1]++;
        ans += a[id][id1];
        q[id2].push((jjj){a[id][id1] - a[id][id2], id1, id});
    }
}

void dfs(ll sum, int id, int rrc[]) {
    if (id > n) {
        ans = max(ans, sum);
        return ;
    }

    for (int i = 1; i <= 3; i++) {
        if (rrc[i] >= (n >> 1)) continue;
        rrc[i]++;
        dfs(sum + a[id][i], id + 1, rrc);
        rrc[i]--;
    }
}

void fir();
void solve() {
    cin >> n;
    fir();
    int f2 = 0, f3 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 3; j++){
            cin >> a[i][j];
            if (j == 2 && a[i][j] != 0) f2 = 1;
            if (j == 3 && a[i][j] != 0) f3 = 1;
        }

    if (f2 == 0 && f3 == 0) {
        for (int i = 1; i <= n; i++) b[i] = a[i][1];
        sort(b + 1, b + n + 1, cmp);
        for (int i = 1; i <= (n >> 1); i++) ans += b[i];
        return cout << ans << "\n", void();
    }
    if (n <= 10) {
        dfs(0ll, 1, rec);
        cout << ans << "\n";
        return ;
    }

    int m = (n >> 1);
    for (int i = 1; i <= n; i++) {
        ll maxn = -1;
        int td = 1;
        for (int j = 1; j <= 3; j++)
            if (maxn < a[i][j]) maxn = a[i][j], td = j;

        if (rec[td] >= m) { // 出现冲突
            change(i, td);
        }
        else {
            ans += a[i][td];
            rec[td]++;
            for (int j = 1; j <= 3; j++) {
                if (j == td) continue;
                q[j].push((jjj){a[i][td] - a[i][j], td, i});
            }
            
        }
    }

    cout << ans << "\n";
}
inline void fir() {
    memset(rec, 0, sizeof(rec));
    ans = 0;
    while (!q[1].empty()) q[1].pop();
    while (!q[2].empty()) q[2].pop();
    while (!q[3].empty()) q[3].pop();
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
// 做法假了怎么办
// 现在乐观估计本题能获得0pts
// 还有一个题的暴力没打