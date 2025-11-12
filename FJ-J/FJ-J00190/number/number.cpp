#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string str;
	vector<int>num;
	cin>>str;
	for(unsigned long long i=0;i<str.size();i++){
		if('0'<=str[i]&&str[i]<='9'){
			num.push_back(str[i]-'0');
		}
	}
	sort(num.begin(),num.end(),greater<int>());
	for(unsigned long long i=0;i<num.size();i++){
		cout<<num[i];
	}
	return 0;
} 
