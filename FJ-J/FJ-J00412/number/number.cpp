#include <bits/stdc++.h>
using namespace std;
int len(string s)
{
	int i;
	for(i=0;s[i];i++)
	{
		
	}
	return i;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int nn=len(a);
	int b[nn]={};
	int n=0;
	for(int i=0;i<nn;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[n++]=a[i]-'0';
		}
	}
	sort(b,b+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<b[i];
	}
}
