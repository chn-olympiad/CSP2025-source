#include<bits/stdc++.h>
using namespace std;
char a[100010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,t=0,h=0,f=0,d=0,k=0,l=0,m=0,n=0,o=0,v=0;
	for(i=1;i<=100000;i++)
	{
		cin>>a[i];
		if(a[i]=='9') t++;
		if(a[i]=='8') h++;
		if(a[i]=='7') f++;
		if(a[i]=='6') d++;
		if(a[i]=='5') k++;
		if(a[i]=='4') l++;
		if(a[i]=='3') m++;
		if(a[i]=='2') n++;
		if(a[i]=='1') o++;
		if(a[i]=='0') v++;
	}
	for(i=1;i<=t;i++)
	{
		cout<<'9';
	}
	for(i=1;i<=h;i++)
	{
		cout<<'8';
	}
	for(i=1;i<=f;i++)
	{
		cout<<'7';
	}
	for(i=1;i<=d;i++)
	{
		cout<<'6';
	}
	for(i=1;i<=k;i++)
	{
		cout<<'5';
	}
	for(i=1;i<=l;i++)
	{
		cout<<'4';
	}
	for(i=1;i<=m;i++)
	{
		cout<<'3';
	}
	for(i=1;i<=n;i++)
	{
		cout<<'2';
	}
	for(i=1;i<=o;i++)
	{
		cout<<'1';
	}
	for(i=1;i<=v;i++)
	{
		cout<<'0';
	}
	return 0;
}
