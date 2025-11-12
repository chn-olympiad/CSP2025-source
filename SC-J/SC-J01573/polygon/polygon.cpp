#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 50;
const int M = 998244353;
int a[N], ans;
vector<int> b(N);
int n;
void dfs(int pos, int cnt, int mx, int sum){
	if(cnt >= 3 && sum > mx * 2){
		ans++;
	}
	if(cnt > n) return;
	for(int i = pos; i <= n; i++){
		if(b[i] == 0){
			b[i] = 1;
			dfs(i, cnt+1, max(mx, a[i]), sum+a[i]);
			b[i] = 0;
		}
		
	}
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int maxx = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if(maxx == 1){
		int sum = 0;
		for(int i = 3; i <= n; i++){
			int s = 1;
			for(int j = n; j >= n - i + 1; j--){
				s *= i;
			}
			for(int j = 1; j <= i; i++){
				s /= i;
			}
			sum += s;
			sum %= M;
		}
		cout << sum;
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}