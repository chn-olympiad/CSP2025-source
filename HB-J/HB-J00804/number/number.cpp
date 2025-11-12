#include<bits/stdc++.h>
using namespace std;
int a;
int b,c,d,e;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	if(a<=9)cout<<a;
	if(a>=10&&a<=99){
		if(a%10 < a/10)cout<<a%10<<a/10;
		else cout<<a;
		}
	if(a>=100&&a<=999){
		b=a%10;
		c=a/10%10;
		d=a/100;
		if(b>c)swap(b,c);
		if(b>d)swap(b,d);
		if(c>d)swap(c,d);
		cout<<d<<c<<b;
		}
		if(a>=1000&&a<=9999){
		b=a%10;
		c=a/10%10;
		d=a/100%10;
		e=a/1000;
		if(b>c)swap(b,c);
		if(b>d)swap(b,d);
		if(b>e)swap(b,e);
		if(c>d)swap(c,d);
		if(c>e)swap(c,e);
		if(d>e)swap(d,e);
		cout<<e<<d<<c<<b;
		return 0;
		}
}
