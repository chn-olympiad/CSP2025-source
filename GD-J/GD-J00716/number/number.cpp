#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	vector<int> num;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num.push_back(int(s[i]-'0'));
		}
	}
	sort(num.begin(),num.end());
	for(int i=num.size()-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
