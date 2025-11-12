#include<bits/stdc++.h>
using namespace std;
long long a[5010], b[5010];
bool vis[5010];
long long n, ans = 0;
bool sss(long long a[], long long nn){
	long long sum = 0, maxn = LLONG_MIN;
	for(int i = 1; i <= nn; i++) sum += a[i], maxn = max(maxn, a[i]);
	if(sum > 2 * maxn) return true;
	return false;
}
void dfs(long long b[], long long step, long long cnt){
	if(step > cnt){
		if(sss(b, cnt) == true) ans++;
		return ;
	}
	for(int i = step; i <= n; i++){
		if(vis[i] == false){
			b[i] = a[i];
			vis[i] = true;
			dfs(b, step + 1, cnt);
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n < 3){
		cout << 0;
		return 0;
	}
	else if(n == 3){
		if(sss(a, n)){
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	else{
		for(int i = 3; i <= n; i++){
			memset(vis, false, sizeof vis);
			dfs(b, 1, i);
		}
		cout << ans;
	}
	return 0;
}
