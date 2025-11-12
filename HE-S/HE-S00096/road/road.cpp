#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, ans = 0, w, v, l;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		cin >> w >> v >> l;
		ans += l;
	}
	cout << ans;
	
	return 0;
}
