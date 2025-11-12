#include<bits/stdc++.h>
using namespace std;
int b[10000005],z=0,s,xb=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string d;
	string a;
	cin>>a;
	for(int i=0;i<=10000005;i++)
	{
		if(a[i])z++;
		else	break;
	}
	for(int i=0;i<z;i++)
	{
		if(a[i]=='0')
		{
			b[0]++;
			s++;
		}
		if(a[i]=='1')
		{
			b[1]++;
			s++;
		}
		if(a[i]=='2')
		{
			b[2]++;
			s++;
		}
		if(a[i]=='3')
		{
			b[3]++;
			s++;
		}
		if(a[i]=='4')
		{
			b[4]++;
			s++;
		}
		if(a[i]=='5')
		{
			b[5]++;		
			s++;
		}
		if(a[i]=='6')
		{
			b[6]++;
			s++;
		}
		if(a[i]=='7')
		{
			b[7]++;
			s++;
		}
		if(a[i]=='8')
		{
			b[8]++;
			s++;
		}
		if(a[i]=='9')
		{
			b[9]++;
			s++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		xb=xb+b[i];
		for(int j=xb;j<b[i]+xb;j++)
		{
			if(i==9)d[j]='9';
			if(i==8)d[j]='8';
			if(i==7)d[j]='7';
			if(i==6)d[j]='6';
			if(i==5)d[j]='5';
			if(i==4)d[j]='4';
			if(i==3)d[j]='3';
			if(i==2)d[j]='2';
			if(i==1)d[j]='1';
			if(i==0)d[j]='0';
			cout<<d[j];
		}
	}
	return 0;
}
