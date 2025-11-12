#include<bits/stdc++.h>
using namespace std;
int n, l[5005], f, s[5005], tot, a[5005];
long long ans;
void dfs(int x, int k, int t){
    if (k > 3){
        if (s[k-1] * 2 < t){
            ans ++;
            ans %= 998244353;
        }
        if (k > n) return ;
    }
    for (int i = x + 1; i <= n; i ++){
        s[k] = l[i];
        dfs(i, k + 1, t + l[i]);
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &l[i]);
        a[i] += a[i-1] + l[i];
        tot += l[i];
        if (l[i] == 1) f ++;
    }
    sort(l + 1, l + 1 + n);
    if (n == 3){
        int m = 1;
        if (tot > l[n]) printf("%d", m);
        else printf("%d", m - 1);
        return 0;
    }
    dfs(0, 1, 0);
    cout << ans;

    return 0;
}
