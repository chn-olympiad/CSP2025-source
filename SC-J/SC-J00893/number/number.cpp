#include<bits/stdc++.h>
using namespace std;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,t;
	cin>>s;
	for(int i=0;i<s.size();i++) if('0'<=s[i] && s[i]<='9') t+=s[i];
	sort(t.begin(),t.end(),greater<int>());
	cout<<t;
	return 0;
}