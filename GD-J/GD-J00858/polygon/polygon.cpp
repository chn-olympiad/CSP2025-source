#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n, a[110], cnt;
void dfs(int step, int maxn, int sum){
	if (step > n){
		if (sum > 2*maxn) cnt++;
		return;
	}
	dfs(step+1, maxn, sum);
	dfs(step+1, max(a[step], maxn), sum+a[step]);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
		
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 0, 0);
	cout << cnt << endl;
	return 0;
}
