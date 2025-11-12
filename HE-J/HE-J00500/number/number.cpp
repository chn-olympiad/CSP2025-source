#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>v;
	for (int i=0;i<s.length();++i){
		if (s[i]>='0'&&s[i]<='9')v.push_back(((int)s[i]-'0'));
	}
	sort(v.begin(),v.end(),greater<int>());
	if (v[0]==0)cout<<0;
	for (int i=0;i<v.size();++i)cout<<v[i];
	return 0;
}
