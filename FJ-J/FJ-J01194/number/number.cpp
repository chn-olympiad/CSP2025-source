#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >> s;
	for (int i = 0;i < s.size();i++) mp[s[i]]++;
	string ans;for (int i = '9';i >= '0';i--) for (int j = 1;j <= mp[i];j++) ans += i;
	while(ans.size() > 1 && ans[0] == '0') ans.erase(0,1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
