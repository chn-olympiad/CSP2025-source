#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s;
	cin>>s;
	map<char,int> a;
	for(int i=0;i<s.size();i++)
	{
		a[s[i]]++;
	}
	char c='9';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<9;
			a[c]--;
		} 
		else break;
	}
	c='8';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<8;
			a[c]--;
		} 
		else break;
	}
	c='7';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<7;
			a[c]--;
		} 
		else break;
	}
	c='6';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<6;
			a[c]--;
		} 
		else break;
	}
	c='5';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<5;
			a[c]--;
		} 
		else break;
	}
	c='4';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<4;
			a[c]--;
		} 
		else break;
	}
	c='3';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<3;
			a[c]--;
		} 
		else break;
	}
	c='2';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<2;
			a[c]--;
		} 
		else break;
	}
	c='1';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<1;
			a[c]--;
		} 
		else break;
	}
	c='0';
	for(int i=1;;i++)
	{
		if(a[c]>0)
		{
			cout<<0;
			a[c]--;
		} 
		else break;
	}
	return 0;
}
