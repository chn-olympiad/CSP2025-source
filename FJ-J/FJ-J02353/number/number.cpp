#include<bits/stdc++.h>
using namespace std;
int s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if (s%1==0){
	    a=s;
	}
	if (a<=10){
		cout<<a;
	}
	if (a<=10000){
		int c,b,d,e;
		c=s/1000;
		b=(s-c*1000)/100;
		d=(s-c*1000-b*100)/10;
		e=s-c*1000-b*100-d*100;
		cout<<c<<b<<d<<e;
	}

	return 0;
}
