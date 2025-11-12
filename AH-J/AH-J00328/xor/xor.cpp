#include<bits/stdc++.h>
using namespace std;
long long a[1010];
bool vis[1010] = {false};
struct node{
	long long s, l, r;
}f[500510];
long long iii, n, k, m = 1, ans, maxn = LLONG_MIN;
bool solve(long long l, long long r){
	for(int i = l; i <= r; i++) {
		if(vis[i] == true) return false;
	}
	return true;
}
void viss(long long l, long long r){
	for(int i = l; i <= r; i++) vis[i] = true;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			f[m].s = a[l], f[m].l = l, f[m].r = r;
			for(int i = l + 1; i <= r; i++){
				f[m].s ^= a[i];
			}
			if(f[m].s == k) iii++;
			m++;
		}
	}
	for(int i = 1; i <= iii; i++){
		memset(vis, false, sizeof vis);
		ans = 0;
		for(int i = 1; i < m; i++){
			if(f[i].s == k && solve(f[i].l, f[i].r) == true){
				ans++;
				viss(f[i].l, f[i].r);
			}
		}
		for(int i = 1; i < m; i++){
			if(f[i].s == k){
				f[i].s = LLONG_MIN;
				break;
			}
		}
		maxn = max(maxn, ans);
	}
	cout << maxn;
	return 0;
}
