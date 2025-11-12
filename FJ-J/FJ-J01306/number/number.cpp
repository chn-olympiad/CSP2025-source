#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> p;

void solve(){
	cin >> s;
	for(int i = 0; i < s.size(); ++i)
		if('0' <= s[i] && s[i] <= '9')
			p.push_back(s[i] - '0');
	sort(p.begin(), p.end(), greater<>());
	for(auto k : p) printf("%d", k);
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	solve();
	return 0;
} 
