#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a10=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') a1++;
		if(s[i]=='1') a2++;
		if(s[i]=='2') a3++;
		if(s[i]=='3') a4++;
		if(s[i]=='4') a5++;
		if(s[i]=='5') a6++;
		if(s[i]=='6') a7++;
		if(s[i]=='7') a8++;
		if(s[i]=='8') a9++;
		if(s[i]=='9') a10++;
	}
	if(a10>0){
		for(int i=1;i<=a10;i++) cout<<9;
	}
	if(a9>0){
		for(int i=1;i<=a9;i++) cout<<8;
	}
	if(a8>0){
		for(int i=1;i<=a8;i++) cout<<7;
	}
	if(a7>0){
		for(int i=1;i<=a7;i++) cout<<6;
	}
	if(a6>0){
		for(int i=1;i<=a6;i++) cout<<5;
	}
	if(a5>0){
		for(int i=1;i<=a5;i++) cout<<4;
	}
	if(a4>0){
		for(int i=1;i<=a4;i++) cout<<3;
	}
	if(a3>0){
		for(int i=1;i<=a3;i++) cout<<2;
	}
	if(a2>0){
		for(int i=1;i<=a2;i++) cout<<1;
	}
	if(a1>0){
		for(int i=1;i<=a1;i++) cout<<0;
	}
	return 0;
} 
