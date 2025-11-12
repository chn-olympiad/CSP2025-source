#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	char s,a[s],b,c,d,e,f,g;
	cin<<s;
	for(int i=1;i<=n;i++)
	{
		b=s%10;
		if(b>=1&&s%10<=9)
		{
			a[1]=b;
		}
		c=s%100;
		if(c>=1&&s%10<=9)
		{
			a[2]=c;
		}
		d=s%1000;
		if(d>=1&&s%10<=9)
		{
			a[3]=d;
		}
		e=s%10000;
		if(e>=1&&s%10<=9)
		{
			a[4]=e;
		}
		f=s%100000;
		if(f>=1&&s%10<=9)
		{
			a[5]=f;
		}
		g=s%1000000;
		if(g>=1&&s%10<=9)
		{
			a[6]=g;
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<a[6]
	return 0;
}
