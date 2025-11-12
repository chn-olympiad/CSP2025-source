#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0;i < n;i ++) {
		cin >> a[i];
	}
	int ans = 0; 
	for (int i = 3;i < n;i ++) {
		for (int k = i;k <= n;k ++) {
			ans ++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
