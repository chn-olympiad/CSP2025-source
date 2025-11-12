#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
int n, m, k;
long long a[N], b[N], c[N], ans;
int s1, s2, s3, s4, s5;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		ans += c[i];
	}
	for(int i = 1; i <= k; i++) {
		cin >> s1 >> s2 >> s3 >> s4 >> s5;
	}
	cout << ans;
	return 0;
}
