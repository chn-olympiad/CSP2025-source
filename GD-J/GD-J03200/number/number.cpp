#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> vec;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.length();i++)
		if('0'<=s[i] && s[i]<='9')
			vec.push_back(s[i]-'0');
	sort(vec.begin(), vec.end(), greater<>());
	for(auto i:vec) cout<<i;
	return 0;
}

