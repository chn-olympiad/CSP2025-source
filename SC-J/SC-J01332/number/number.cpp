#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005];
	int n[15];
	cin>>a;
	
	for(int i=0;i<strlen(a);i++) 
	{
		if('0'<a[i]<'9')
		{
			n[int(a[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=n[i];j>=1;j--)
		{
			cout<<i;
		}
	}
	return 0;
 } 
