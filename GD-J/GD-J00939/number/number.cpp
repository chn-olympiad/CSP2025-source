#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

vector<int> st;

int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	rep(i, 1, n)
		if(s[i] >= '0' && s[i] <= '9')
			st.emplace_back(s[i] - '0');
	sort(st.begin(), st.end(), greater<int>());
	for(auto v : st) cout << v;
	cout << endl;
	return 0;
}
