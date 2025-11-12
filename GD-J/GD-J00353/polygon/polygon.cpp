#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int n, a[N], ans=0;

void dfs(int idx, int sum, int max_){
	if(idx>n){
		if(sum>max_*2) ans++;
		return;
	}
	dfs(idx+1, sum+a[idx], max(max_, a[idx]));
	dfs(idx+1, sum, max_);
	return;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
