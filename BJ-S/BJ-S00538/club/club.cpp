#include <bits/stdc++.h>
using namespace std;
int T;
int n, a[100005][5], N;
long long ans = 0;
int f[35][5][35][35][35];
void dfs(int step, int a1, int b1, int c1, long long num) {
    if(step == n + 1) {
        ans = max(ans, num);
        return ;
    }
    if(a1 < N) {
        dfs(step + 1, a1 + 1, b1, c1, num + a[step][1]);
    }
    if(b1 < N) {
        dfs(step + 1, a1, b1 + 1, c1, num + a[step][2]);
    }
    if(c1 < N) {
        dfs(step + 1, a1, b1, c1 + 1, num + a[step][3]);
    }
}
int main() {
    cin >> T;
    while(T--) {
        bool A=1, B=1;
        cin >> n;
        N = n/2;
        for(int i = 1;i <= n;i++) {
            scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
            if(a[i][3] != 0)
                B=0;
            if(a[i][3] != 0 || a[i][2] != 0)
                A=0;
        }
        if(n <= 10) {
            ans = 0;
            dfs(1, 0, 0, 0, 0);
            cout << ans << endl;
        }
        else if(A) {
            int ans[100005];
            for(int i = 1;i <= n;i++){
                ans[i] = a[i][1];
            }
            sort(ans + 1, ans + n + 1);
            long long sum = 0;
            for(int i = n;i >= N+1;i--){
                sum += ans[i];
            }
            cout << sum << endl;
        }
        else {
            memset(f, 0, sizeof(f));
            int dp = 0;
            for(int i = 1;i <= n;i++){
                for(int u = 0;u <= N;u++){
                    for(int v = 0;v <= N;v++){
                            int w = i - u - v;
                            if(u+v+w != i || w<0)
                                continue;
                            if(u>0)
                                for(int j = 1;j <= 3;j++)
                                    f[i][1][u][v][w] = max(f[i][1][u][v][w], f[i-1][j][u-1][v][w] + a[i][1]);
                            if(v>0)
                                for(int j = 1;j <= 3;j++)
                                    f[i][2][u][v][w] = max(f[i][2][u][v][w], f[i-1][j][u][v-1][w] + a[i][2]);
                            if(w>0)
                                for(int j = 1;j <= 3;j++)
                                    f[i][3][u][v][w] = max(f[i][3][u][v][w], f[i-1][j][u][v][w-1] + a[i][3]);
                            dp = max(max(dp, f[i][1][u][v][w]), max(f[i][2][u][v][w], f[i][3][u][v][w]));


                    }
                }
            }
            cout << dp << endl;
        }
    }
    return 0;
}