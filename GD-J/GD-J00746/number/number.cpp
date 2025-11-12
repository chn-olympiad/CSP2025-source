#include <bits/stdc++.h>
using namespace std;
string str;
int a[101];
void print(int t,int num)
{
	for(int i=1;i<=t;i++)
	{
		cout<<num;
	}
}
int main()
{
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]<='9' && str[i]>='0')
		{
			int tmp=str[i]-'0';
			a[tmp]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			print(a[i],i);
		}
	}
	return 0;
}
