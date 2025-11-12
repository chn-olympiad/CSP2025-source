#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
using namespace std;
string a;
int t[10]={};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		switch(a[i])
		{
			case '0':t[0]++;break;
			case '1':t[1]++;break;
			case '2':t[2]++;break;
			case '3':t[3]++;break;
			case '4':t[4]++;break;
			case '5':t[5]++;break;
			case '6':t[6]++;break;
			case '7':t[7]++;break;
			case '8':t[8]++;break;
			case '9':t[9]++;break;
			default:break;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<t[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
