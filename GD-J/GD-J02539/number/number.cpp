#include <bits/stdc++.h>
using namespace std;
string s;
map<int,string> mp;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9') mp[s[i]-'0']+=s[i];
	}
	for(int i = 9;i >= 0;i--){
		cout << mp[i];
	}
	return 0;
}
