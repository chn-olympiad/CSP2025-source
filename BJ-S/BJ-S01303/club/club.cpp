#include <bits/stdc++.h>
using namespace std;

int n, c[100010], ans;

struct node {
    int g1, g2, g3;
} a[100010];

bool cmp1(node x, node y) {
    return x.g1 > y.g1;
}

bool cmp2(node x, node y) {
    return x.g2 > y.g2
}

bool cmp3(node x, node y) {
    return x.g3 > y.g3;
}

void dfs(int x) {
    if (x > 3) {
        int sum = 0;
        for (int i = 1; i <= 3; i++) {
            sum += c[i];
        }
        if (sum != n) return;
        else {
            sum = 0;
            for (int i = 1; i <= 3; i++) {
                if (i == 1) sort(a + 1, a + n + 1, cmp1);
                if (i == 2) sort(a + 1, a + n + 1, cmp2);
                if (i == 3) sort(a + 1, a + n + 1, cmp3);
                for (int j = 1; j <= c[i]; j++) {
                    if (i == 1) sum += a[j].g1;
                    if (i == 2) sum += a[j].g2;
                    if (i == 3) sum += a[j].g3;
                }
            }
            ans = max(ans, sum);
        }
        return;
    }
    for (int i = 1; i <= n / 2; i++) {
        c[x] = i;
        dfs(x + 1);
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].g1 >> a[i].g2 >> a[i].g3;
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}
