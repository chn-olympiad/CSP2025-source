#include<bits/stdc++.h>
using namespace std;
vector<char>num;
bool cmp(char x,char y){
	return(x>y);
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(s[i]);
		}
	}
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<num.size();i++){
		cout<<num[i];
	}
	return 0;
}
