#include <bits/stdc++.h>
using namespace std;
string s;
long long s1,a,b,c,d,e,f,g,h,i,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s1=s.size();
	for(int x=0;x<s1;x++){
		if(s[x]=='0') a++;
		else if(s[x]=='1') b++;
		else if(s[x]=='2') c++;
		else if(s[x]=='3') d++;
		else if(s[x]=='4') e++;
		else if(s[x]=='5') f++;
		else if(s[x]=='6') g++;
		else if(s[x]=='7') h++;
		else if(s[x]=='8') i++;
		else if(s[x]=='9') j++;
	}
	for(int x=1;x<=j;x++) cout<<'9';
	for(int x=1;x<=i;x++) cout<<'8';
	for(int x=1;x<=h;x++) cout<<'7';
	for(int x=1;x<=g;x++) cout<<'6';
	for(int x=1;x<=f;x++) cout<<'5';
	for(int x=1;x<=e;x++) cout<<'4';
	for(int x=1;x<=d;x++) cout<<'3';
	for(int x=1;x<=c;x++) cout<<'2';
	for(int x=1;x<=b;x++) cout<<'1';
	for(int x=1;x<=a;x++) cout<<'0';
	return 0;
}
