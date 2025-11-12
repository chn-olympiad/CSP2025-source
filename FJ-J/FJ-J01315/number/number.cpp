#include<bits/stdc++.h>
using namespace std;
string s,res;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++) if(s[i]=='9') res+="9";
	for(int i=0;i<len;i++) if(s[i]=='8') res+="8";
	for(int i=0;i<len;i++) if(s[i]=='7') res+="7";
	for(int i=0;i<len;i++) if(s[i]=='6') res+="6";
	for(int i=0;i<len;i++) if(s[i]=='5') res+="5";
	for(int i=0;i<len;i++) if(s[i]=='4') res+="4";
	for(int i=0;i<len;i++) if(s[i]=='3') res+="3";
	for(int i=0;i<len;i++) if(s[i]=='2') res+="2";
	for(int i=0;i<len;i++) if(s[i]=='1') res+="1";
	for(int i=0;i<len;i++) if(s[i]=='0') res+="0";
	cout<<res;
	return 0;
} 
