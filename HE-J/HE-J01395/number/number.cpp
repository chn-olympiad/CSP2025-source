#include<bits/stdc++.h>
using namespace std;
const int M=2000000;

string s;
int num[M];
int main(){
	memset(num,-1,sizeof(num));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if (s[i]>='0' && s[i]<='9'){
			num[i]=s[i]-'0';
		}
		if (num[i]==9){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==8){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==7){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==6){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==5){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==4){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==3){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==2){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==1){
			cout<<num[i];
		}
	}
	for(int i=0;i<s.size();i++){
		if (num[i]==0){
			cout<<num[i];
		}
	}
	return 0;
}
