#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	if(v[v.size()-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}
/*
AK CSP-J
AK CSP-S
AK NOIP
AK 省选
AK NOI
AK IOI
*/