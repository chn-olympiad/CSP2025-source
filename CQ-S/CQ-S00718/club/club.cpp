#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long t, i, j, n, a[N][5], ans, maxsum[N], max_;
int cmp(int A, int B){
	return A > B;
}
void dfs(long long k, long long sum, long long s1, long long s2, long long s3){
	if(k > n){
		ans = max(ans, sum);
		return ; 
	}
	if(sum + maxsum[n] - maxsum[k - 1] <= ans){
		return;
	}
	if(s1 < n / 2){
		dfs(k + 1, sum + a[k][1], s1 + 1, s2, s3);
	} 
	if(s2 < n / 2){
		dfs(k + 1, sum + a[k][2], s1, s2 + 1, s3);
	}
	if(s3 < n / 2){
		dfs(k + 1, sum + a[k][3], s1, s2, s3 + 1);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		ans = 0;
		for(i = 1; i <= n; i++){
			max_ = 0;
			for(j = 1; j <= 3; j++){
				cin >> a[i][j];
				max_ = max(max_, a[i][j]);
			}
			maxsum[i] = maxsum[i - 1] + max_;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n"; 
	} 
	return 0;
}
