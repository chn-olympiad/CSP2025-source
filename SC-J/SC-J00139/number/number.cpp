#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int> r;
	for(int i=0;i<s.length();++i){
		if(s[i]-'0'<=9){
			r.push_back(s[i]-'0');
		}
	}
	sort(r.begin(),r.end(),greater<int>());
	if(r[0]==0){
		cout<<'0';
		return 0;
	}
	for(int j=0;j<r.size();++j){
		cout<<r[j];
	}
	return 0;
}