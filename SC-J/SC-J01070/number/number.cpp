#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void solve(){
	string s;
	cin >> s;
	vector<int> ans;
	for(int i = 0; i < s.size(); i ++ ) {
		if(s[i] >= '0' && s[i] <='9') ans.push_back(s[i] - '0');
	}
	sort(ans.begin(), ans.end(),[](int a, int b){
		return a > b;
	});
	for(auto c : ans) cout << c;
	
	
}
signed main() {
	
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t= 1;
	while(t--) solve();
	
	
	return 0;
}