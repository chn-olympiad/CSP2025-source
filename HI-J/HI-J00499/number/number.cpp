#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number3.in","r",stdin);
	freopen("number3.out","w",stdout);
	char s[1000000],j[1000000];
	cin>>s;
	for(int i=1;;i++){
		if(s[i]='1') j[i]='1';
		else if(s[i]='2') j[i+1]='2';
		else if(s[i]='3') j[i+2]='3';
		else if(s[i]='4') j[i+3]='4';
		else if(s[i]='5') j[i+4]='5';
		else if(s[i]='6') j[i+5]='6';
		else if(s[i]='7') j[i+6]='7';
		else if(s[i]='8') j[i+7]='8';
		else if(s[i]='9') j[i+8]='9';
		else if(s[i]='0') j[i+9]='0';
		break;
		sort(j+i,j+i+1);
	}
	for(int i=1;;i++){
		cout<<j[i];
		break;
	}
	return 0;
} 
