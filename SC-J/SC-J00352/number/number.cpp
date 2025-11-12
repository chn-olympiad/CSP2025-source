#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define D(i,j,k) for(int i=j;i>=k;i--)
#define int long long
const int N = 2e5+100;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int>vec;
	F(i, 0, s.size() - 1)
	if (s[i] <= '9' && s[i] >= '0')
		vec.push_back(s[i] - '0');

	sort(vec.begin(), vec.end(), greater<int>());
	F(i, 0, vec.size() - 1)cout << vec[i];
	cout << '\n';

	return 0;
}