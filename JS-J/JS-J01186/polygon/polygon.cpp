#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5007;
constexpr int mod = 998244353;
int n, res, a[N];
bool vis[N];
void dfs(int cur, int maxn, int sum, int cnt){
    if(cnt >= 3 && sum > maxn * 2){
        cout << sum << " " << maxn << '\n';
        res++;
        res %= mod;
        return ;
    }
    for(int i = cur + 1; i <= n; i++){
        if(!vis[i]){
            maxn = max(maxn, a[i]);
            sum += a[i];
            vis[i] = true;
            cnt++;
            dfs(i, maxn, sum, cnt);
            sum -= a[i];
            maxn = 0;
            cnt--;
            vis[i] = false;
        }
    }
}
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if(n < 3){
        cout << 0 << '\n';
        return 0;
    }
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n - 2; i++) dfs(i, i, i, 1);
    res %= mod;
    cout << res << '\n';
    return 0;
}
