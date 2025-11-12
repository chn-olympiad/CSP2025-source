#include <bits/stdc++.h>
using namespace std;

int n, a[5005], cnt;

void dfs(int last, int x, int sum) {
	if(x-1 >= 3) {
		if(a[last]*2 < sum) {
			cnt ++;
		}
	}
	if(x==n+1) return ;
	for(int i=last+1; i<=n; i++) {
		dfs(i, x+1, sum+a[i]);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w" ,stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	dfs(0, 1, 0);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
