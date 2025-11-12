#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long a[5001];
bool vis[5001];
long long n, maxx = 0, cnt = 0, ans = 0;
long long cala(int x, int y){
    long long k = 1;
    for (long long i = 0; i < y; i++)
        k = (k * (x - i)) % mod;
    for (long long i = y; i >= 2; i--)
        k /= i;
    return k;
}
void dfs(long long p){
    if (p > n){
        long long dcnt = 0, dmax = 0, flag = 0;
        for (long long i = 1; i <= n; i++){
            if (vis[i]){
                dcnt += a[i];
                dmax = max(dmax, a[i]);
                flag++;
            }
        }
        if (flag < 3)
            return ;
        if (dcnt > dmax * 2)
            ans++;
        return ;
    }
    for (long long i = 0; i <= 1; i++){
        vis[p] = i;
        dfs(p + 1);
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    if (maxx == 1) {
        for (long long i = 3; i <= n; i++) {
            cnt = (cnt + cala(n, i)) % mod;
        }
        cout << cnt;
        return 0;
    } else {
        dfs(1);
        cout << ans;
        return 0;
    }
    cout << "CSP You Have no Egg!!!!!!";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
