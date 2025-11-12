#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long a=0,b=0,x=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,k=0;
	char s[1000010];
	scanf("%s",s);
	while(s[x]!='\0')
	{
		if(s[x]=='0') a++;
		if(s[x]=='1') b++;
		if(s[x]=='2') c++;
		if(s[x]=='3') d++;
		if(s[x]=='4') e++;
		if(s[x]=='5') f++;
		if(s[x]=='6') g++;
		if(s[x]=='7') h++;
		if(s[x]=='8') j++;
		if(s[x]=='9') k++;
		x++;
	}
	for(int i=0;i<k;i++)
	{
		cout<<9;
	}
	for(int i=0;i<j;i++)
	{
		cout<<8;
	}
	for(int i=0;i<h;i++)
	{
		cout<<7;
	}
	for(int i=0;i<g;i++)
	{
		cout<<6;
	}
	for(int i=0;i<f;i++)
	{
		cout<<5;
	}
	for(int i=0;i<e;i++)
	{
		cout<<4;
	}
	for(int i=0;i<d;i++)
	{
		cout<<3;
	}
	for(int i=0;i<c;i++)
	{
		cout<<2;
	}
	for(int i=0;i<b;i++)
	{
		cout<<1;
	}
	for(int i=0;i<a;i++)
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
