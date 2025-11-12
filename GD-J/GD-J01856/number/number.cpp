#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e6+5;
string s;
int l;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	l=s.length();
	for(int i=0; i<l; ++i)
	{
		if(int(s[i])>=int('0') && int(s[i])<=int('9'))
			a[int(s[i])-int('0')]+=1;
	}
	
	for(int i=9; i>=0; --i)
	{
		for(int j=1; j<=a[i]; ++j)
			printf("%d",i);
	}
	return 0;
}
