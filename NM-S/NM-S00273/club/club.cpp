#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, ans;
int pre[N];
int a[3][N];

void dfs(int n1, int n2, int n3, int id, int num) {
    if (id == n + 1) {
        ans = max(ans, num);
        return ;
    }
    if (num + pre[n] - pre[id - 1] <= ans)
        return ;
    int tn = n / 2;
    if (n1 < tn)
        dfs(n1 + 1, n2, n3, id + 1, num + a[0][id]);
    if (n2 < tn)
        dfs(n1, n2 + 1, n3, id + 1, num + a[1][id]);
    if (n3 < tn)
        dfs(n1, n2, n3 + 1, id + 1, num + a[2][id]);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[0][i], &a[1][i], &a[2][i]);
            pre[i] = pre[i - 1] + max(a[0][i], max(a[1][i], a[2][i]));
        }
        ans = 0;
        dfs(0, 0, 0, 1, 0);
        printf("%d\n", ans);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
