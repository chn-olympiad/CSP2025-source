#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> res; 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i] >= '0' && s[i] <= '9') res.push_back(s[i]);
	}
	sort(res.begin(),res.end());
	for(int i=res.size()-1;i>=0;i--) cout << res[i];
	return 0;
}
