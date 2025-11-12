#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void io(string name=""){
	if(name.size()){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
string s;
vector<int> ans;
signed main(){
	io("number");
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;++i)
		if(isdigit(s[i]))
			ans.push_back(s[i]-48);
	sort(ans.begin(), ans.end(), greater<int>());
	for(auto x:ans)
		cout<<x;
	return 0;
}
