#include<bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==9){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==8){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==7){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==6){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==5){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==4){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==3){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==2){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==1){
			cout<<s[j];		
		}
	}
	for(int j=0;j<s.size();j++){
		if(s[j]-'0'<10&&s[j]-'0'==0){
			cout<<s[j];		
		}
	}
	return 0;
} 
