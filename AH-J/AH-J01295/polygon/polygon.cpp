#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5, M = 1e7 + 5;
const long long mod = 998244353;
int n, a[N], max_a = 0, W = 0;
long long ans = 0, cum[N];
void dfs(int id, int sum, int maxn){
    if(id == n + 1){
        if(sum > 2 * maxn){
            ans = (ans + 1) % mod;
        }
        return;
    }
    dfs(id + 1, sum, maxn);
    dfs(id + 1, sum + a[id], max(maxn, a[id]));
}
long long f[M];
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        max_a = max(max_a, a[i]);
        W = W + a[i];
    }
    if(n <= 20){
        dfs(1, 0, 0);
    }else{
        sort(a + 1, a + n + 1);
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = W; j >= a[i]; j--){
                f[j] = (f[j] + f[j - a[i]]) % mod;
            }
            if(i >= 3){
                for(int j = W; j > a[i] * 2; j--){
                    ans = (ans + f[j]) % mod;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
