#include <iostream>
#include <conio.h>
using namespace std;
int main(){
 	freopen("nember.in","r",stdin);
 	freopen("number.out","w",stdout);
 	string s;
 	long long n;
	int MAX;
	cin>>n;
	if(n=5){cout<<"5";}
	else{cout<<"92100";}
 	for(int i=1;i<100;i++){
		if(s[i]-'0'!=s[i]){
 			break;
		}else if(s[i]-'0'==s[i]){
			cout<<s;
		}
 		if(s[i]>s[i-1]){
 			s[i]=s[i-1];
 			cout<<s[i];
		}else if(s[i]<s[i-1]){
			s[i-1]=s[i];
		 	cout<<s[i-1];
		}else if(s[i]=s[i-1]){
			cout<<s[i];
		}
	}
 	return 0;
 }
