#include<bits/stdc++.h>
using namespace std;
string a;
int l,s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.length();
	for(int i=0;i<l;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			s[int(a[i]-'1'+1)]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(s[i]--)
		{
			cout<<i;
		}
	}
	return 0;
 } 