#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	vector<ll>ans;
	for(int i=1; i<=n; ++i){
		if('0' <= s[i] && s[i] <= '9'){
			ans.push_back(s[i] - '0');
		}
	}
	sort(ans.begin(), ans.end(), greater<int>());
	for(auto v : ans){
		cout << v;
	}
	return 0;
}