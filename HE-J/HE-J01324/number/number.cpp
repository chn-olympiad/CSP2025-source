#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x,r;
	int g,h;
	int s;
//	int a,b,c;
	cin>>s;
	if(s<=9||s>999) cout<<s<<endl;
	if(9<s<99){
		g=s%10;
		h=s/10;
		if(g>h) cout<<g<<h<<endl;
		else cout<<s;
	}
//	if(99<s<999){
//		a=s%10;
//		b=s%100;
//		c=s/100;
//		if(a>b>c) cout<<a<<b<<c<<endl;
//		if(a>c>b) cout<<a<<c<<b<<endl;
//		if(b>a>c) cout<<b<<a<<c<<endl;
//		if(b>c>a) cout<<b<<c<<a<<endl;
//		if(c>b>a) cout<<c<<b<<a<<endl;
//		if(c>a>b) cout<<c<<a<<b<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
