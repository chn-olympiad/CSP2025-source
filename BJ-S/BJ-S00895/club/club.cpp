#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y;
} p[100005];

int T, n, a[100005], b[100005], c[100005], dp[205][205][205], ans;
bool spA, spB;
priority_queue<pair<int, int>> qA, qB, qC;

bool cmpa(const node &a, const node &b){
    if (a.x > b.x) return a.x > b.x;
    return a.y < b.y;
}

bool cmpb(const node &a, const node &b){
    if (a.y > b.y) return a.y > b.y;
    return a.x < b.x;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n); spA = spB = true; ans = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            if (b[i] != 0) spA = false;
            if (c[i] != 0) spB = spA = false;
        }
        int limit = n / 2;
        if (n <= 200){
            memset(dp, 0, sizeof dp);
            for (int i = 0; i <= limit; i++){
                for (int j = 0; j <= limit; j++){
                    for (int k = 0; k <= limit; k++){
                        int now = i + j + k + 1;
                        if (now == n + 1) ans = max(ans, dp[i][j][k]);
                        if (i < limit) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + a[now]);
                        if (j < limit) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k] + b[now]);
                        if (k < limit) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k] + c[now]);
                    }
                }
            }
            printf("%d\n", ans);
            continue;
        }
        if (spA){
            sort(a+1, a+n+1);
            for (int i = n; i > n / 2; i--){
                ans += a[i];
            }
            printf("%d\n", ans);
            continue;
        }
        if (spB){
            for (int i = 1; i <= n; i++){
                p[i] = {a[i], b[i]};
            }
            sort(p+1, p+n+1, cmpa);
            int res1 = 0;
            for (int i = 1; i <= n; i++){
                if (i <= n / 2) ans += p[i].x;
                else ans += p[i].y;
            }
            sort(p+1, p+n+1, cmpb);
            int res2 = 0;
            for (int i = 1; i <= n; i++){
                if (i <= n / 2) ans += p[i].y;
                else ans += p[i].x;
            }
            printf("%d\n", max(res1, res2));
            continue;
        }
        for (int i = 1; i <= n; i++){
            if (a[i] >= b[i] && a[i] >= c[i]) qA.push({b[i] - a[i], i}), ans += a[i];
            else if (b[i] >= a[i] && b[i] >= c[i]) qB.push({c[i] - b[i], i}), ans += b[i];
            else qC.push({a[i] - c[i], i}), ans += c[i];
        }
        while (qA.size() > limit || qB.size() > limit || qC.size() > limit){
            while (qA.size() > limit || qA.top().first > 0){
                int x = qA.top().second; qA.pop();
                qB.push({c[x] - b[x], x}); ans += b[x] - a[x];
            }
            while (qB.size() > limit || qB.top().first > 0){
                int x = qB.top().second; qB.pop();
                qC.push({a[x] - c[x], x}); ans += c[x] - b[x];
            }
            while (qC.size() > limit || qC.top().first > 0){
                int x = qC.top().second; qC.pop();
                qA.push({b[x] - a[x], x}); ans += a[x] - c[x];
            }
        }
        printf("%d\n", ans);
        while (qA.size()) qA.pop();
        while (qB.size()) qB.pop();
        while (qC.size()) qC.pop();
    }
    return 0;
}