#include <bits/stdc++.h>
using namespace std;
	string s;
	char a[100003];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0'){
			a[c] = s[i];
			c++;
			
		}
	}
	for(int i=0;i<c;i++){
		if(a[i] == '9'){
			cout<<'9';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '8'){
			cout<<'8';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '7'){
			cout<<'7';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '6'){
			cout<<'6';
		}
	} for(int i=0;i<c;i++){
		if(a[i] == '5'){
			cout<<'5';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '4'){
			cout<<'4';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '3'){
			cout<<'3';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '2'){
			cout<<'2';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '1'){
			cout<<'1';
		}
	} 
	for(int i=0;i<c;i++){
		if(a[i] == '0'){
			cout<<'0';
		}
	} 
	
	return 0;
} 
