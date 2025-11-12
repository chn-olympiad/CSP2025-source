#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n, k, a[N], dp[N];
map<pair<int, int>, int> mp;
vector<pair<int, int> > vt;
int main() {
	freopen("xor.in", "r" , stdin);
	freopen("xor.out", "w" , stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= n; j ++) {
			if (i == j)
				mp[{i, j}] = a[j];
			else
				mp[{i, j}] = mp[{i, j - 1}] ^ a[j];
			if (mp[{i, j}] == k)
				vt.push_back({i, j});
//				cout << i << ' ' << j << endl;
		}
	}
	int len = vt.size();
	for (int i = 0; i < len; i ++) {
		for (int j = n; j >= vt[i].second; j --)
			dp[j] = max(dp[j], dp[vt[i].first - 1] + 1);
	}
	cout << dp[n];
	return 0;
}

