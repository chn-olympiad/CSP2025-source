#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n;
int a[5005];
int mx = -1;
long long ans = 0;
bool tp1 = 1;
vector<int> vis;
void dfs(int x, int cnt, int k, long long sum, int mx){
	if(n-x+1 < k-cnt) return;
	if(cnt == k){
		if(sum > mx*2) ans++;
		ans %= N;
		return;
	}
	vis.push_back(a[x]);
	dfs(x+1, cnt+1, k, sum+a[x], max(mx,a[x]));
	vis.pop_back();
	dfs(x+1, cnt, k, sum, mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		mx = max(mx, a[i]);
		if(a[i] != 1) tp1 = 0;
	}
	if(n == 3){
		if(a[1]+a[2]+a[3] > 2*mx) cout << 1;
		else cout << 0;
		return 0;
	}
	if(tp1){
		cout << n-2;
		return 0;
	}
	for(int i = 3; i <= n; ++i){
		vis.clear();
		dfs(1,0,i,0,-1);
	}
	cout << ans % N;
	return 0;
}
