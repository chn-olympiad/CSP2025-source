#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> v;
	for (int i=0; i<s.size(); i++)
		if (isdigit(s[i]))
			v.push_back(s[i]-'0');
	sort(v.begin(), v.end());
	for (int i=v.size()-1; i>=0; i--)
		printf("%lld", v[i]);
	return 0;
}