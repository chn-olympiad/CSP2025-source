#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int n;
int a[N][3];
int f[N];
vector<int>vec[3];
inline bool cmp(int i, int j) { return f[i] < f[j]; }
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1;i <= n;++i)
            for (int j = 0;j < 3;++j) scanf("%d", &a[i][j]);
        for (int i = 0;i < 3;++i) vec[i].clear();
        LL ans = 0;
        for (int i = 1;i <= n;++i)
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) vec[0].push_back(i), ans += a[i][0], f[i] = max(a[i][1] - a[i][0], a[i][2] - a[i][0]);
            else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) vec[1].push_back(i), ans += a[i][1], f[i] = max(a[i][0] - a[i][1], a[i][2] - a[i][1]);
            else vec[2].push_back(i), ans += a[i][2], f[i] = max(a[i][0] - a[i][2], a[i][1] - a[i][2]);
        for (int i = 0;i < 3;++i)
            if (vec[i].size() > n >> 1) {
                sort(vec[i].begin(), vec[i].end(), cmp);
                for (int j = vec[i].size() - 1;j >= (n >> 1);--j) ans += f[vec[i][j]];
            }
        printf("%lld\n", ans);
    }
    return 0;
}