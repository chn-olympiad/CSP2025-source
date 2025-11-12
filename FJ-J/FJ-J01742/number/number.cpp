#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,k=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')a++;
		if(s[i]=='1')b++;
		if(s[i]=='2')c++;
		if(s[i]=='3')d++;
		if(s[i]=='4')e++;
		if(s[i]=='5')f++;
		if(s[i]=='6')g++;
		if(s[i]=='7')h++;
		if(s[i]=='8')j++;
		if(s[i]=='9')k++;
	}
	for(int i=1;i<=k;i++)cout<<9;
	for(int i=1;i<=j;i++)cout<<8;
	for(int i=1;i<=h;i++)cout<<7;
	for(int i=1;i<=g;i++)cout<<6;
	for(int i=1;i<=f;i++)cout<<5;
	for(int i=1;i<=e;i++)cout<<4;
	for(int i=1;i<=d;i++)cout<<3;
	for(int i=1;i<=c;i++)cout<<2;
	for(int i=1;i<=b;i++)cout<<1;
	for(int i=1;i<=a;i++)cout<<0;
	return 0;
} 
