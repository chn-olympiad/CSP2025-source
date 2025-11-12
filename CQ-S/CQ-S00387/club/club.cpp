#include <bits/stdc++.h>
using namespace std;

int T, n, t, a[100001][3];

int calc(int x) {
    int ans = 0;
    for (int i = 0; i < 3; i++)
        if (i != t)
            ans = max(ans, a[x][i]);
    return ans;
}

bool cmp(int x, int y) {
    return a[x][t] - calc(x) < a[y][t] - calc(y);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> v[3];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int t = 0;
            for (int j = 0; j < 3; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] > a[i][t])
                    t = j;
            }
            v[t].push_back(i);
            ans += a[i][t];
        }
        for (t = 0; t < 3; t++) {
            if (v[t].size() > n / 2) {
                sort(v[t].begin(), v[t].end(), cmp);
                for (int i = 0; i < v[t].size() - n / 2; i++)
                    ans -= a[v[t][i]][t] - calc(v[t][i]);
            }
        }
        printf("%d\n", ans);
    }
}