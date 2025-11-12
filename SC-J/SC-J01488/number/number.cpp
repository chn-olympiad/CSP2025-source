#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string num0,num1,num2,num3,num4,num5,num6,num7,num8,num9;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')num0+='0';
		if(s[i]=='1')num1+='1';
		if(s[i]=='2')num2+='2';
		if(s[i]=='3')num3+='3';
		if(s[i]=='4')num4+='4';
		if(s[i]=='5')num5+='5';
		if(s[i]=='6')num6+='6';
		if(s[i]=='7')num7+='7';
		if(s[i]=='8')num8+='8';
		if(s[i]=='9')num9+='9';
	}
	cout<<num9<<num8<<num7<<num6<<num5<<num4<<num3<<num2<<num1<<num0;
	return 0;
} 