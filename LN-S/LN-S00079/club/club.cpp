#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
int test, n, ans, c[N], a1[N],a2[N],a3[N];

inline void dfs(int i, int c1, int c2, int c3) {
    if (i == n + 1) {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum += c[j];
        ans = max(ans, sum);
        return;
    }
    if (c1 < n / 2) {
        c[i] = a1[i];
        dfs(i + 1, c1 + 1, c2, c3);
    }
    if (c2 < n / 2) {
        c[i] = a2[i];
        dfs(i + 1, c1, c2 + 1, c3);
    }
    if (c3 < n / 2) {
        c[i] = a3[i];
        dfs(i + 1, c1, c2, c3 + 1);
    }
}

inline void solve() {
    scanf("%d", &n);
    int c1 = 0, c2 = 0, c3 = 0;
    bool oka = 1, okb = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
        if (a2[i] || a3[i])
            oka = 0;
        if (a3[i])
            okb = 0;
    }
    ans = 0;
    if (n <= 10) {
        memset(c, 0, sizeof(c));
        dfs(1, 0, 0, 0);
        printf("%d\n", ans);
        return;
    }
    if (oka) {
        sort(a1 + 1, a1 + n + 1, greater<int>());
        for (int i = 1; i <= n / 2; i++)
            ans += a1[i];
        printf("%d\n", ans);
        return;
    }
    for (int i = 1; i <= n; i++) {
        int ma = max({a1[i], a2[i], a3[i]});
        if (ma == a1[i]) c1++;
        else if (ma == a2[i]) c2++;
        else c3++;
        ans += ma;
    }
    if (2 * c1 > n) {
        int x = c1 - n / 2;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++) {
            if (-a2[i] < -a3[i])
                v.push_back({a1[i]-a2[i],2});
            else
                v.push_back({a1[i]-a3[i],3});
        }
        sort(v.begin(), v.end());
        c1 -= x;
        for (int i = 0; i < x; i++) {
            ans = ans - v[i].first;
            if (v[i].second == 2)
                c2++;
            else
                c3++;
        }
    }
    if (2 * c2 > n) {
        int x = c2 - n / 2;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++) {
            if (-a1[i] < -a3[i])
                v.push_back({a2[i]-a1[i],1});
            else
                v.push_back({a2[i]-a3[i],3});
        }
        sort(v.begin(), v.end());
        c2 -= x;
        for (int i = 0; i < x; i++) {
            ans = ans - v[i].first;
            if (v[i].second == 1)
                c1++;
            else
                c3++;
        }
    }
    if (2 * c3 > n) {
        int x = c3 - n / 2;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; i++) {
            if (-a1[i] < -a2[i])
                v.push_back({a3[i]-a1[i],1});
            else
                v.push_back({a3[i]-a2[i],2});
        }
        sort(v.begin(), v.end());
        c3 -= x;
        for (int i = 0; i < x; i++) {
            ans = ans - v[i].first;
            if (v[i].second == 1)
                c1++;
            else
                c2++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &test);
    for (; test--; )
        solve();
    return 0;
}
