#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='9'){
			cout<<9;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='8'){
			cout<<8;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='7'){
			cout<<7;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='6'){
			cout<<6;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='5'){
			cout<<5;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='4'){
			cout<<4;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='3'){
			cout<<3;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='2'){
			cout<<2;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cout<<1;
			s[i]='a';
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			cout<<0;
			s[i]='a';
		}
	}
	return 0;
}
