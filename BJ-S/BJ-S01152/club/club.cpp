#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, ans;
int a[N][4], sum[4], cnt[4];
int a1[N], a2[N], a3[N];
 
void dfs(int step, int sum, int cnt1, int cnt2, int cnt3) {
    if (step > n) {
        ans = max(ans, sum);
        return;
    }
    if (cnt1 < n / 2)
        dfs(step + 1, sum + a[step][1], cnt1 + 1, cnt2, cnt3);
    if (cnt2 < n / 2)
        dfs(step + 1, sum + a[step][2], cnt1, cnt2 + 1, cnt3);
    if (cnt3 < n / 2)
        dfs(step + 1, sum + a[step][3], cnt1, cnt2, cnt3 + 1);
}

inline int MaxId(int a, int b, int c) {
    if (a > b && a > c) return 1;
    else if (b > a && b > c) return 2;
    return 3;
}

inline int MinId(int a, int b, int c) {
    if (a < b && a < c) return 1;
    else if (b < a && b < c) return 2;
    return 3;
}

inline int MidId(int a, int b, int c) {
    int midn = a + b + c - max({a, b, c}) - min({a, b, c});
    if (midn == a) return 1;
    else if (midn == b) return 2;
    return 3; 
}

struct Node {
    int d, a, b;
}tmp[N];

struct Node2 {
    int x, y, z;
    int maxn;
}ak[N];

bool cmp2(Node2 x, Node2 y) {
    return x.maxn > y.maxn;
}

bool cmp(Node x, Node y) {
    return x.d > y.d;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        memset(sum, 0, sizeof sum);
        bool flagA = 1, flagB = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 3; ++j) {
                cin >> a[i][j];
                sum[j] += a[i][j];
                flagA = flagA && (a[i][2] == 0 && a[i][3] == 0);
                flagB = flagB && (a[i][3] == 0);
                a1[i] = a[i][1];
                a2[i] = a[i][2];
                a3[i] = a[i][3];
                ak[i].x = a[i][1], ak[i].y = a[i][2], ak[i].z = a[i][3];
                ak[i].maxn = max({a[i][1], a[i][2], a[i][3]});
            }
        if (n <= 10) {
            ans = -1e9;
            dfs(1, 0, 0, 0, 0);
            cout << ans << endl;
            continue;
        }
        if (flagA) {
            sort(a1 + 1, a1 + n + 1, greater<int>());
            int ret = 0;
            for (int i = 1; i <= n / 2; ++i)
                ret += a1[i];
            cout << ret << endl;
            continue;
        }
        if (flagB) {
            int ret = 0;
            for (int i = 1; i <= n; ++i)
                tmp[i] = Node{abs(a1[i] - a2[i]), a1[i], a2[i]};
            sort(tmp + 1, tmp + n + 1, cmp);
            int ans = 0, cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; ++i) {
                if (tmp[i].a > tmp[i].b) {
                    if (cnt1 < n / 2)
                        ret += tmp[i].a, cnt1++;
                    else
                        ret += tmp[i].b, cnt2++; 
                }
                else {
                    if (cnt2 < n / 2)
                        ret += tmp[i].b, cnt2++;
                    else
                        ret += tmp[i].a, cnt1++;
                }
            }
            cout << ret << endl;
            continue;
        }
        sort(ak + 1, ak + n + 1, cmp2);
        for (int i = 1; i <= n; ++i) {
            a[i][1] = ak[i].x;
            a[i][2] = ak[i].y;
            a[i][3] = ak[i].z;
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            
            if (a[i][1] == a[i][2] && a[i][2] == a[i][3]) {
                int mn = MinId(sum[1], sum[2], sum[3]);
                int mx = MaxId(sum[1], sum[2], sum[3]);
                int md = MidId(sum[1], sum[2], sum[3]);
                res += a[i][1];
                if (cnt[mn] < n / 2) {
                    cnt[mn]++;
                    sum[mn] -= a[i][1];
                }
                else if (cnt[md] < n / 2) {
                    cnt[md]++;
                    sum[md] -= a[i][1];
                }
                else {
                    cnt[mx]++;
                    sum[mx] -= a[i][1];
                }
            }   
            else if (a[i][1] == a[i][2]) {
                ans += a[i][1];
                int mn = MinId(sum[1], sum[2], 1e9);
                int md = (mn == 1 ? 2 : 1);
                if (cnt[mn] < n / 2) {
                    cnt[mn]++;
                    sum[mn] -= a[i][1];
                }
                else {
                    cnt[md]++;
                    sum[md] -= a[i][1];
                }
            }
            else if (a[i][1] == a[i][3]) {
                ans += a[i][1];
                int mn = MinId(sum[1], 1e9, sum[3]);
                int md = (mn == 1 ? 3 : 1);
                if (cnt[mn] < n / 2) {
                    cnt[mn]++;
                    sum[mn] -= a[i][1];
                }
                else {
                    cnt[md]++;
                    sum[md] -= a[i][1];
                }
            }
            else if (a[i][2] == a[i][3]) {
                ans += a[i][2];
                int mn = MinId(1e9, sum[2], sum[3]);
                int md = (mn == 2 ? 3 : 2);
                if (cnt[mn] < n / 2) {
                    cnt[mn]++;
                    sum[mn] -= a[i][2];
                }
                else {
                    cnt[md]++;
                    sum[md] -= a[i][2];
                }
            }
            else {
                int mn = MinId(a[i][1], a[i][2], a[i][3]);
                int mx = MaxId(a[i][1], a[i][2], a[i][3]);
                int md = MidId(a[i][1], a[i][2], a[i][3]);
                if (cnt[mx] < n / 2) {
                    cnt[mx]++;
                    ans += a[i][mx];
                    sum[mx] -= a[i][mx];
                }
                else if (cnt[md] < n / 2) {
                    cnt[md]++;
                    ans += a[i][md];
                    sum[md] -= a[i][md];
                }
                else {
                    cnt[mn]++;
                    ans += a[i][mn];
                    sum[mn] -= a[i][mn];
                }
            }
        }
    }
    return 0;
}