#include<bits/stdc++.h>
using namespace std;

int n, a[30], ans;
bool b[30];

void dfs(int x) {
    if(x == n) {
        int sum = 0, m = 0;
        for(int i = 1; i <= n; i++) {
            if(b[i] == true) {
                sum += a[i];
                m = max(m, a[i]);
            }
        }
        if(sum > m * 2) {
            ans++;
        }
        b[x] = false;
        return ;
    }
    b[x + 1] = true;
    dfs(x + 1);
    b[x + 1] = false;
    dfs(x + 1);
    return ;
 }

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if(n < 3) {
        printf("0");
        return 0;
    }
    dfs(0);
    printf("%d", ans);
}
