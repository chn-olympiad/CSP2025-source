#include<iostream>
#include<string.h>
using namespace std;
int n;
int t[15];
string a;
string b="";
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.length();
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]>='0'&&a[i-1]<='9')
		t[a[i-1]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(t[i]--)
		{
			b+=(i+'0');
		}
	}
	if(b[0]!='0')
		cout<<b;
	else
		cout<<0;
}
