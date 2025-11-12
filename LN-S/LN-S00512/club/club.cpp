#include<bits/stdc++.h>
using namespace std;

int t, ans, cnt[4];
int arr[4][100010], g[4];

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        memset(g, 0, sizeof(g));
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        for (int i = 1; i <= n; i++) {
            int a, b, c, ma = 0, maa = 0;
            scanf("%d%d%d", &a, &b, &c);
            ma = max(max(a, b), c);
            if (ma == a)
                maa = max(b, c), g[1]++, arr[1][++cnt[1]] = ma - maa;
            else if (ma == b)
                maa = max(a, c), g[2]++, arr[2][++cnt[2]] = ma - maa;
            else
                maa = max(a, b), g[3]++, arr[3][++cnt[3]] = ma - maa;
            ans += ma;
        }
        for (int i = 1; i <= 3; i++)
            sort(arr[i] + 1, arr[i] + 1 + cnt[i]);
        if (g[1] > n / 2) {
            for (int i = 1; i <= g[1] - n / 2; i++)
                ans -= arr[1][i];
        } else if (g[2] > n / 2){
            for (int i = 1; i <= g[2] - n / 2; i++)
                ans -= arr[2][i];
        } else {
            for (int i = 1; i <= g[3] - n / 2; i++)
                ans -= arr[3][i];
        }
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
