#include <bits/stdc++.h>
#define frein(x) freopen(x, "r", stdin);
#define freot(x) freopen(x, "w", stdout);
using namespace std;
using ll = long long;

const int N = 5e5 + 5;
int n, k;
int a[N], pre[N], opt;
unordered_map<int, queue<int> > mp;
int ans = 0;

int main() {
	frein("xor.in");
	freot("xor.out");
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin >> n >> k;
	
	mp[0].emplace(0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
		int t = pre[i] ^ k;
		if (!mp[t].empty()) {
			bool f = 1;
			while (!mp[t].empty()) {
				int tf = mp[t].front();
				if (f && opt <= tf) {
					++ans;
					f = 0;
					//cerr << mp[t].front() << ' ' << i << "\n\n";
					opt = i;
				}
				if (tf < i) {
					mp[t].pop();
				}
			}
		}
		mp[pre[i]].emplace(i);
	}
	cout << ans;
	return 0;
}
