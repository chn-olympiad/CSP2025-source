#include <bits/stdc++.h>
using namespace std;
string s;
string y[10];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int si=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='0'){
			y[0]+='0';
		}
		if(s[i]=='1'){
			y[1]+='1';
		}
		if(s[i]=='2'){
			y[2]+='2';
		}
		if(s[i]=='3'){
			y[3]+='3';
		}
		if(s[i]=='4'){
			y[4]+='4';
		}
		if(s[i]=='5'){
			y[5]+='5';
		}
		if(s[i]=='6'){
			y[6]+='6';
		}
		if(s[i]=='7'){
			y[7]+='7';
		}
		if(s[i]=='8'){
			y[8]+='8';
		}
		if(s[i]=='9'){
			y[9]+='9';
		}
	}
	cout<<y[9]<<y[8]<<y[7]<<y[6]<<y[5]<<y[4]<<y[3]<<y[2]<<y[1]<<y[0];
	return 0;
} 
