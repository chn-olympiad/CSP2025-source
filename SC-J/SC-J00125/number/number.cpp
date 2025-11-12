#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	vector<int> v;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	return 0;
}