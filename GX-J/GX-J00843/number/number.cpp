#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w".stdout);
	char s[101];
	int c=1,a=0,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0,b0=0;
	for(int i=1;i<=c;i++)
	{
		cin>>s[i];
		if(s[i]>='a'&&s[i]<='z') 
		{
			a++;
			c++;
		}
		if(s[i]>='0'&&s[i]<='9') 
		{
			a++;
			c++;
		}
		if(s[i]>='A'&&s[i]<='Z') 
		{
			a++;
			c++;
		c--;
		if(c==0) break;
	}
	for(int i=1;i<=a;i++)
	{
		if(s[i]=='1') b1++;
		else if(s[i]=='2') b2++;
		else if(s[i]=='3') b3++;
		else if(s[i]=='4') b4++;
		else if(s[i]=='5') b5++;
		else if(s[i]=='6') b6++;
		else if(s[i]=='7') b7++;
		else if(s[i]=='8') b8++;
		else if(s[i]=='9') b9++;
		else if(s[i]=='0') b0++;
	}
	for(int i=1;i<=b9;i++)
	{
		cout<<'9';
	}
	for(int i=1;i<=b8;i++)
	{
		cout<<'9';
	}
	for(int i=1;i<=b7;i++)
	{
		cout<<'7';
	}
	for(int i=1;i<=b6;i++)
	{
		cout<<'6';
	}
	for(int i=1;i<=b5;i++)
	{
		cout<<'5';
	}
	for(int i=1;i<=b4;i++)
	{
		cout<<'4';
	}
	for(int i=1;i<=b3;i++)
	{
		cout<<'3';
	}
	for(int i=1;i<=b2;i++)
	{
		cout<<'2';
	}
	for(int i=1;i<=b1;i++)
	{
		cout<<'1';
	}
	for(int i=1;i<=b0;i++)
	{
		cout<<'0';
	}
	return 0;
}
