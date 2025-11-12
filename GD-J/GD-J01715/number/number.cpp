#include<bits/stdc++.h>
#define int long long
using namespace std;
string z="",x="",c="",v="",b="",n="",m="",q="",w="",e="";
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')e+='0';
		else if(s[i]=='1')z+='1';
		else if(s[i]=='2')x+='2';
		else if(s[i]=='3')c+='3';
		else if(s[i]=='4')v+='4';
		else if(s[i]=='5')b+='5';
		else if(s[i]=='6')n+='6';
		else if(s[i]=='7')m+='7';
		else if(s[i]=='8')q+='8';
		else if(s[i]=='9')w+='9';
	}
	cout<<w<<q<<m<<n<<b<<v<<c<<x<<z<<e;
	return 0;
} 
