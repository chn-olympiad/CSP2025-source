#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define D(i,j,k) for(int i=j;i>=k;i--)
#define int long long
const int N = 5e5+100;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second != b.second)return a.second < b.second;
	return a.first < b.first;
}
vector<pair<int, int>>vec;
map<int, int>LST;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, f = 0, cur,lst = -1,ans=0;
	cin >> n >> k;
	LST[0] = 0;
	F(i, 1, n) {
		cin >> cur;
		f ^= cur;
		if (LST.count(k^f))
			vec.push_back({LST[k^f] + 1, i});
		LST[f] = i;
	}
	sort(vec.begin(), vec.end(), cmp);
	for (pair<int, int> x : vec) {
		if (x.first <= lst)continue;
		lst = x.second, ++ans;
	}
	cout << ans << '\n';
	return 0;
}