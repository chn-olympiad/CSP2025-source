#include<bits/stdc++.h>
using namespace std;
long long ans = 0;
bool u = true;
long long a[100010];
bool vis[100010];
long long n;
const long long mod = 998244353;
void dfs(int step, long long maxx, long long sum){
    if(sum > maxx * 2){
        ans = (ans + 1) % mod;
    }
    if(step == n + 1){
        return;
    }
    for(int i = step; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = true;
        dfs(i + 1, max(maxx, a[i]), sum + a[i]);
		vis[i] = false;
    }
}
int main(){
	freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != 1) u = false;
    }
    if(u){
        cout << n * (n - 1) * (n - 2) / 6;
    }else{
        dfs(1, 0LL, 0LL);
        cout << ans;
    }
    return 0;
}
