#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5e3 + 10, INF = 9e18, mod = 998244353;
int n, cnt, a[N];
void dfs(int dep, int sum, int maxx){
    if(dep == n){
        if(sum > maxx * 2) cnt++;
        return;
    }
    dfs(dep + 1, sum, maxx);
    dfs(dep + 1, sum + a[dep + 1], max(maxx, a[dep + 1]));
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if(n == 3){
        int a, b, c;
        cin >> a >> b >> c;
        if(max({a, b, c}) * 2 < a + b + c) cout << 1;
        else cout << 0;
    }
    else{
        int maxn(0);
        rep(i, n) cin >> a[i], maxn = max(maxn, a[i]);
        if(maxn == 1){
            int sum(0);
            for(int i = 3; i <= n; i++){
                int tmp(1);
                for(int j = n; j >= n - i + 1; j--){
                    tmp *= j;
                    tmp %= mod;

                }
                rep(j, i){
                    tmp /= j;
                }
                sum += tmp;
                sum %= mod;
            }
            cout << sum;
        }
        else{
            dfs(0, 0, 0);
            cout << cnt;
        }

    }
    return 0;
}
