#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	string s;
	cin>>s;
	string ans="";
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')ans.push_back(s[i]);
	}
	sort(ans.begin(),ans.end(),greater<char>());
	len=ans.size();
	int i;
	for(i=0;i<len;i++){
		if(ans[i]!='0')break;
	}
	if(i==len)cout<<0;
	else cout<<ans.substr(i);
	return 0;
}
