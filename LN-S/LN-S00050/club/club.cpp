#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N], b[N], c[N];
void init(){
    n = 0;
    memset(a, 0, sizeof a);
    return;
}
bool cmp(int a, int b){
    return a > b;
}
int dfs(int x, int sum, int cnt1, int cnt2, int cnt3){
    if(x == n + 1){
        return sum;
    }
    int mx = -1;
    if(cnt1 + 1 <= n / 2)
        mx = max(dfs(x + 1, sum + a[x], cnt1 + 1, cnt2, cnt3), mx);
    if(cnt2 + 1 <= n / 2)
        mx = max(dfs(x + 1, sum + b[x], cnt1, cnt2 + 1, cnt3), mx);
    if(cnt3 + 1 <= n / 2)
        mx = max(dfs(x + 1, sum + c[x], cnt1, cnt2, cnt3 + 1), mx);
    return mx;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        init();
        bool f1 = true, f2 = true;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            f1 &= (b[i] == 0 && c[i] == 0);
            f2 &= (c[i] == 0);
        }
        if(f1){
            sort(a + 1, a + 1 + n, cmp);
            int sum = 0;
            for(int i = 1; i <= n / 2; i++)
                sum += a[i];
            printf("%d\n", sum);
            continue;
        }else if(f2){
            printf("%d\n", dfs(1, 0, 0, 0, n));
            continue;
        }
        printf("%d\n", dfs(1, 0, 0, 0, 0));
    }
    return 0;
}
