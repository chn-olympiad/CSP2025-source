#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 500005
#define MAXM 100005
#define pii pair<int, int>

int n, k;
map<int, int> mp;
int a[MAXN];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	int sum = 0, last = 0;
	mp[sum] = 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum ^= a[i];
		int goal = sum ^ k;
		if (mp[goal] > last) {
			++ans;
			last = i;
		}
		mp[sum] = i + 1;
	}
	cout << ans << endl;
	return 0;
}