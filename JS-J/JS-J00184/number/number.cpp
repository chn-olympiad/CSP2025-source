#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string a;
int s[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;a[i];i++)
	{
		if(a[i]-'0'<=9 && a[i]-'0'>=0)
		s[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<s[i];j++)
		cout<<i;
	}
	return 0;
}

