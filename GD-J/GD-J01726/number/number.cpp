#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	bool h0=false;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'&&!h0){cout<<0;return 0;}
		if(s[i]<='9')cout<<s[i],h0=true;
	}
	return 0;
}
