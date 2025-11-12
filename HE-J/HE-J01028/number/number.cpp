#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string ss="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss+=s[i];
		}
	}
	sort(ss.begin(),ss.end(),cmp);
	cout<<ss;
	return 0;
}
