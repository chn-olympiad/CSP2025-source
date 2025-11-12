#include<bits/stdc++.h>

using namespace std;

int n;
int a[5010];
int ans;
const int P = 998244353;
int c[5010];

inline void dfs(int i, int cnt, int na, int mx){
    if(i == n + 1){
        if((na > mx * 2) && (cnt >= 3)) {
            ans++, ans %= P;
        }
        return;
    }
    c[i] = 1;
    dfs(i + 1, cnt + 1, na + a[i], max(mx, a[i]));
    c[i] = 0;
    dfs(i + 1, cnt, na, mx);
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    dfs(1, 0, 0, 0);

    printf("%d", ans);
    return 0;
}
