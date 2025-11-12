#include<bits/stdc++.h>
using namespace std;
const int M =  998244353;
int n, a[5010];
bool v[5010];
int ans = 0;
int dfs(int b, int s) {
	if(s > 2 * a[b - 1]) {
		ans = (ans + 1) % M;
	}
	for(int i = b; i <= n; i++) {
		if(v[i] == 0) {
			v[i] = 1;
			dfs(i + 1, s + a[i]);
			v[i] = 0;
		}
	}
	return ans % M;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << dfs(1, 0);
	return 0;
}