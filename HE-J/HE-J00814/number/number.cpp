#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);                                   
    string s;
	cin>>s;
	long long len=s.size(),o=0;
	string k="",a="",b="",c="",d="",e="",f="",g="",h="",j="";
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]=='9')j+='9';
			else if(s[i]=='8')h+='8';
			else if(s[i]=='7')g+='7';
			else if(s[i]=='6')f+='6';
			else if(s[i]=='5')e+='5';
			else if(s[i]=='4')d+='4';
			else if(s[i]=='3')c+='3';
			else if(s[i]=='2')b+='2';
			else if(s[i]=='1')a+='1';
			else k+='0';
		}
	}
	cout<<j+h+g+f+e+d+c+b+a+k;
	return 0;
}
